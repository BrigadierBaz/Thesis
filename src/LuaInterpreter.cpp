#include "LuaInterpreter.h"


/* Retrieve Agent information */
RVO::Vector3 LuaInterpreter::getAgentVelocity(int agentNum) const
{
    RVO::Vector3 agentVelocity = m_sim->getAgentVelocity(agentNum);
    return agentVelocity;
}

RVO::Vector3 LuaInterpreter::getAgentPosition(int agentNum) const
{
    RVO::Vector3 agentPosition = m_sim->getAgentPosition(agentNum);
    return agentPosition;
}



/* Get data on agent Neighbor */
int LuaInterpreter::getAgentNeighborNum(int agentNum, int neighborCount) const
{
  return m_sim->getAgentAgentNeighbor(agentNum,neighborCount);
}

int LuaInterpreter::getAgentNeighborCount(int agentNum) const
{
  return m_sim->getAgentNumAgentNeighbors(agentNum);
}




/* Add vector into predator array to be drawn to the screen */
void LuaInterpreter::setPredators(RVO::Vector3 predator)
{
   m_predators.push_back(predator);
}



/* Angle iterates with each execution of the script */
float LuaInterpreter::getPredatorAngle() const
{
  return m_predatorAngle;
}

void LuaInterpreter::setPredatorAngle(float angle)
{
  m_predatorAngle = angle;
}



/* Get/Set the overall speed of a given agent */
float LuaInterpreter::getAgentMaxSpeed(int agentNum)
{
  float maxSpeed = m_sim->getAgentMaxSpeed(agentNum);
  return maxSpeed;
}

void LuaInterpreter::setAgentMaxSpeed(int agentNum, float newSpeed)
{
  m_sim->setAgentMaxSpeed(agentNum, newSpeed);
}







/* Operations unavailable in Lua */
float LuaInterpreter::getAbsoluteValue(RVO::Vector3 input) const
{
  return abs(input);
}

float LuaInterpreter::getPowerOf(float input, float power) const
{
  return pow(input, power);
}







/* Get/set position of goal from sim*/
const RVO::Vector3& LuaInterpreter::getGoal() const
{
  return m_goal;
}

void LuaInterpreter::setGoal(const RVO::Vector3& val)
{
  m_goal = val;
}





/* Store center for use with Cpp functions */
const RVO::Vector3& LuaInterpreter::getCenter() const
{
  return m_center;
}

void LuaInterpreter::setCenter(const RVO::Vector3& val)
{
  m_center = val;
}





/* Get center for target */
RVO::Vector3 LuaInterpreter::getCenterOfSwarm() const
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





/// @brief Agents will attempt to remain in a cluster with immediate neighbors.
/// Modified from :-
/// Daniel Shiffman (Jun 6 2013). Flocking [online].
/// [Accessed 2016]. Available from: <https://processing.org/examples/flocking.html>.
RVO::Vector3 LuaInterpreter::getCohesion(int agentNum) const
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


/// @brief Agents attempt to maintain parrallel movement.
/// Modified from :-
/// Daniel Shiffman (Jun 6 2013). Flocking [online].
/// [Accessed 2016]. Available from: <https://processing.org/examples/flocking.html>.
RVO::Vector3 LuaInterpreter::getAlignment(int agentNum) const
{
  RVO::Vector3 alignment;

  if(m_sim->getNumAgents()!=0)
  {
    RVO::Vector3 sum (0.0f,0.0f,0.0f);
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







/* Set velocities of given agents */
void LuaInterpreter::setSingleAgentVelocity(int agentNum, RVO::Vector3 targetVector)
{
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





/* Vector Operations */
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
