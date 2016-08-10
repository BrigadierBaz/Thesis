maxAgent = interpreter:getNumAgents()

zero = {x=0.0,
		y=0.0,
		z=0.0}
    



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
    

for i=0, 200, 1
do
	agent = interpreter:getAgent(i)
	
	if agent > maxAgent
	then
		agent = 0
	end
	
	velocity = interpreter:getAgentVelocity(agent)
    position = interpreter:getAgentPosition(agent)
	
    center = interpreter:getCenterOfSwarm()
    interpreter:setCenter(center)
    centerVector = interpreter:subVectors(center, position)
    

    --centerVector = interpreter:getCenterVector(agent)		
	
	goal = interpreter:getGoal()
	goalVector = interpreter:subVectors(goal, position)
	

    if interpreter:getAgentNeighborCount(agent) > 0
    then
		neighbor = interpreter:getAgentNeighborNum(agent,0)
	end
    
    positionAbsolute = interpreter:getAbsoluteValue(position)
    goalAbsolute = interpreter:getAbsoluteValue(goal)
    
    cohesion = interpreter:getCohesion(agent)
    
    alignment = interpreter:getAlignment(agent)
    
    angle = math.rad(math.pi * 10)
    
    bait = baitBall(angle, position, goal, goalVector, agent)
    
    finalVelocity = interpreter:addVectors(zero, goalVector)
    
    finalVelocity = interpreter:addVectors(finalVelocity, cohesion)
    
    finalVelocity = interpreter:addVectors(finalVelocity, alignment)
    
    finalVelocity = interpreter:addVectors(finalVelocity, bait)
    
    interpreter:setSingleAgentVelocity(agent, finalVelocity)
    
        --if goalAbsolute 
    
    distance = 50.0
    
    randomX = math.random(0,150) - math.random(0,150)
    randomY = math.random(0,150) - math.random(0,150)
    randomZ = math.random(0,150) - math.random(0,150)
    
	if goalAbsolute - 10.0 < positionAbsolute and positionAbsolute < goalAbsolute + 10.0 and
	goal["x"] - distance < position["x"] and position["x"] < goal["x"] + distance and
   goal["z"] - distance < position["z"] and position["z"] < goal["z"] + distance and
   goal["y"] - distance < position["y"] and position["y"] < goal["y"] + distance
	 then
		goal.x = randomX
		goal.y = randomY
		goal.z = randomZ
		
		interpreter:setGoal(goal)
			 
	 end


    interpreter:setAgent(agent + 1)
	

end







