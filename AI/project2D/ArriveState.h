#pragma once
#include "State.h"
class ArriveState :
	public State
{
public:
	ArriveState(Matrix3* target, float maxSpeed, float slowDistance);
	~ArriveState();

	void onEnter(Agent* agent);
	void onExit(Agent* agent);
	void update(float deltaTime, Agent* agent, StateManager* sm);

private:
	Matrix3* target;
	float maxSpeed;
	float slowDistance;

};

