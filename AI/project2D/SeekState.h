#pragma once
#include "State.h"
#include "StateManager.h"
#include <Vector2.h>

class SeekState :
	public State
{
public:
	SeekState(Agent* target, float maxSpeed);
	~SeekState();

	void onEnter(Agent* agent);
	void onExit(Agent* agent);
	void update(float deltaTime, Agent* agent, StateManager* sm);

private:
	Agent* target;
	float maxSpeed;
};

//get distance 
// divide by maxdistance
// * by result

