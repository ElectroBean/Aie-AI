#include "FollowMouse.h"



FollowMouse::FollowMouse()
{
	inputs = aie::Input::getInstance();
	moveSpeed = 200.0f;
}


FollowMouse::~FollowMouse()
{
}

void FollowMouse::Update(float a_dt, Agent * a_agent)
{
	float mousex = inputs->getMouseX();
	float mousey = inputs->getMouseY();
	Vector3 mouseXY = Vector3(mousex, mousey, 0);

	float move = moveSpeed;
	float distance = Vector3::distance(a_agent->GlobalTransform.position, mouseXY);
	if (distance < moveSpeed)
	{
		move = distance;
	}

	if (mousex > a_agent->GlobalTransform.position.x)
	{
		a_agent->AddForce(Vector3(move, 0.0f, 0));
	}
	else if (mousex < a_agent->GlobalTransform.position.x)
	{
		a_agent->AddForce(Vector3((0 - move), 0.0f, 0));
	}
	else {}

	if (mousey > a_agent->GlobalTransform.position.y)
	{
		a_agent->AddForce(Vector3(0, move, 0));
	}
	else if (mousey < a_agent->GlobalTransform.position.y)
	{
		a_agent->AddForce(Vector3(0, (0 - move), 0));
	}
	else {}

	if (a_agent->GlobalTransform.position.x == mousex
		&& a_agent->GlobalTransform.position.y == mousey)
	{
		a_agent->AddForce(Vector3(0, 0, 0));
	}
}
