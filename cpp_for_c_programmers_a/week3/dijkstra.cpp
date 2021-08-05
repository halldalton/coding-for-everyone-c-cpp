// Dijkstra's algorithm in C++
// August 4th, 2021

#include <iostream>
#include <vector>

using namespace std;
using Node = int; // scheme for naming vertices

inline double prob()
{
  return rand() / static_cast<double>(RAND_MAX); // generates random value between 0 and 1
}

class Graph
{
  private:

    // two dimensional vector to represent the graph as a matrix
    vector<vector<int>> graph; // int values represent the weight of the edge between two nodes
    int n_nodes;
    int n_edges;

  public:

    Graph(int size = 50, double density = .4) // default constructor
    {
      graph = vector<vector<int>>(size, vector<int>(size, 0)); // initialize matrix of size x size, values set to 0
      n_nodes = size;
      n_edges = 0;
      for (int i = 0; i < size; ++i)
      {
        for (int j = i; j < size; ++j) // graph is symetrical
        {
          if (i == j) 
          {
            graph[i][j] = 0; // no loops
          }
          else
          {
            if (prob() < density)
            {
              add(i, j);
              n_edges++;
            }
          }
        }
      }
    }

    int V() // returns the number of vertices in the graph
    {
      return n_nodes;
    } 

    int E() // returns the number of edges in the graph
    {
      return n_edges;
    } 

    bool adjacent(Node x, Node y) // tests whether there is an edge from node x to node y.
    {
      if (graph[x][y] > 0)
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    vector<Node> neighbors(Node x) // lists all nodes y such that there is an edge from x to y.
    {
      vector<Node> neighbors;
      for (int j; j < n_nodes; j++)
      {
        if (graph[x][j] > 0)
        {
          neighbors.push_back(j); // adds value to vector
        }
      }
      return neighbors;
    }

    void add(Node x, Node y) // adds to G the edge from x to y, if it is not there.
    {
      if (graph[x][y] == 0)
      {
        graph[x][y] = graph[y][x] = (rand() % 10) + 1; // random distance between 1 and 10
      }
    }

    void remove(Node x, Node y) // removes the edge from x to y, if it is there.
    {
      if (graph[x][y] > 0)
      {
        graph[x][y] = graph[y][x] = 0;
      }
    }

    int get_node_value(Node x)// returns the value associated with the node x.
    {
      return x;
    }

    int get_edge_value(Node x, Node y) // returns the value associated to the edge (x,y).
    {
      return graph[x][y];
    }

    void set_edge_value(Node x, Node y, int v) // sets the value associated to the edge (x,y) to v.
    {
      graph[x][y] = graph[y][x] = v;
    }
};