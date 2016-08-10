-- Bait ball simulation --

-- Brief: This file is intended for use with Luke Bazalgette Thesis 2016
-- Agents are repelled away from predators
-- Simulates the effects of real world bait balling in schools of fish.

-- Gobal variables

-- Total number of agents for loop condition
maxAgent = interpreter:getNumAgents()

-- Vector3 format
zero = {x=0.0,
		y=0.0,
		z=0.0}

-- Retrieve current point of predator movement cycle
newAngle = interpreter:getPredatorAngle()

-- Interate on angle for staggered animation
interpreter:setPredatorAngle(newAngle+1.0)

-- ensure angle doesn't exceed 360.
if newAngle == 360 then newAngle = 0
end

-- convert angle into radians
predatorAngle = math.rad(newAngle)
    


-- bait ball returns velocity required to circle point in a sphere formation
function baitBall(angle, position, center, centerVector, agent)
	
	newVelocity = {x=(math.cos(angle) * (position["x"] - center["x"]) - math.sin(angle) * (position["z"] - center["z"]) - center["x"])*math.random(),
			   y=(math.sin(centerVector["y"]) * (position["x"] - center["x"]) - math.sin(centerVector["y"]) * (position["z"] - center["z"]) - center["y"])*math.random(),
			   z=(math.sin(angle) * (position["x"] - center["x"]) - math.sin(angle) * (position["z"] - center["z"]) - center["z"])*math.random()}
	
	cohesion = interpreter:getCohesion(agent)
	alignment = interpreter:getAlignment(agent)
	
	steer = interpreter:addVectors(cohesion,alignment)
		
	newSpeed = interpreter:getAgentMaxSpeed(agent) - 0.05
	if newSpeed < 0.4 then newSpeed = 0.4 end
	interpreter:setAgentMaxSpeed(agent, newSpeed)
	
	final = interpreter:addVectors(centerVector, interpreter:addVectors(newVelocity,steer))

	return final
end
    

-- Change second value to increase Velocity sample rate
for i=0, 70, 1
do
	-- Get the current agent
	agent = interpreter:getAgent()
	
	-- If agent count exceeds maximum number of active agents a segfalt occurs.
	-- Reset to zero to prevent this.
	if agent > maxAgent
	then
		agent = 0
	end
	
	-- Get Vector data for current agent
	velocity = interpreter:getAgentVelocity(agent)
    position = interpreter:getAgentPosition(agent)
	
	-- Get the middle of the agent swarm
    center = interpreter:getCenterOfSwarm()
    
    -- Get position of goal in simulation
    goal = interpreter:getGoal()

	-- return the value to Cpp for use in functions		  
    interpreter:setCenter(center)
    
    -- Get the distance from agent to center of swarm
    centerVector = interpreter:subVectors(center, position)

	-- Initial position of predator
    predator = {x= 40,y=0,z=30}
   
	-- Point predator orientates around
	predatorOrigin = {x= 40,y=0,z=30}
    
    -- Move in an irregular pattern
    predator["x"] = (center["x"] + math.cos(predatorAngle*2) * 60)
    predator["z"] = (center["z"] + math.sin(predatorAngle/1.5) * 60)
    predator["y"] = (center["y"] + math.cos(predatorAngle*3) * 60)
    
    
    otherPredator = {x= 10,y=0,z=10}
					
	predatorOrigin = {x= 20,y=20,z=50}
					
	otherPredator["x"] = (center["x"] + math.cos(predatorAngle/2.5) * 100)
    otherPredator["z"] = (center["z"] + math.sin(predatorAngle/6) * 40)
    otherPredator["y"] = (center["y"] + math.cos(predatorAngle*2) * 20)
    
    finalPredator = {x= 10,y=0,z=10}
					
	predatorOrigin = {x= 10,y=20,z=15}		
					
	finalPredator["x"] = (predatorOrigin["x"] + math.cos(predatorAngle*0.2) * 80)
    finalPredator["z"] = (predatorOrigin["z"] + math.sin(predatorAngle/3) * 70)
    finalPredator["y"] = (predatorOrigin["y"] + math.cos(predatorAngle*0.2) * 95)

    -- You can set any given Vector as a predator
    predatorArray = { goal, otherPredator, finalPredator}
    
	-- Get absolute values of Vectors
    positionAbsolute = interpreter:getAbsoluteValue(position)
    predatorAbsolute = interpreter:getAbsoluteValue(predator)
    centerAbsolute = interpreter:getAbsoluteValue(center)
    
    -- Absolute of predatpor vector
    predatorVectorAbs = interpreter:getAbsoluteValue(interpreter:subVectors(position, predator))
    
    -- Angle of velocity adjustment agents undergo
    angle = math.rad(math.pi * 45)
    
	-- Distance agents detect predators
    distance = 50
    
    -- Previous predator to be detected
    -- required in order for agents to respond to multiple predaotrs.
    oldPredator = {x=0,y=0,
	z=0}
	
	-- Number of predators in the range of the bait ball				
	predatorsInRange = 0
	
	-- Set agent to bait ball before searching for predators.
	-- This will maintain bait ball shape.
	interpreter:setSingleAgentVelocity(agent, baitBall(angle, position, center, centerVector, agent))

	-- Loop through list of predators and adjust velocity of each agents
	for k,v in pairs(predatorArray)
	do
	-- Get current predator and absolute position
	newPredator = predatorArray[k]
	predatorAbsolute = interpreter:getAbsoluteValue(newPredator)
		
		-- Check if predator is in range of the bait ball
		if newPredator["x"] - distance < position["x"] and position["x"] < newPredator["x"] + distance and
		   newPredator["z"] - distance < position["z"] and position["z"] < newPredator["z"] + distance and
		   newPredator["y"] - distance < position["y"] and position["y"] < newPredator["y"] + distance
		 then
		 
			-- Add to value if a predator is within range. Used to scale magnitude.
			predatorsInRange = predatorsInRange + 1
			
			-- Increase speed as predator approaches bait ball
			newSpeed = interpreter:getAgentMaxSpeed(agent) 
						+ (math.abs(predatorAbsolute - positionAbsolute)*0.015)

			-- Cap speed at 2.0
			if newSpeed > 2.0 then newSpeed = 2.0 end
			interpreter:setAgentMaxSpeed(agent, newSpeed)
			
			-- Update center vector
			centerVector = interpreter:subVectors(center, position)
			
			-- Get velocity to achieve cohesion between Agents
			cohesion = interpreter:getCohesion(agent)

			-- Update the velocity of the agent
			oldVelocity = interpreter:getAgentVelocity(agent)
			
			-- Check that there is a recorded value in OldPredator
			if oldPredator.x ~= 0
			then
				oldVelocity = interpreter:subVectors(position,oldPredator)
			end
			
			-- Scale vector according to how many predators are in range
			newPredator = interpreter:divideVectors(newPredator,predatorsInRange)
			
			-- Agent moves away from predator
			interpreter:setSingleAgentVelocity(agent, interpreter:addVectors(oldVelocity,interpreter:subVectors(cohesion, newPredator)))
			
			-- Split away from center if predaotr comes too close to the center
			if newPredator["x"] - 28 < position["x"] and position["x"] < newPredator["x"] + 28 and
			   newPredator["z"] - 26 < position["z"] and position["z"] < newPredator["z"] + 24 and
			   newPredator["y"] - 28 < position["y"] and position["y"] < newPredator["y"] + 22
			 then
			 
				interpreter:setSingleAgentVelocity(agent, interpreter:addVectors(oldVelocity,interpreter:subVectors(position, newPredator)))
				interpreter:setAgentMaxSpeed(agent, 3.0)
					
			 end

			-- Set position of current vector to be used in next looop if needed
			oldPredator = interpreter:addVectors(oldPredator, v)
			oldPredator = interpreter:divideVectors(interpreter:addVectors(oldPredator, v),predatorsInRange)

		end
	end
    
    -- Iterate agent count and return to Cpp
    interpreter:setAgent(agent + 1)

end

numPredators = interpreter:getPredators()

-- Pass positions of predators back into program
if numPredators == 0 then
for k,v in pairs(predatorArray)
do
	interpreter:setPredators(v)
end
end








