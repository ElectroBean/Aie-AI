#pragma once
#include "State.h"
#include "StateManager.h"
#include "SeekState.h"
#include "FleeState.h"

class WanderState :
	public State
{
public:
	WanderState(Agent* agent, float wanderRadius, float wanderDistance, float jitterAmount, float maxSpeed, Agent * target);
	~WanderState();

	void onEnter(Agent* agent);
	void onExit(Agent* agent);
	void update(float deltaTime, Agent* agent, StateManager* sm);

private:
	float wanderRadius;
	float wanderDistance;
	float jitterAmount;
	float maxSpeed;
	Matrix3 previousTarget;
	bool reachedPos;
	Matrix3 wanderCircle;
	Matrix3 nextPosition;
	Vector3 randCircumPoint;
	

	Agent* target;
};

