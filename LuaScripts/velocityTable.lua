--interpreter:GetAgent()

velocity = interpreter:RetrieveAgentVelocity(interpreter:GetAgent())

position = interpreter:RetrieveAgentPosition(interpreter:GetAgent())
interpreter:SetPosition(position)

goal = interpreter:RetrieveGoalPosition()

--goal["x"] = goal["x"] + 0.1

center = interpreter:RetrieveCenterOfSwarm()
interpreter:SetCenter(center)

goalVector = interpreter:RetrieveGoalVector(interpreter:GetAgent())

centerVector = interpreter:RetrieveCenterVector(interpreter:GetAgent())

absolute = interpreter:RetrieveAbsoluteValue(velocity)

power = interpreter:RetrievePowerOf(absolute,0.2)


-- Test operation

newVelocity = {x=(velocity["x"] + math.sin(interpreter:RetrieveAbsoluteValue(centerVector)) + 100),
               y=(0.0),
               z=(velocity["z"] + math.cos(interpreter:RetrieveAbsoluteValue(centerVector)) + 100)}

interpreter:SetVelocity(newVelocity)

interpreter:SetGoal(goal)

--interpreter:ReturnVelocity()
interpreter:PrintMe()

for k, v in pairs(goalVector) do
    print(k,v)
end

for k, v in pairs(centerVector) do
    print(k,v)
end

print(absolute)
print(math.cos(absolute))
print(power)

for k, v in pairs(newVelocity) do
    print(k,v)
end

