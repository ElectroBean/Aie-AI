#include "WanderState.h"



WanderState::WanderState(Agent* agent, float wanderRadius, float wanderDistance, float jitterAmount, float maxSpeed, Agent * target)
{
	this->wanderDistance = wanderDistance;
	this->wanderRadius = wanderRadius;
	this->jitterAmount = jitterAmount;
	this->maxSpeed = maxSpeed;
	previousTarget = agent->GlobalTransform;
	this->target = target;
}


WanderState::~WanderState()
{
}

void WanderState::onEnter(Agent * agent)
{

}

void WanderState::onExit(Agent * agent)
{

}

void WanderState::update(float deltaTime, Agent * agent, StateManager * sm)
{
	if (!reachedPos)
	{
		Vector3 dir = nextPosition.position - agent->GlobalTransform.position;
		dir.normalise();

		float distance = Vector3::distance(agent->GlobalTransform.position, nextPosition.position);
		/*if (maxSpeed > distance)
			maxSpeed = distance;*/

		dir = dir * maxSpeed;

		agent->velocity = agent->velocity + dir * deltaTime;


		if (Vector3::distance(nextPosition.position, agent->GlobalTransform.position) < 1.0f)
		{
			reachedPos = true;
			std::cout << "distance reached" << std::endl;
		}
		else
		{
			reachedPos = false;
		}
	}

	//we're at the destination
	else
	{
		wanderCircle.position = Vector3(agent->GlobalTransform.position + (agent->GlobalTransform.position * wanderDistance));

		int xRand = rand() % (50 - -50 + 1) + -50;
		int yRand = rand() % (50 - -50 + 1) + -50;

		randCircumPoint = Vector3(float(xRand), float(yRand), 0);

		randCircumPoint.normalise();
		Vector3 wanderPos = wanderCircle.position + randCircumPoint * wanderRadius;

		nextPosition.position = wanderPos;
		std::cout << "position changed" << std::endl;
		reachedPos = false;

	}

	if (Vector3::distance(agent->GlobalTransform.position, target->GlobalTransform.position) < 50)
	{
		if (agent->getHealth() >= 25.0f)
		{
			sm->changeState(agent, new SeekState(target, maxSpeed));
			std::cout << "seeking" << std::endl;
			//now seeking

		}
		else if (agent->getHealth() < 25.0f)
		{
			sm->changeState(agent, new FleeState(target, maxSpeed));
			std::cout << "fleeing" << std::endl;
			//now fleeing

		}
	}
}
