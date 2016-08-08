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
    interpreter:setPredatorAngle(newAngle+1.0)
    
    if newAngle == 360 then newAngle = 0
    end
    
    predatorAngle = math.rad(newAngle)
    



function baitBall(angle, position, center, centerVector, agent)
	newVelocity = {x=(math.cos(angle) * (position["x"] - center["x"]) - math.sin(angle) * (position["z"] - center["z"]) - center["x"])*math.random(),
			   y=(math.sin(centerVector["y"]) * (position["x"] - center["x"]) - math.sin(centerVector["y"]) * (position["z"] - center["z"]) - center["y"])*math.random(),
			   z=(math.sin(angle) * (position["x"] - center["x"]) - math.sin(angle) * (position["z"] - center["z"]) - center["z"])*math.random()}
	
	cohesion = interpreter:retrieveCohesion(agent)
	alignment = interpreter:getAlignment(agent)
	
	steer = interpreter:addVectors(cohesion,alignment)
	
	--for k,v in pairs(cohesion) do
		--print (k,v)
	--end
	
	interpreter:setSingleAgentVelocity(agent, interpreter:addVectors(centerVector, interpreter:addVectors(newVelocity,steer)))
	newSpeed = interpreter:retrieveAgentMaxSpeed(agent) - 0.1
	if newSpeed < 0.4 then newSpeed = 0.4 end
	interpreter:setAgentMaxSpeed(agent, newSpeed)
end





-- Predator Update
-- Purposefully defined outside the loop to prevent instructions from being called multiple times

numPredators = interpreter:getPredators()

-- If condition checks to see if the array is already populated
if numPredators == 0 then

 predator = {x= 40,
					y=0,
					z=30}
   
	predatorOrigin = {x= 40,
					y=0,
					z=30}
    
    predator["x"] = (center["x"] + math.cos(predatorAngle*2) * 60)
    predator["z"] = (center["z"] + math.sin(predatorAngle/1.5) * 60)
    predator["y"] = (center["y"] + math.cos(predatorAngle*3) * 60)
    
    otherPredator = {x= 10,
					y=0,
					z=10}
					
	predatorOrigin = {x= 20,
					y=20,
					z=50}
					
	otherPredator["x"] = (center["x"] + math.cos(predatorAngle/2.5) * 100)
    otherPredator["z"] = (center["z"] + math.sin(predatorAngle/6) * 40)
    otherPredator["y"] = (center["y"] + math.cos(predatorAngle*2) * 20)
    
    finalPredator = {x= 10,
					y=0,
					z=10}
					
	predatorOrigin = {x= 10,
					y=20,
					z=15}		
					
	finalPredator["x"] = (predatorOrigin["x"] + math.cos(predatorAngle*0.2) * 80)
    finalPredator["z"] = (predatorOrigin["z"] + math.sin(predatorAngle/3) * 70)
    finalPredator["y"] = (predatorOrigin["y"] + math.cos(predatorAngle*0.2) * 95)
    
    predatorArray = {predator}

for k,v in pairs(predatorArray)
do
	--print(k,v)
	interpreter:setPredators(k,v)
end
end


    


for i=0, 70, 1
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

   
					
	goal = interpreter:getGoal()
    
    --cohesion = interpreter:getCohesion(agent)
    --interpreter:setSingleAgentVelocity(agent, interpreter:subVectors(position, cohesion))
    
    positionAbsolute = interpreter:retrieveAbsoluteValue(position)
    predatorAbsolute = interpreter:retrieveAbsoluteValue(predator)
    centerAbsolute = interpreter:retrieveAbsoluteValue(center)
    
    predatorVectorAbs = interpreter:retrieveAbsoluteValue(interpreter:subVectors(position, predator))
    
    angle = math.rad(math.pi * 45)
    
    --interpreter:setAgentMaxSpeed(agent, interpreter:retrieveAgentMaxSpeed(agent))

    
    distance = 50
    
    oldPredator = {x=0,
					y=0,
					z=0}

	for k,v in pairs(predatorArray)
	do
	newPredator = predatorArray[k]
	predatorAbsolute = interpreter:retrieveAbsoluteValue(newPredator)
	
		if newPredator["x"] - distance < position["x"] and position["x"] < newPredator["x"] + distance and
		   newPredator["z"] - distance < position["z"] and position["z"] < newPredator["z"] + distance and
		   newPredator["y"] - distance < position["y"] and position["y"] < newPredator["y"] + distance
		 then
			
			--interpreter:setAgentMaxSpeed(agent, 0.9 + (predatorAbsolute + positionAbsolute)/100)
			newSpeed = interpreter:retrieveAgentMaxSpeed(agent) 
						+ (math.abs(predatorAbsolute - positionAbsolute)*0.01)

			
			if newSpeed > 2.0 then newSpeed = 2.0 end
			
			interpreter:setAgentMaxSpeed(agent, newSpeed)
			centerVector = interpreter:retrieveCenterVector(agent)
			
			cohesion = interpreter:getCohesion(agent)
			--alignment = interpreter:getAlignment(agent)
			
			--steer = interpreter:addVectors(cohesion,alignment)
			
			randomVec = {x=(math.random())/2,
						 y=(math.random())/2,
						 z=(math.random())/2}
						 
			steer = interpreter:addVectors(cohesion,randomVec)
			
			oldVelocity = interpreter:retrieveAgentVelocity(agent)
			oldVelocity = interpreter:subVectors(oldVelocity,oldPredator)
			
			newPredator = interpreter:divideVectors(newPredator,k)
			
			interpreter:setSingleAgentVelocity(agent, interpreter:addVectors(oldVelocity,interpreter:subVectors(cohesion, newPredator)))
			
			if newPredator["x"] - 28 < position["x"] and position["x"] < newPredator["x"] + 28 and
			   newPredator["z"] - 26 < position["z"] and position["z"] < newPredator["z"] + 24 and
			   newPredator["y"] - 28 < position["y"] and position["y"] < newPredator["y"] + 22
			 then
				interpreter:setSingleAgentVelocity(agent, interpreter:addVectors(oldVelocity,interpreter:subVectors(position, newPredator)))
					
			 end
			
			--interpreter:setSingleAgentVelocity(agent,interpreter:subVectors(cohesion, newPredator))
			
			--oldPredator = interpreter:addVectors(oldPredator, v)
			oldPredator = interpreter:divideVectors(interpreter:addVectors(oldPredator, v),k)
			
		else baitBall(angle, position, center, centerVector, agent)
		end
	end
    
    interpreter:setAgent(agent + 1)
    
    --print(predatorAbsolute)
    --print(positionAbsolute)

end









