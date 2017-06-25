#include "FollowMouse.h"



FollowMouse::FollowMouse()
{
	inputs = aie::Input::getInstance();
}


FollowMouse::~FollowMouse()
{
}

void FollowMouse::Update(float a_dt, Agent * a_agent)
{
	float mousex = inputs->getMouseX();
	float mousey = inputs->getMouseY();

	float moveSpeed = 200.0f;

	if (mousex > a_agent->position.x)
	{
		a_agent->AddForce(glm::vec2(moveSpeed, 0.0f));
	}
	else if (mousex < a_agent->position.x)
	{
		a_agent->AddForce(glm::vec2((0 - moveSpeed), 0.0f));
	}
	else {}

	if (mousey > a_agent->position.y)
	{
		a_agent->AddForce(glm::vec2(0,  moveSpeed));
	}
	else if (mousey < a_agent->position.y)
	{
		a_agent->AddForce(glm::vec2(0, (0 -moveSpeed)));
	}
	else {}

	if (a_agent->position.x == mousex && a_agent->position.y == mousey)
	{
		a_agent->AddForce(glm::vec2(0, 0));
	}
}
