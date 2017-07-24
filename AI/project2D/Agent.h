#pragma once
#include <glm\glm.hpp>
#include <iostream>
#include <vector>
#include <vector2.h>
#include <Vector3.h>
#include <Matrix3D.h>
#include <Renderer2D.h>
#include <Texture.h>

class IBehaviour;
namespace aie
{
	class Renderer2D;
}

class Agent
{
public:
	Agent();
	Agent(Vector3 position, aie::Texture* AgentTexture);
	~Agent();

	void AddForce(Vector3 a_force);
	void update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);
	void AddBehaviours(IBehaviour* behaviour);
	bool hasWeapon();
	float getHealth();

	Matrix3 GlobalTransform;
	Vector3 acceleration;
	Vector3 velocity;

	std::vector<IBehaviour*> behaviours;

private:
	float health;
	bool weapon;
	float MaxVelocity;
	aie::Texture* AgentTexture;
};

