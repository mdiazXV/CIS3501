//Mariah Diaz
//CIS 3501
//Fall 2019
//Prof. John P. Baugh
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

//a struct to store the graph's edges
struct Edge 
{
	int src, dest;
};

//the following class represents a graph object 
class Graph
{
public: 

	//a vector of vectors to represent an adjacency list
	vector<vector<int>> adjacencyList;

	Graph(vector<Edge> const& edges, int N) //graph constructor
	{
		adjacencyList.resize(N); //resize vector to size N of type vector<int>

		for(auto &edge: edges) //adding edges to graph
		{
			adjacencyList[edge.dest].push_back(edge.src); //insert at the end
		}
	}
};

//the following function has input of a pointer to a graph object
//and the number of nodes and its output is the adjacency list 
//for the graph object and shows which nodes point to other nodes
void printGraph(Graph const& graph, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << i << " ";

		for (int v : graph.adjacencyList[i])
		{
			cout << v << " ";
		}

		cout << endl;
	}

}

int main()
{
	vector<Edge> edges =
	{
		{0,1}, {1,2}, {3,1}
	};

	int N = 4;

	Graph graph(edges, N);
	printGraph(graph, N);

	system("pause");
}