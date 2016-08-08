--agent = interpreter:getAgent();

--[[
]]--

maxAgent = interpreter:retrieveNumAgents()

zero = {x=0.5,
		y=0.5,
		z=0.5}

--if agent > maxAgent
--then
	--agent = 0;
--end

--print (maxAgent)

for i=0, 30, 1
do
	agent = interpreter:getAgent()
	
	if agent > maxAgent
	then
		agent = 0
	end
	
	velocity = interpreter:retrieveAgentVelocity(agent)
    position = interpreter:retrieveAgentPosition(agent)
        
	
    center = interpreter:retrieveCenterOfSwarm()
    --interpreter:setCenter(center)
    
    --[[center = {x=oldCenter["x"]-0.001,
			  y=0.0,
			  z=oldCenter["z"]+0.001}]]
			  
    interpreter:setCenter(center)
    
    --getIt = interpreter:getCenter()
    
    centerVector = interpreter:retrieveCenterVector(agent)

    goal = interpreter:getPredatorPosition()

    angle = math.rad(math.pi * 45)

    --angle = interpreter:retrieveAbsoluteValue(centerVector)

    --newVelocity = {x=(math.cos(angle) * (position["x"] - center["x"]) - math.sin(angle) * (position["z"] - center["z"]) - center["x"])*math.random(),
                   --y=(math.sin(centerVector["y"]) * (position["x"] - center["x"]) - math.sin(centerVector["y"]) * (position["z"] - center["z"]) - center["y"])*math.random(),
                   --z=(math.sin(angle) * (position["x"] - center["x"]) - math.sin(angle) * (position["z"] - center["z"]) - center["z"])*math.random()}
    --y=(velocity["y"] + math.tan(interpreter:retrieveAbsoluteValue(centerVector) + 100)),

    --interpreter:setVelocity(newVelocity)

    --for k, v in pairs(newVelocity) do
        --print(k,v)
    --end

--    interpreter:setSingleAgentVelocity(agent, interpreter:addVectors(centerVector, newVelocity))
    --interpreter:setNeighborAgentVelocity(agent, center)
    
    interpreter:setSingleAgentVelocity(agent, interpreter:subVectors(position, goal))
    
    positionAbsolute = interpreter:retrieveAbsoluteValue(position)
    goalAbsolute = interpreter:retrieveAbsoluteValue(goal)
    centerAbsolute = interpreter:retrieveAbsoluteValue(center)
    
    goalVectorAbs = interpreter:retrieveAbsoluteValue(interpreter:subVectors(position, goal))
    
    --interpreter:setAgentMaxSpeed(agent, interpreter:retrieveAgentMaxSpeed(agent))
    
	function baitBall(angle, position, center, centerVector)
	    newVelocity = {x=(math.cos(angle) * (position["x"] - center["x"]) - math.sin(angle) * (position["z"] - center["z"]) - center["x"])*math.random(),
                   y=(math.sin(centerVector["y"]) * (position["x"] - center["x"]) - math.sin(centerVector["y"]) * (position["z"] - center["z"]) - center["y"])*math.random(),
                   z=(math.sin(angle) * (position["x"] - center["x"]) - math.sin(angle) * (position["z"] - center["z"]) - center["z"])*math.random()}
        
        interpreter:setSingleAgentVelocity(agent, interpreter:addVectors(centerVector, newVelocity))
        newSpeed = interpreter:retrieveAgentMaxSpeed(agent) - 0.1
        if newSpeed < 0.6 then newSpeed = 0.6 end
        interpreter:setAgentMaxSpeed(agent, newSpeed)
	end
    
    goalPoint = 0
    positionPoint = 0
    
    distance = math.random(40,70)
    

		if goal["x"] - distance < position["x"] and position["x"] < goal["x"] + distance and
		   goal["z"] - distance < position["z"] and position["z"] < goal["z"] + distance and
		   goal["y"] - distance < position["y"] and position["y"] < goal["y"] + distance
		 then
			
			--interpreter:setAgentMaxSpeed(agent, 0.9 + (goalAbsolute + positionAbsolute)/100)
			newSpeed = interpreter:retrieveAgentMaxSpeed(agent) 
						+ (math.abs(goalAbsolute - positionAbsolute)*0.007)

			
			if newSpeed > 1.5 then newSpeed = 1.5 end
			
			interpreter:setAgentMaxSpeed(agent, newSpeed)
			centerVector = interpreter:retrieveCenterVector(agent)
			
		else baitBall(angle, position, center, centerVector)
		end
    
    interpreter:setAgent(agent + 1)
    
    print(goalAbsolute)
    print(positionAbsolute)

end
