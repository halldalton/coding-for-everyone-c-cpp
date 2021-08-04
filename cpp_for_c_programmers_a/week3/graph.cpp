// Randomly Generated Graph, using New for memory allocation
// Dalton Hall
// August 4th, 2021

#include <iostream>

using namespace std;


double prob()
{
  return rand() / static_cast<double>(RAND_MAX);
}


bool** generate_random_graph(int size)
{
  bool **graph; // init 2D array
  graph = new bool *[size];
  for (int i = 0; i < size; ++i)
  {
    graph[i] = new bool[size];
  }
  for (int i = 0; i < size; ++i)
  {
    for (int j = i; j < size; ++j) // graph is symetrical
    {
      if (i == j) 
      {
        graph[i][j] = false; // no loops
      }
      else
      {
        graph[i][j] = graph[j][i] = (prob() < 0.5); // aproximately 1/2 of possible edges will be filled
      }
    }
  }
  return graph;
}


void print_graph(bool **graph, int size)
{
  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      cout << graph[i][j] << '\t';
      if (j == (size - 1))
      {
        cout << endl;
      }
    }
  }
  cout << endl;
}


bool is_connected(bool **graph, int size)
{
  int old_size = 0, c_size = 0;
  bool *close = new bool[size];
  bool *open = new bool[size];

  for (int i = 0; i < size; i++)
  {
    open[i] = close[i] = false;
  }

  open[0] = true;

  while (c_size < size)
  {
    for (int i = 0; i < size; ++i)
    {
      old_size = c_size;
      if (open[i] && (close[i] == false))
      {
        close[i] = true;
        c_size++;
      }
      for (int j = 0; j < size; ++j)
      {
        open[j] = open[j] || graph[i][j];
      }
      if (c_size == size)
      {
        return true;
      }
      if (old_size == c_size)
      {
        return false;
      }
    }
  }
}


int main()
{
  srand(time(0));

  int size;
  cout << "\nEnter int value to create graph of size n x n: ";
  cin >> size;

  bool **graph = generate_random_graph(size); // fill graph with edges

  cout << "\nPopulated graph" << endl;
  print_graph(graph, size);

  bool connected = is_connected(graph, size);

  if (connected)
  {
    cout << "Graph is connected" << endl;
  }
  else
  {
    cout << "Graph is not connected" << endl;
  }

  cout << endl;

  return 0;
}