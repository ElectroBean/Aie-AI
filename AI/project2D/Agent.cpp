#include "Agent.h"
#include "IBehaviour.h"
#include <random>

Agent::Agent()
{
	health = 100.0f;
	weapon = true;
}

Agent::Agent(Vector3 position, aie::Texture* AgentTexture)
{
	this->GlobalTransform.position = position;
	health = 100.0f;
	weapon = true;
	this->AgentTexture = AgentTexture;
}


Agent::~Agent()
{
}

void Agent::AddForce(Vector3 a_force)
{
	acceleration = acceleration + a_force;
}

void Agent::update(float deltaTime)
{
	for (auto iter = behaviours.begin(); iter != behaviours.end(); iter++)
	{
		(*iter)->Update(deltaTime, this);
	}

	AddForce(velocity * -1.0f);
	GlobalTransform.position = GlobalTransform.position + velocity * deltaTime;
	velocity = velocity + acceleration * deltaTime;

	acceleration = Vector3(0, 0, 0);

	if (this->GlobalTransform.position.x > 1280)
		this->GlobalTransform.position.x = 0;

	if (this->GlobalTransform.position.x < 0)
		this->GlobalTransform.position.x = 1280;

	if (this->GlobalTransform.position.y > 720)
		this->GlobalTransform.position.y = 0;

	if (this->GlobalTransform.position.y < 0)
		this->GlobalTransform.position.y = 720;


	if (health <= -100)
		health = -100;
	
}

void Agent::Draw(aie::Renderer2D * renderer)
{
	renderer->drawSprite(AgentTexture, GlobalTransform.position.x, GlobalTransform.position.y, 32, 32, 0, 0);
	renderer->setRenderColour(1, 0, 0, 1);
	renderer->drawLine(GlobalTransform.position.x - 25, GlobalTransform.position.y + 25, GlobalTransform.position.x + health / 4, GlobalTransform.position.y + 25);
	renderer->setRenderColour(1, 1, 1, 1);
}

void Agent::AddBehaviours(IBehaviour * behaviour)
{
	this->behaviours.push_back(behaviour);
}

bool Agent::hasWeapon()
{
	return weapon;
}

float Agent::getHealth()
{
	return health;
}

void Agent::takeDamage(float damage)
{
	health -= damage;
}

