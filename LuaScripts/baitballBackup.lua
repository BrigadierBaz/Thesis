interpreter:SetAgent(3)

velocity = interpreter:RetrieveAgentVelocity(9)
goal = interpreter:RetrieveGoalPosition()

agent = 5

interpreter:SetSingleAgentVelocity(agent, goal, velocity)
--agent = interpreter:GetAgent()
maxAgent = interpreter:RetrieveNumAgents()
--velocity = interpreter:RetrieveAgentVelocity(9)

print (maxAgent)

for k, v in pairs(velocity) do
    print(k,v)
end
--position = interpreter:RetrieveAgentPosition(i)
