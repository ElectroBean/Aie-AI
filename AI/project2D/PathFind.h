#pragma once
#include "State.h"
class PathFind :
	public State
{
public:
	PathFind(Agent* agent, std::vector<Vector3> path, float maxSpeed);
	~PathFind();

	void onEnter(Agent* agent);
	void onExit(Agent* agent);
	void update(float deltaTime, Agent* agent, StateManager* sm);

	float wanderRadius;
	float wanderDistance;
	float jitterAmount;
	float maxSpeed;
	float maxSpeedConst;
	Matrix3 previousTarget;
	bool reachedPos;
	Matrix3 wanderCircle;
	Matrix3 nextPosition;
	Vector3 randCircumPoint;
	int i = 0;

	std::vector<Vector3> nodes;
};

