// Dijkstra's algorithm in C++
// August 4th, 2021

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using Node = int; // scheme for naming vertices
using Edge = pair<Node, int>; // ADT for edge in PriorityQueue class


inline double prob() // generates random value between 0 and 1
{
  return rand() / static_cast<double>(RAND_MAX);
}


// two dimensional vector to represent the graph as a matrix
// index [i] represents the node and index [i][j] represents the edge between nodes 1 and j
class Graph
{
  private:

    vector<vector<int>> graph; // int values represent the weight of the edge between two nodes
    int n_nodes;
    int n_edges;

  public:

    Graph(const int size = 50, const double density = .4, const int range = 10) // default constructor, generates random graph
    {
      graph = vector<vector<int>>(size, vector<int>(size, 0)); // initialize matrix of (size * size), values set to 0
      n_nodes = size;
      n_edges = 0;
      for (int i = 0; i < size; ++i)
      {
        for (int j = i; j < size; ++j) // graph is symetrical, [i][j] == [j][i]
        {
          if (i == j) 
          {
            graph[i][j] = 0; // no self referential loops
          }
          else
          {
            if (prob() < density)
            {
              add(i, j, range);
              n_edges++; // increment number of edges everytime we add one
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

    vector<Edge> neighbors(Node x) // retuns vector of Edge {node, cost} of neighbors 
    {
      vector<Edge> neighbors;
      for (int j; j < n_nodes; ++j)
      {
        if (graph[x][j] > 0)
        {
          Edge e = {j, graph[x][j]};
          neighbors.push_back(e); // adds value to vector
        }
      }
      return neighbors;
    }

    void add(Node x, Node y, int range) // adds to G the edge from x to y, if it is not there.
    {
      if (graph[x][y] == 0)
      {
        graph[x][y] = graph[y][x] = (rand() % range) + 1; // random distance between 1 and range
      }
    }

    void remove(Node x, Node y) // removes the edge from x to y, if it is there.
    {
      if (graph[x][y] > 0)
      {
        graph[x][y] = graph[y][x] = 0;
      }
    }

    int get_edge_value(Node x, Node y) // returns the value associated to the edge (x,y).
    {
      return graph[x][y];
    }

    void set_edge_value(Node x, Node y, int v) // sets the value associated to the edge (x,y) to v.
    {
      graph[x][y] = graph[y][x] = v;
    }

    ~Graph() 
    {
      vector<vector<int>>().swap(graph); // deallocates memory by swapping graph with an unitialized vector
    }
};


// priority queue implementation using a sorted vector
class PriorityQueue
{
  private:

    vector<Edge> queue;

    bool comp(const Edge &a, const Edge &b) // used to compare edges, kept private since it is only used internally to sort
    {
      return a.second < b.second;
    }

  public:

    PriorityQueue() {} // default constructor

    PriorityQueue(Node i, Graph source) // constructor that takes a node and its source graph as arguments
    {
      queue = source.neighbors(i);
      sort(queue.begin(), queue.end(), comp); // sort the queue to get a minHeap
    }

    PriorityQueue(vector<Edge> neighbors) // constructor that takes a vector of edges as an argument
    {
      queue = neighbors;
      sort(queue.begin(), queue.end(), comp); // sort the queue to get a minHeap
    }

    void minPrioirty() // removes the top element of the queue.
    {
      queue.erase(queue.begin());
    }

    bool contains(Edge queue_element) // does the queue contain queue_element.
    {
      Node first = queue_element.first;
      for (int i; i < queue.size(); ++i)
      {
        if (first == queue[i].first)
        {
          return true;
        }
      }
      return false;
    }

    void insert(Edge queue_element) // insert queue_element into queue
    {
      if (contains(queue_element))
      {
        Node first = queue_element.first;
        int second = queue_element.second;
        for (int i; i < queue.size(); ++i)
        {
          Node compare_first = queue[i].first;
          if (first == compare_first)
          {
            int compare_second = queue[i].second;
            queue[i].second = min(second, compare_second); // find min cost and add back to minHeap
          }
        }
      }
      else
      {
        queue.push_back(queue_element);
      }
      sort(queue.begin(), queue.end(), comp); // sort the queue to get a minHeap
    }

    Edge top() // returns the top element of the queue.
    {
      return queue[0];
    }

    int size() // return the number of queue_elements.
    {
      return queue.size();
    }

    vector<Edge> get_queue() // returns the queue
    {
      return queue;
    }

    ~PriorityQueue() 
    {
      vector<Edge>().swap(queue); // deallocates memory by swapping queue with an unitialized vector
    }
};


//
class ShortestPath
{
  private:

    Graph graph;

  public:

    ShortestPath() // default constructor
    {
      graph = Graph();
    }

    ShortestPath(const int size = 50, const double density = .4, const int range = 10) // constructor that takes size, density, and range as arguments
    {
      graph = Graph(size, density, range);
    }

    ShortestPath(Graph graph): graph(graph) {} // constructor that takes an existing graph as an argument


    vector<Node> vertices() // list of vertices in G(V,E).
    {
      vector<Node> nodes;
      for (int i = 0; i < graph.V(); ++i)
      {
        nodes[i] = i;
      }
      return nodes;
    }

    vector<Node> path(Node u, Node w) // find shortest path between u-w and returns the sequence of vertices representing shorest path u-v1-v2-…-vn-w.
    {
      // step 1
      // inlcude s in closed set
      vector<Edge> init; // init vector to feed into priority queue class
      Edge start = {u, 0};
      init.push_back(start);
      PriorityQueue closed_set = PriorityQueue(init);

      // add all immediate successors of s to open set
      vector<Edge> neighbors = graph.neighbors(u);
      PriorityQueue open_set = PriorityQueue(neighbors);

      // step 2
      // pick open node with least cost
      Edge next = open_set.top();
      Node current = next.first;
      int cost = next.second;
      
      // remove from open set and add to closed set
      closed_set.insert(next);
      open_set.minPrioirty();

      while (current != w)  // repeat previous steps until current == w
      {
        neighbors = graph.neighbors(current);
        for (int i = 0; i < neighbors.size(); ++i)
        {
          neighbors[i].second += cost;
          open_set.insert(neighbors[i]);
        }
        next = open_set.top();
        current = next.first;
        cost = next.second;

        closed_set.insert(next);
        open_set.minPrioirty();
      }
    }
    
    int path_size(Node u, Node w) // return the path cost associated with the shortest path.
    {
      vector<Node> solution = path(u, w);
      int size = 0;
      for (int i = 0; i < solution.size() - 1; ++i)
      {
        Node a = solution[i];
        Node b = solution[i + 1];
        size += graph.get_edge_value(a, b); // sum the cost with each associated edge between a and b
      }
      return size;
    }

    ~ShortestPath() {}
};