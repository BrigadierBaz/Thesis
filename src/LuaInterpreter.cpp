#include "LuaInterpreter.h"

//typedef int (*lua_CFunction) (lua_State *L);


// Retrieve the active agent number
int LuaInterpreter::getAgent() const
{
  return m_agent;
}

void LuaInterpreter::setAgent(int val)
{
  m_agent = val;
}

float LuaInterpreter::getPredatorAngle() const
{
  return m_predatorAngle;
}

void LuaInterpreter::setPredatorAngle(float angle)
{
  m_predatorAngle = angle;
}


void LuaInterpreter::setAgentMaxSpeed(int agentNum, float newSpeed)
{
  m_sim->setAgentMaxSpeed(agentNum, newSpeed);
}

float LuaInterpreter::retrieveAgentMaxSpeed(int agentNum)
{
  float maxSpeed = m_sim->getAgentMaxSpeed(agentNum);
  return maxSpeed;
}


const RVO::Vector3& LuaInterpreter::getVelocity() const
{
  return m_velocity;
}

void LuaInterpreter::setVelocity(const RVO::Vector3& val)
{
  m_velocity = val;
}

RVO::Vector3 LuaInterpreter::retrieveAgentVelocity(int agentNum) const
{

    RVO::Vector3 agentVelocity = m_sim->getAgentVelocity(agentNum);

    return agentVelocity;

}

float LuaInterpreter::retrieveAbsoluteValue(RVO::Vector3 input) const
{
  return abs(input);
}

float LuaInterpreter::retrievePowerOf(float input, float power) const
{
  return pow(input, power);
}


const RVO::Vector3& LuaInterpreter::getPosition() const
{
  return m_position;
}

void LuaInterpreter::setPosition(const RVO::Vector3& val)
{
  m_position = val;
}

RVO::Vector3 LuaInterpreter::retrieveAgentPosition(int agentNum) const
{

    RVO::Vector3 agentPosition = m_sim->getAgentPosition(agentNum);

    return agentPosition;

}


const RVO::Vector3& LuaInterpreter::getGoal() const
{
  return m_goal;
}

void LuaInterpreter::setGoal(const RVO::Vector3& val)
{
  m_goal = val;
}

RVO::Vector3 LuaInterpreter::retrieveGoalPosition() const
{
  RVO::Vector3 goalPosition = m_goal;

  return goalPosition;
}


//const RVO::Vector3& LuaInterpreter::getPredatorPosition() const
//{
// return m_predator;
//}

//void LuaInterpreter::setPredatorPosition(const RVO::Vector3& val)
//{
//  m_predator=val;
//}



const RVO::Vector3& LuaInterpreter::getCenter() const
{
  return m_center;
}

void LuaInterpreter::setCenter(const RVO::Vector3& val)
{
  m_center = val;
}

//RVO::Vector3 LuaInterpreter::RetrieveCenterOfSwarm(int firstAgent, int lastAgent) const
//{

//  RVO::Vector3 firstAgentPosition = m_sim->getAgentPosition(firstAgent);
//  RVO::Vector3 lastAgentPosition = m_sim->getAgentPosition(lastAgent);

//  RVO::Vector3 sumOfAgentPositions = firstAgentPosition.operator +(lastAgentPosition);

//  RVO::Vector3 centerOfSchool = sumOfAgentPositions.operator /(2);

//  return centerOfSchool;

//}

RVO::Vector3 LuaInterpreter::retrieveCenterOfSwarm() const
{
  RVO::Vector3 sumOfAgentPositions;
  RVO::Vector3 centerOfSchool;

  for(size_t i=0; i<m_sim->getNumAgents(); i++)
  {
    sumOfAgentPositions.operator += (m_sim->getAgentPosition(i));
    centerOfSchool = sumOfAgentPositions.operator /(i);
  }

  return centerOfSchool;

}


RVO::Vector3  LuaInterpreter::retrieveGoalVector(int agentNum) const
{
  RVO::Vector3 goalVector = m_goal - m_sim->getAgentPosition(agentNum);

  return goalVector;
}

RVO::Vector3  LuaInterpreter::retrieveCenterVector(int agentNum) const
{
  RVO::Vector3 centerVector = m_center - m_sim->getAgentPosition(agentNum);

  return centerVector;
}


//int LuaInterpreter::retrieveNumAgents() const
//{
//  // Minus 1 as index starts from 0.
//  int numAgents = m_sim->getNumAgents() - 1;

//  return numAgents;
//}

RVO::Vector3 LuaInterpreter::retrieveCohesion(int agentNum) const
{

  RVO::Vector3 cohesion;

       if (m_sim->getAgentNumAgentNeighbors(agentNum) > 0)
         {
           size_t neighboringAgentNumber = 0;
           RVO::Vector3 neighborPosition (0,0,0);

             for(size_t j=0; j <m_sim->getAgentNumAgentNeighbors(agentNum); j++)
             {
             neighboringAgentNumber =  m_sim->getAgentAgentNeighbor(agentNum,j);
             neighborPosition.operator +=(m_sim->getAgentPosition(neighboringAgentNumber));
             }

           neighborPosition.operator /=(m_sim->getAgentNumAgentNeighbors(agentNum));

           RVO::Vector3 desired (neighborPosition-m_sim->getAgentPosition(agentNum));
           desired.operator *=(m_sim->getAgentMaxSpeed(agentNum));
           cohesion = desired;
         }

     return cohesion;
}

const RVO::Vector3& LuaInterpreter::getCohesion() const
{
  return m_cohesion;
}

RVO::Vector3 LuaInterpreter::getAlignment(int agentNum) const
{
  RVO::Vector3 alignment;

  if(m_sim->getNumAgents()!=0)
  {
    RVO::Vector3 sum (0.0f,0.0f,0.0f);
    //RVO::Vector2 vAverageAgentSpeed(0,0);
    size_t neighboringAgentNumber = 0;

    if (m_sim->getAgentNumAgentNeighbors(agentNum) > 0)
    {
      neighboringAgentNumber = m_sim->getAgentAgentNeighbor(agentNum,0);

      sum.operator +=(m_sim->getAgentVelocity(neighboringAgentNumber));
//            sum = RVO::normalize(sum);
      sum.operator *=(m_sim->getAgentMaxSpeed(neighboringAgentNumber));
    }

    if(abs(sum) > 0)
    {
      alignment = RVO::Vector3(sum + m_sim->getAgentVelocity(agentNum));
    }

  }

  return alignment;
}



void LuaInterpreter::setCohesion(const RVO::Vector3& val)
{
   m_cohesion = val;
}



//void LuaInterpreter::setSingleAgentVelocity(int agentNum, RVO::Vector3 target, RVO::Vector3 inputVelocity, RVO::Vector3 agentPosition)
void LuaInterpreter::setSingleAgentVelocity(int agentNum, RVO::Vector3 targetVector)
{
  //RVO::Vector3 targetVector = target - agentPosition;
  m_sim->setAgentPrefVelocity(agentNum, targetVector);
}

void LuaInterpreter::setNeighborAgentVelocity(int agentNum, RVO::Vector3 target)
{
  if(m_sim->getAgentNumAgentNeighbors(agentNum) > 0)
  {
    size_t iNeighboringAgentNumber =  m_sim->getAgentAgentNeighbor(agentNum,0);
    RVO::Vector3 targetVector = target - m_sim->getAgentPosition(agentNum);
    m_sim->setAgentPrefVelocity(iNeighboringAgentNumber, targetVector + m_sim->getAgentPrefVelocity(agentNum));
  }
}

void LuaInterpreter::setAllAgentVelocities(RVO::Vector3 target, RVO::Vector3 inputVelocity)
{
  for (size_t i = 0; i < m_sim->getNumAgents(); ++i)
  {
    RVO::Vector3 targetVector = target - m_sim->getAgentPosition(i);
    m_sim->setAgentPrefVelocity(i, targetVector + inputVelocity);
  }
}

// Vector functions
RVO::Vector3 LuaInterpreter::addVectors(RVO::Vector3 firstVector, RVO::Vector3 secondVector)
{
  return firstVector.operator +(secondVector);
}

RVO::Vector3 LuaInterpreter::subVectors(RVO::Vector3 firstVector, RVO::Vector3 secondVector)
{
  return firstVector.operator -(secondVector);
}

RVO::Vector3 LuaInterpreter::multiplyVectors(RVO::Vector3 firstVector, float value)
{
  return firstVector.operator *(value);
}

RVO::Vector3 LuaInterpreter::divideVectors(RVO::Vector3 firstVector, float value)
{
  return firstVector.operator /(value);
}

bool LuaInterpreter::compareVectors(RVO::Vector3 firstVector, RVO::Vector3 secondVector)
{
  return firstVector.operator !=(secondVector);
}


void LuaInterpreter::setPredators(int predatorNum, RVO::Vector3 predator)
{
  //m_predators.assign (10,100);
  //m_predators.at(predatorNum)= predator;
   m_predators.push_back(predator);
   //m_predators.at(predatorNum) = predator;
   //m_predators.assign(predatorNum, predator);

}
