#ifndef LUA_INTERPRETER_H
#define LUA_INTERPRETER_H

#include"lua.hpp"

#include <memory>
#include "RVO.h"


class LuaInterpreter
{

  public:

      //LuaInterpreter(int agentNum);
      LuaInterpreter() : m_velocity(),
                         m_position(),
                         m_center(),
                         m_goal(),
                         m_agent(),
                         m_predators(),
                         m_predatorAngle(),
                         m_cohesion(){}

      RVO::Vector3 m_velocity;
      RVO::Vector3 m_position;

      RVO::Vector3 m_center;
      RVO::Vector3 m_goal = RVO::Vector3(0.0f,0.0f,0.0f);

      int m_agent;

      std::vector <RVO::Vector3> m_predators;

      float m_predatorAngle;

      RVO::Vector3 m_cohesion;


      float m_agentSpeed;

      float m_numAgents;


      int getAgent() const;
      void setAgent(int val);

      float getPredatorAngle() const;
      void setPredatorAngle(float angle);

      void  setAgentMaxSpeed(int agentNum, float newSpeed);
      float retrieveAgentMaxSpeed(int agentNum);

      const RVO::Vector3& getPredatorPosition() const;
      void setPredatorPosition(const RVO::Vector3& Member);

      const RVO::Vector3& getVelocity() const;
      void setVelocity(const RVO::Vector3& Member);
      RVO::Vector3 retrieveAgentVelocity(int agentNum) const;

      const RVO::Vector3& getPosition() const;
      void setPosition(const RVO::Vector3& Member);
      RVO::Vector3 retrieveAgentPosition(int agentNum) const;

      const RVO::Vector3& getGoal() const;
      void setGoal(const RVO::Vector3& Member);
      RVO::Vector3 retrieveGoalPosition() const;

      const RVO::Vector3& getCenter() const;
      void setCenter(const RVO::Vector3& Member);

      RVO::Vector3 retrieveCohesion(int agentNum) const;
      const RVO::Vector3& getCohesion() const;
      void setCohesion(const RVO::Vector3& Member);

      RVO::Vector3 getAlignment(int agentNum) const;

//      RVO::Vector3 RetrieveCenterOfSwarm(int firstAgent, int lastAgent) const;
      RVO::Vector3 retrieveCenterOfSwarm() const;

      RVO::Vector3 retrieveGoalVector(int agentNum) const;

      RVO::Vector3 retrieveCenterVector(int agentNum) const;

      float retrieveAbsoluteValue (RVO::Vector3 input) const;

      float retrievePowerOf(float input, float power) const;

      //int retrieveNumAgents() const;

      void setSingleAgentVelocity(int agentNum, RVO::Vector3 targetVector);
      void setAllAgentVelocities(RVO::Vector3 target, RVO::Vector3 inputVelocity);
      void setNeighborAgentVelocity(int agentNum, RVO::Vector3 target);

      RVO::Vector3 addVectors(RVO::Vector3 firstVector, RVO::Vector3 secondVector);
      RVO::Vector3 subVectors(RVO::Vector3 firstVector, RVO::Vector3 secondVector);
      RVO::Vector3 multiplyVectors(RVO::Vector3 firstVector, float value);
      RVO::Vector3 divideVectors(RVO::Vector3 firstVector, float value);
      bool compareVectors(RVO::Vector3 firstVector, RVO::Vector3 secondVector);

      // Clean up functions below when necessary.

      //kaguya::State m_luaTest;
      lua_State* L = luaL_newstate();

      std::unique_ptr<RVO::RVOSimulator> m_sim;

      void setPredators(int predatorNum, RVO::Vector3 predator);

      const int* getAgentNum() const;

//  private:

//      int m_agentNum;
};


#endif // LUA_INTERPRETER_H

