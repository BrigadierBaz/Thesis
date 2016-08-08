--agent = interpreter:getAgent();

--[[
]]--

maxAgent = interpreter:retrieveNumAgents()

zero = {x=20.0,
		y=20.0,
		z=20.0}

--if agent > maxAgent
--then
	--agent = 0;
--end

--print (maxAgent)

    newAngle = interpreter:getPredatorAngle()
    
    --print(newAngle)
    interpreter:setPredatorAngle(newAngle+1.0)
    
if newAngle == 360 then newAngle = 0
end

predatorAngle = math.rad(newAngle)


function baitBall(angle, position, center, centerVector, agent)
	newVelocity = {x=(math.cos(angle) * (position["x"] - center["x"]) - math.sin(angle) * (position["z"] - center["z"]) - center["x"])*math.random(),
			   y=(math.sin(centerVector["y"]) * (position["x"] - center["x"]) - math.sin(centerVector["y"]) * (position["z"] - center["z"]) - center["y"])*math.random(),
			   z=(math.sin(angle) * (position["x"] - center["x"]) - math.sin(angle) * (position["z"] - center["z"]) - center["z"])*math.random()}
	
	cohesion = interpreter:retrieveCohesion(agent)
	
	--for k,v in pairs(cohesion) do
		--print (k,v)
	--end
	
	cohesion = interpreter:multiplyVectors(cohesion, 3)
	
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
    
    otherPredator = {x= 100,
					y=0,
					z=90}
					
	goal = interpreter:getGoal()
    
    predatorArray = {zero, goal}
    

    --interpreter:setSingleAgentVelocity(agent, interpreter:subVectors(position, predator))
    
    positionAbsolute = interpreter:retrieveAbsoluteValue(position)
    centerAbsolute = interpreter:retrieveAbsoluteValue(center)
    
    
    angle = math.rad(math.pi * 45)
    
    --interpreter:setAgentMaxSpeed(agent, interpreter:retrieveAgentMaxSpeed(agent))
    
    predatorPoint = 0
    positionPoint = 0
    
    distance = 70;
    

	baitBall(angle, position, center, centerVector, agent)
	
	for k,v in pairs(predatorArray)
	do
	newPredator = predatorArray[k]
	predatorAbsolute = interpreter:retrieveAbsoluteValue(predator)
	--interpreter:setSingleAgentVelocity(agent, interpreter:subVectors(position, predator))
		if newPredator["x"] - distance < position["x"] and position["x"] < newPredator["x"] + distance and
		   newPredator["z"] - distance < position["z"] and position["z"] < newPredator["z"] + distance and
		   newPredator["y"] - distance < position["y"] and position["y"] < newPredator["y"] + distance
		 then
			
			--interpreter:setAgentMaxSpeed(agent, 0.9 + (predatorAbsolute + positionAbsolute)/100)
			newSpeed = interpreter:retrieveAgentMaxSpeed(agent) 
						+ (math.abs(predatorAbsolute - positionAbsolute)*0.004)

			
			if newSpeed > 2.0 then newSpeed = 2.0 end
			
			interpreter:setAgentMaxSpeed(agent, newSpeed)
			centerVector = interpreter:retrieveCenterVector(agent)
			
			cohesion = interpreter:getCohesion(agent)
			
			oldVelocity = interpreter:retrieveAgentVelocity(agent)
			
			--interpreter:setSingleAgentVelocity(agent, interpreter:addVectors(oldVelocity,interpreter:subVectors(position, predator)))
			
			split = interpreter:subVectors(position, interpreter:multiplyVectors(cohesion,2))
			
			interpreter:setSingleAgentVelocity(agent, interpreter:addVectors( interpreter:multiplyVectors(oldVelocity,4),
																			  interpreter:subVectors(split, newPredator)))
			--interpreter:setSingleAgentVelocity(agent,interpreter:subVectors(cohesion, predator))
			
			
		else baitBall(angle, position, center, centerVector, agent)
			newSpeed = interpreter:retrieveAgentMaxSpeed(agent) - 0.01
			if newSpeed < 0.4 then newSpeed = 0.4 end
			interpreter:setAgentMaxSpeed(agent, newSpeed)
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








