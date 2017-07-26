#pragma once
#include <functional>
#include <Vector3.h>
#include <vector>

namespace aie
{
	class Renderer2D;
}

class Graph
{
public:
	Graph();
	~Graph();
	Graph(int x, int y, float windowHeight);
	struct node;
	struct edge
	{
		node* nodeA;
		node* nodeB;
		float cost;
		bool highlighted = false;
		bool traversable = true;
	};

	struct node
	{
		Vector3 position;
		Vector3 index;
		float gScore;
		bool highlighted;
		node* parent;
		std::vector<edge*> connections;
		float hScore;
		float fScore;
		bool visited = false;
		bool traversable = true;
		Vector3 size;

		static bool compareGScore(node* a, node* b)
		{
			return a->gScore < b->gScore;
		}
		static bool compareFScore(node* a, node* b)
		{
			return a->fScore < b->fScore;
		}

		Vector3 getPos() { return position; }

	};

	void addNode(node* node);
	void connectNodes(node* a, node* b, float cost);
	node* findNode(Vector3 position, float distance);
	std::vector<Vector3> djikstraSearch(node* startNode, node* endNode);
	std::vector<Vector3> aStarSearch(node* startNode, node* endNode);
	void Draw(aie::Renderer2D* spritebatch);
	std::vector<node*> nodes;

};

