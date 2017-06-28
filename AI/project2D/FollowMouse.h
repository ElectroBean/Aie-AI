#pragma once
#include "IBehaviour.h"
#include <Input.h>

class FollowMouse :
	public IBehaviour
{
public:
	FollowMouse();
	~FollowMouse();

	void virtual Update(float a_dt, Agent* a_agent);

protected:
	aie::Input* inputs;
	float moveSpeed;
};

