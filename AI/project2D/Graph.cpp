#include "Graph.h"
#include <list>
#include <iostream>
#include <algorithm>
#include <Renderer2D.h>
Graph::Graph()
{
	for (auto node : nodes)
	{
		node->highlighted = false;
	}
}


Graph::~Graph()
{
}

Graph::Graph(int x, int y, float windowHeight)
{
	for (auto node : nodes)
	{
		node->highlighted = false;
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			Graph::node* node = new Graph::node();

			node->position = Vector3((15 * (i + 1) - 6), (windowHeight - ((j + 1) * 15) + 6), 0);

			addNode(node);
		}
	}

	for (auto a : nodes)
	{

		for (auto b : nodes)
		{
			if (a == b)
				continue;

			float dist = Vector3::distance(a->position, b->position);
			if (dist <= 15)
				connectNodes(a, b, dist);
			
			//else break;
		}
		a->size = Vector3(5, 5, 0);
	}
}

void Graph::addNode(node * node)
{
	nodes.push_back(node);
}

void Graph::connectNodes(node * a, node * b, float cost)
{
	Graph::edge* edge = new Graph::edge();
	edge->cost = cost;
	edge->nodeA = a; edge->nodeB = b;
	//a->connections.push_back(edge);
	b->connections.push_back(edge);
}

Graph::node * Graph::findNode(Vector3 position, float distance)
{
	for (auto node : nodes)
	{
		//if (node->position == position)
		//	return node;
		float mag = Vector3::distance(node->position, position);

		if (mag < distance)
			return node;

	}
	return nullptr;
}

std::vector<Vector3> Graph::djikstraSearch(node * startNode, node * endNode)
{
	//set gscores to 0 && parents to null
	for (auto node : nodes)
	{
		node->gScore = 0;
		node->parent = nullptr;
	}
	//list of nodes yet to be visited
	std::list<node*> openList;
	//list ofnodes that have been traversed
	std::list<node*> closedList;

	// set the start nde parent to null
	startNode->parent = nullptr;
	// push the start
	openList.push_back(startNode);

	//while the open list is not empty
	while (!openList.empty())
	{
		//sort by gscore
		openList.sort(node::compareGScore);

		//current node = openlist front
		auto cNode = openList.front();

		//if currentNode is endNode break 
		if (cNode == endNode)
			break;

		//remove current node from open list and put it in closed list
		openList.remove(cNode);
		cNode->visited = true;
		closedList.push_back(cNode);

		for (auto connections : cNode->connections)
		{
			bool foundNode = false;
			auto iter = find(closedList.begin(), closedList.end(), connections->nodeA);
			for (auto iter : closedList)
			{
				if (iter == connections->nodeA)
				{
					foundNode = true;
				}
			}

			if (foundNode == false)
			{
				openList.push_back(connections->nodeA);
				connections->nodeA->gScore = cNode->gScore + connections->cost;
				connections->nodeA->parent = cNode;
			}
		}
	}

	std::vector<Vector3> path;
	node* currentPathNode = endNode;
	while (currentPathNode != nullptr)
	{
		path.push_back(currentPathNode->position);
		currentPathNode->highlighted = true;
		for (auto c : currentPathNode->connections)
		{
			//check if connections target is parent node
			if (c->nodeA == currentPathNode->parent)
			{
				//if true, set the connection to highlighted
				c->highlighted = true;
			}
		}
		currentPathNode = currentPathNode->parent;
	}

	return path;
}

std::vector<Vector3> Graph::aStarSearch(node * startNode, node * endNode)
{
	//list of nodes yet to be visited
	std::list<node*> openList;
	//list ofnodes that have been traversed
	std::list<node*> closedList;

	for (auto node : nodes)
	{
		if (!node->traversable)
		{
			closedList.push_back(node);
		}
	}
	// set the start nde parent to null
	startNode->parent = nullptr;
	// push the start
	openList.push_back(startNode);

	while (!openList.empty())
	{
		openList.sort(node::compareFScore);

		auto cNode = openList.front();

		if (cNode == endNode)
			break;

		openList.remove(cNode);

		if (cNode->traversable)
		cNode->visited = true;


		closedList.push_back(cNode);

		for (auto connections : cNode->connections)
		{
			bool foundNode = false;
			for (auto iter : closedList)
			{
				if (iter == connections->nodeA)
				{
					foundNode = true;
				}
			}
			if (foundNode == false)//dis dont work
			{
				auto n = connections->nodeA;
				openList.push_back(connections->nodeA);
				connections->nodeA->gScore = cNode->gScore + connections->cost;
				connections->nodeA->hScore = Vector3::distance(connections->nodeA->position, endNode->position);
				connections->nodeA->fScore = connections->nodeA->gScore + connections->nodeB->hScore;
				connections->nodeA->parent = cNode;
			}
		}
	}

	std::vector<Vector3> path;
	node* currentPathNode = endNode;
	while (currentPathNode != nullptr)
	{
		path.push_back(currentPathNode->position);
		currentPathNode->highlighted = true;
		//for all connections in current node
		for (auto c : currentPathNode->connections)
		{
			//check if connections target is parent node
			if (c->nodeA == currentPathNode->parent || c->nodeB == currentPathNode->parent)
			{
				//if true, set the connection to highlighted
				c->highlighted = true;
			}
		}
		//iterate through
		currentPathNode = currentPathNode->parent;
	}

	//return vector of positions of path
	return path;
}

void Graph::Draw(aie::Renderer2D * spritebatch)
{
	//for all nodes within nodes vector
	for (auto node : nodes)
	{
		//for all connections within current node
		for (auto e : node->connections)
		{
			//check if both connections are highlighted
			if (e->highlighted)
			{
				//draw the edge as green
				spritebatch->setRenderColour(0, 1, 0, 1);
				spritebatch->drawLine(e->nodeA->position.x, e->nodeA->position.y, e->nodeB->position.x, e->nodeB->position.y);
				spritebatch->setRenderColour(1, 1, 1, 1);

			}
			else
			{
				//draw as white
				spritebatch->drawLine(e->nodeA->position.x, e->nodeA->position.y, e->nodeB->position.x, e->nodeB->position.y);
			}
		}

		//if the node isnt highlighted and hasn't been visited
		if (!node->highlighted && !node->visited)
		{
			if (node->traversable)
			{
				spritebatch->drawBox(node->position.x, node->position.y, node->size.x, node->size.x);
				spritebatch->setRenderColour(1, 1, 1, 1);

			}
			else
			{
				//red
				spritebatch->setRenderColour(1, 0, 0, 1);
				spritebatch->drawBox(node->position.x, node->position.y, node->size.x, node->size.x);
				spritebatch->setRenderColour(1, 1, 1, 1);
			}
		}
		//if it's highlighted
		else if (node->highlighted)
		{
			spritebatch->setRenderColour(0, 1, 0, 1);
			spritebatch->drawBox(node->position.x, node->position.y, node->size.x, node->size.x);
			spritebatch->setRenderColour(1, 1, 1, 1);
		}
		//not highlighted but visited
		else if (!node->highlighted && node->visited)
		{
			spritebatch->setRenderColour(1, 0, 1, 1);
			spritebatch->drawBox(node->position.x, node->position.y, node->size.x, node->size.x);
			spritebatch->setRenderColour(1, 1, 1, 1);
		}

	}
}
