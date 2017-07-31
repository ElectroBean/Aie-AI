#include "PathFind.h"



PathFind::PathFind(Agent* agent, std::vector<Vector3> path, float maxSpeed)
{
	this->wanderDistance = wanderDistance;
	this->wanderRadius = wanderRadius;
	this->jitterAmount = jitterAmount;
	this->maxSpeedConst = maxSpeed;
	previousTarget = agent->GlobalTransform;
	nodes = path;
	//this->target = target;
}

PathFind::~PathFind()
{
}

void PathFind::onEnter(Agent * agent)
{
}

void PathFind::onExit(Agent * agent)
{
}

void PathFind::update(float deltaTime, Agent * agent, StateManager * sm)
{
	maxSpeed = maxSpeedConst;
	if (!reachedPos)
	{
		Vector3 dir = nextPosition.position - agent->GlobalTransform.position;
		dir.normalise();

		float distance = Vector3::distance(agent->GlobalTransform.position, nextPosition.position);
		/*if (maxSpeed > distance)
		maxSpeed = distance;*/
		float dist = Vector3::distance(nextPosition.position, agent->GlobalTransform.position);
		//if (maxSpeed > dist)
			//maxSpeed = dist;

		dir = dir * maxSpeed;

		agent->velocity = dir;

		//agent->velocity = agent->velocity + dir * deltaTime;


		if (Vector3::distance(nextPosition.position, agent->GlobalTransform.position) < 10.0f)
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
		if (i < nodes.size())
		nextPosition.position = nodes[i];
		i++;
		std::cout << "position changed" << std::endl;
		reachedPos = false;

	}
}
