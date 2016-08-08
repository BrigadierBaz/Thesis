--agent = interpreter:getAgent();

--[[
]]--

maxAgent = interpreter:retrieveNumAgents()

zero = {x=0.0,
		y=0.0,
		z=0.0}

--if agent > maxAgent
--then
	--agent = 0;
--end

--print (maxAgent)

    newAngle = interpreter:getPredatorAngle()
    
    --print(newAngle)
    interpreter:setPredatorAngle(newAngle+0.5)
    
    if newAngle == 360 then newAngle = 0
    end
    
    predatorAngle = math.rad(newAngle)
    
        
function baitBall(angle, position, center, centerVector)
	newVelocity = {x=(math.cos(angle) * (position["x"] - center["x"]) - math.sin(angle) * (position["z"] - center["z"]) - center["x"])*math.random(),
			   y=(math.sin(centerVector["y"]) * (position["x"] - center["x"]) - math.sin(centerVector["y"]) * (position["z"] - center["z"]) - center["y"])*math.random(),
			   z=(math.sin(angle) * (position["x"] - center["x"]) - math.sin(angle) * (position["z"] - center["z"]) - center["z"])*math.random()}
	
	cohesion = interpreter:retrieveCohesion(agent)
	
	--for k,v in pairs(cohesion) do
		--print (k,v)
	--end
	
	interpreter:setSingleAgentVelocity(agent, interpreter:addVectors(centerVector, interpreter:addVectors(newVelocity,cohesion)))
end

for i=0, 100, 1
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

    predator = {x= 40,
					y=0,
					z=30}

    --predator["x"] = zero["x"] + math.cos(angle)*0.01
    --predator["z"] = zero["z"] + math.sin(angle)*0.01
    
    --print(interpreter:getPredatorAngle())
   
	predatorOrigin = {x= 40,
					y=0,
					z=30}
    
    predator["x"] = (predatorOrigin["x"] + math.cos(predatorAngle*2) * 80)
    predator["z"] = (predatorOrigin["z"] + math.sin(predatorAngle/1.5) * 80)
    predator["y"] = (predatorOrigin["y"] + math.cos(predatorAngle*3) * 80)
    
    otherPredator = {x= 60,
					y=0,
					z=20}
					
	goal = interpreter:getGoal()
    
    predatorArray = {otherPredator,goal,predator}
    
    --predator["x"] = predator["x"] + (math.cos(angle) * (predator["x"] - zero["x"]) - math.sin(angle) * (predator["z"] - zero["z"]) - zero["x"])*0.5
    --predator["z"] = predator["z"] + (math.sin(angle) * (predator["x"] - zero["x"]) - math.sin(angle) * (predator["z"] - zero["z"]) - zero["z"])*0.5
    --interpreter:setPredatorPosition(predator)

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
    
    cohesion = interpreter:retrieveCohesion(agent)
    --interpreter:setSingleAgentVelocity(agent, interpreter:subVectors(position, predator))
    interpreter:setSingleAgentVelocity(agent, interpreter:addVectors(position, cohesion))
    
    positionAbsolute = interpreter:retrieveAbsoluteValue(position)
    centerAbsolute = interpreter:retrieveAbsoluteValue(center)
    
    predatorVectorAbs = interpreter:retrieveAbsoluteValue(interpreter:subVectors(position, predator))
    
    angle = math.rad(math.pi * 45)
    
    --interpreter:setAgentMaxSpeed(agent, interpreter:retrieveAgentMaxSpeed(agent))
    
    --predatorPoint = 0
    --positionPoint = 0
    
    newSpeed = interpreter:retrieveAgentMaxSpeed(agent) - 0.05
	if newSpeed < 0.4 then newSpeed = 0.4 end
	interpreter:setAgentMaxSpeed(agent, newSpeed)
    
    distance = math.random(60,90)
    
    

	for k,v in pairs(predatorArray)
	do
	print(k)
	predator = predatorArray[k]
	predatorAbsolute = interpreter:retrieveAbsoluteValue(predator)
	cohesion = interpreter:getCohesion(agent)
	interpreter:setSingleAgentVelocity(agent, interpreter:addVectors(center, cohesion))
	--baitBall(angle, position, center, centerVector)
		if predator["x"] - distance < position["x"] and position["x"] < predator["x"] + distance and
		   predator["z"] - distance < position["z"] and position["z"] < predator["z"] + distance and
		   predator["y"] - distance < position["y"] and position["y"] < predator["y"] + distance
		 then
			
			--interpreter:setAgentMaxSpeed(agent, 0.9 + (predatorAbsolute + positionAbsolute)/100)
			newSpeed = interpreter:retrieveAgentMaxSpeed(agent) 
						+ (math.abs(predatorAbsolute - positionAbsolute)*0.004)

			
			if newSpeed > 2.5 then newSpeed = 2.5 end
			
			interpreter:setAgentMaxSpeed(agent, newSpeed)
			centerVector = interpreter:retrieveCenterVector(agent)
			
			oldVelocity = interpreter:retrieveAgentVelocity(agent)
			
			split = interpreter:addVectors(position, interpreter:divideVectors(cohesion,2))
			
			interpreter:setSingleAgentVelocity(agent, interpreter:addVectors(oldVelocity,
																			 interpreter:subVectors(split, predator)))
			
			
		else baitBall(angle, position, center, centerVector)
		end
	end
    
    interpreter:setAgent(agent + 1)
    
    --print(predatorAbsolute)
    --print(positionAbsolute)

end

numPredators = interpreter:getPredators()

if numPredators == 0 then
for k,v in pairs(predatorArray)
do
	--print(k,v)
	interpreter:setPredators(k,v)
end
end
