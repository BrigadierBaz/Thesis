#include "Flock.h"
#include "LuaFunctions.hpp"

Flock::Flock()
{

}

std::unique_ptr <LuaInterpreter> Flock::m_lua;


void Flock::setupSim()
{

  m_lua.reset(new LuaInterpreter);
  //kaguya::LuaFunction get =  m_luaTest.loadfile("script.lua");

  m_goals.clear();
  m_lua->m_predators.clear();
  m_lua->m_sim.reset(new RVO::RVOSimulator());
//  update();

  //m_lua->m_predator =  RVO::Vector3(30.0f,0.0f,30.0f);

  /* Specify the global time step of the simulation. */
  m_lua->m_sim->setTimeStep(0.75f);
  /* Specify the default parameters for agents that are subsequently added. */
  // float neighborDist, size_t maxNeighbors, float timeHorizon, float radius, float maxSpeed
  m_lua->m_sim->setAgentDefaults(m_neighborDist,
                                 m_numOfNeighbors,
                                 2.0f,
                                 m_agentRadius,
                                 0.8f);

  /* Add agents, specifying their start position, and store their goals on the opposite side of the environment. */
    for (float a = 0; a < M_PI; a += 0.1f)
    {
      const float z = 100.0f * std::cos(a);
      const float r = 100.0f * std::sin(a);

      for (size_t i = 0; i < r / 2.5f; ++i)
      {
        const float x = r * std::cos(i * 2.0f * M_PI / (r / 2.5f));
        const float y = r * std::sin(i * 2.0f * M_PI / (r / 2.5f));

        m_lua->m_sim->addAgent(RVO::Vector3(x, y, z));
      }
    }

    m_goals.push_back(m_lua->m_goal);

    m_lua->setAllAgentVelocities(m_lua->m_center, RVO::Vector3(0.0,0.0,0.0));
}


void Flock::setPreferredVelocities()
{
  /* initialize Lua */
  m_lua->L = lua_open();

  /* load Lua base libraries */
  luaL_openlibs(m_lua->L);

    luaopen_LuaInterpreter(m_lua->L);
    luaW_push(m_lua->L, m_lua.get());

    lua_setglobal(m_lua->L, "interpreter");

    // If the string isn't empty, load the file from the string
    if (!m_luaSimScript.empty())
    {
      const char * file = m_luaSimScript.c_str();
      luaL_dofile(m_lua->L, file);
    }

    /* load the script */
    else{ luaL_dofile(m_lua->L, "LuaScripts/baitBallFinal.lua");}


  lua_close(m_lua->L);

}


