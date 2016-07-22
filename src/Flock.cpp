#include "Flock.h"

Flock::Flock()
{

}


void Flock::setupSim()
{

  //kaguya::LuaFunction get =  m_luaTest.loadfile("script.lua");

  m_goals.clear();
  m_sim.reset(new RVO::RVOSimulator());
//  update();

  /* Specify the global time step of the simulation. */
  m_sim->setTimeStep(0.75f);
  /* Specify the default parameters for agents that are subsequently added. */
  // float neighborDist, size_t maxNeighbors, float timeHorizon, float timeHorizonObst, float radius, float maxSpeed
  m_sim->setAgentDefaults(15.0f, 15, 2.0f, 3.0f, 0.8f);

  if (m_terrainState == TerrainState::BASIC)
  {
    m_minNegative = 0;
    m_minPositive =  5;
    m_maxPositive =  10;
    m_maxNegative = 0;

    //Number of blocks will always be sqare of value entered.
    m_numberOfBlocks = 5;
    m_blocksOffset = -5 * m_numberOfBlocks;

    for (int i = 0; i < m_numberOfBlocks; ++i)
    {

      m_obstacles.push_back(RVO::Vector3(m_blocksOffset + (m_minNegative + (i-1) * 210.0f),
                                        0,
                                        m_blocksOffset + (m_maxNegative + (i-1) * 210.0f)));

    }
  }

  /* Add agents, specifying their start position, and store their goals on the opposite side of the environment. */
    for (float a = 0; a < M_PI; a += 0.1f)
    {
      const float z = 100.0f * std::cos(a);
      const float r = 100.0f * std::sin(a);

      for (size_t i = 0; i < r / 2.5f; ++i)
      {
        const float x = r * std::cos(i * 2.0f * M_PI / (r / 2.5f));
        const float y = r * std::sin(i * 2.0f * M_PI / (r / 2.5f));

        m_sim->addAgent(RVO::Vector3(x, y, z));
        m_goals.push_back(m_goalPosition);
      }
    }
}

void Flock::setPreferredVelocities()
{
  for (size_t i = 0; i < m_sim->getNumAgents(); ++i)
  {
    size_t immediateNeighborNumber = 0;
    size_t furthestNeighborNumber = 0;

    if(m_sim->getAgentNumAgentNeighbors(i) > 0)
    {
      immediateNeighborNumber = m_sim->getAgentAgentNeighbor(i,0);
      furthestNeighborNumber = m_sim->getAgentAgentNeighbor(i,m_sim->getAgentNumAgentNeighbors(i)-1);
    }

    // Other values

    RVO::Vector3 sumOfAgentPositions;
    RVO::Vector3 centerVector;
    sumOfAgentPositions.operator +=(m_sim->getAgentPosition(i));

    // center of the fish swarm
    if(m_sim->getNumAgents() > 0)
    {
      m_centerOfSchool = sumOfAgentPositions/i;
      centerVector = m_centerOfSchool - m_sim->getAgentPosition(i);
    }
    else
    {
      m_centerOfSchool = RVO::Vector3(0.0,0.0,0.0);
      centerVector = RVO::Vector3(0.0,0.0,0.0);
    }

    RVO::Vector3 goalVector = m_goalPosition - m_sim->getAgentPosition(i);

//    if(abs(centerVector) - 15 > abs(m_sim->getAgentPosition(i))
//       || abs(centerVector) + 15 < abs(m_sim->getAgentPosition(i)))
//    {
//      m_sim->setAgentPrefVelocity(i, m_sim->getAgentPosition(immediateNeighborNumber));
//    }
//    else
//    {
     m_sim->setAgentPrefVelocity(i, goalVector);
//    }
    m_lua->getAgentVelocityLua(i);
  }

}

bool Flock::reachedGoal()
{
//  /* Check if all agents have reached their goals. */
//    if (RVO::abs(m_vCenterOfSchool - m_vGoalPosition) < 140.0f)
//    {
      return false;
//    }
//    setupSim();
//    return true;
}


