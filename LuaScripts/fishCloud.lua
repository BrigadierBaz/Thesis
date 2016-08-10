--agent = interpreter:getAgent();

--[[
]]--

maxAgent = interpreter:getNumAgents()

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
	
	cohesion = interpreter:getCohesion(agent)
	alignment = interpreter:getAlignment(agent)
	
	steer = interpreter:addVectors(cohesion,alignment)
	
	final = interpreter:addVectors(centerVector, interpreter:addVectors(newVelocity,steer))

	return final
end
    
    

for i=0, 70, 1
do
	agent = interpreter:getAgent()
	
	if agent > maxAgent
	then
		agent = 0
	end
	
	velocity = interpreter:getAgentVelocity(agent)
    position = interpreter:getAgentPosition(agent)
	
	
    center = interpreter:getCenterOfSwarm()		  
    interpreter:setCenter(center)
    centerVector = interpreter:subVectors(center, position)
    
    goal = interpreter:getGoal()
	goalVector = interpreter:subVectors(goal, position)
	
	positionAbsolute = interpreter:getAbsoluteValue(position)
    centerAbsolute = interpreter:getAbsoluteValue(center)
    
    if interpreter:getAgentNeighborCount(agent) > 0
    then
		neighbor = interpreter:getAgentNeighborNum(agent,0)
	end
	
	neighborPosition = zero
	neighborVelocity = interpreter:getAgentVelocity(neighbor)
	
	neighborVector = interpreter:subVectors(neighborPosition, position)
	
	interpreter:setSingleAgentVelocity(agent, goalVector)
	
	if interpreter:getAgentNeighborCount(agent) > 3
    then
		for i=0, 3, 1
		do
			neighbor = interpreter:getAgentNeighborNum(agent,i)
			neighborPosition = interpreter:addVectors(neighborPosition, interpreter:getAgentPosition(neighbor))
		end
		
		neighborPosition = interpreter:divideVectors(neighborPosition, 3)
		neighborVector = interpreter:subVectors(neighborPosition, position)
		neighborAbsolute = interpreter:getAbsoluteValue(neighborVector)
		
		if neighborAbsolute < 10
		then
			neighborVector = interpreter:divideVectors(neighborVector,neighborAbsolute)
			interpreter:setSingleAgentVelocity(agent, neighborVector)
		end	

		
	end		

	

    predator = {x= 40,
					y=0,
					z=30}
   
	predatorOrigin = {x= 40,
					y=0,
					z=30}
    
    predator["x"] = (center["x"] + math.cos(predatorAngle*2) * 60)
    predator["z"] = (center["z"] + math.sin(predatorAngle/1.5) * 60)
    predator["y"] = (center["y"] + math.cos(predatorAngle*3) * 60)
    
    predatorAbsolute = interpreter:getAbsoluteValue(predator)
    predatorVectorAbs = interpreter:getAbsoluteValue(interpreter:subVectors(position, predator))
    angle = math.rad(math.pi * 45)  
    predatorArray = {}

    
    distance = 50
    
    oldPredator = {x=0,
					y=0,
					z=0}

	for k,v in pairs(predatorArray)
	do
	newPredator = predatorArray[k]
	predatorAbsolute = interpreter:getAbsoluteValue(newPredator)
	
	bait = baitBall(angle, position, neighborPosition, neighborVector, agent)
	finalVelocity = interpreter:addVectors(bait, centerVector)
	
	interpreter:setSingleAgentVelocity(agent, finalVelocity)
	interpreter:setAgentMaxSpeed(agent, 0.4)
	
		if newPredator["x"] - distance < position["x"] and position["x"] < newPredator["x"] + distance and
		   newPredator["z"] - distance < position["z"] and position["z"] < newPredator["z"] + distance and
		   newPredator["y"] - distance < position["y"] and position["y"] < newPredator["y"] + distance
		 then
			
			centerVector = interpreter:subVectors(center, position)
			
			cohesion = interpreter:getCohesion(agent)
			--alignment = interpreter:getAlignment(agent)
			
			--steer = interpreter:addVectors(cohesion,alignment)
			
			randomVec = {x=(math.random())/2,
						 y=(math.random())/2,
						 z=(math.random())/2}
						 
			steer = interpreter:addVectors(cohesion,randomVec)
			
			oldVelocity = interpreter:getAgentVelocity(agent)
			
			newPredator = interpreter:divideVectors(newPredator,k)
			
			interpreter:setSingleAgentVelocity(agent, interpreter:addVectors(neighborVector,neighborVelocity))
			
			
			--interpreter:setSingleAgentVelocity(agent,interpreter:subVectors(cohesion, newPredator))
			
			--oldPredator = interpreter:addVectors(oldPredator, v)
			oldPredator = interpreter:divideVectors(interpreter:addVectors(oldPredator, v),k)
			
		else 
			bait = baitBall(angle, position, center, centerVector, agent)
			finalVelocity = interpreter:addVectors(bait, centerVector)
			interpreter:setSingleAgentVelocity(agent, finalVelocity)
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
	interpreter:setPredators(v)
end
end
