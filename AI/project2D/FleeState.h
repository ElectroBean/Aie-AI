#pragma once
#include "State.h"
#include "StateManager.h"
#include <Vector2.h>


class FleeState :
	public State
{
public:
	FleeState(Matrix3* target, float maxSpeed);
	~FleeState();

	void onEnter(Agent* agent);
	void onExit(Agent* agent);
	void update(float deltaTime, Agent* agent, StateManager* sm);

private:
	Matrix3* target;
	float maxSpeed;
};
