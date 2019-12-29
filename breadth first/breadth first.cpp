// breadth first.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>


struct Node
{
	Node() {};
	Node(char val) { value = val; }
	std::vector<Node*> Edges{};
	char value;
};

Node a,b,c,d;



void Init()
{
	a.Edges.push_back(&b);
	a.value = 'a';

	b.Edges.push_back(&d);
	b.Edges.push_back(&c);
	b.value = 'b';

	c.Edges.push_back(&d);
	c.Edges.push_back(&b);
	c.value = 'c';

	d.value = 'd';
}

Node* BreadthFirst(Node* start, char goalValue)
{
	std::queue<Node*> que;
	std::vector<char> Visited;

	std::cout << "start: " << start->value<< std::endl;
	que.push(start);

	while (!que.empty())
	{
		Node* current = que.front();
		que.pop();

		for (Node* edge : current->Edges)
		{
			if (edge->value == goalValue)
			{
				std::cout << "found goal: " << edge->value << std::endl;
				return edge;
			}

			if (std::find(Visited.begin(), Visited.end(), current->value)
				== Visited.end())
			{
				std::cout << "visited: " << edge->value << std::endl;
				que.push(edge);
				Visited.push_back(current->value);
			}
		}


	}
	return nullptr;
}


int main()
{
	Init();
	BreadthFirst(&a, 'd');
    std::cout << "Hello World!\n"; 
}


