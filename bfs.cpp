#include <bits/stdc++.h>
#include <time.h>
using namespace std;

// Function to perform BFS traversal of the graph
void BFS(vector<vector<int>> &graph, int startVertex, vector<bool> &visited)
{
  // Create a queue for BFS
  queue<int> q;

  // Mark the current node as visited and enqueue it
  visited[startVertex] = true;
  q.push(startVertex);

  while (!q.empty())
  {
    // Dequeue a vertex from the queue and print it
    int currentVertex = q.front();
    q.pop();
    cout << currentVertex << " ";

    // Get all adjacent vertices of the dequeued vertex
    for (int i = 0; i < graph.size(); ++i)
    {
      if (graph[currentVertex][i] == 1 && !visited[i])
      {
        visited[i] = true;
        q.push(i);
      }
    }
  }
}

int main()
{
  int numVertices;
  clock_t start, end, runtime;
  cout << "Enter the number of vertices in the graph: ";
  cin >> numVertices;

  // Create an adjacency matrix representation of the graph
  vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));

  cout << "Enter the adjacency matrix:\n";
  for (int i = 0; i < numVertices; ++i)
  {
    for (int j = 0; j < numVertices; ++j)
    {
      cin >> graph[i][j];
    }
  }

  int startVertex;
  cout << "Enter the starting vertex for BFS traversal: ";
  cin >> startVertex;

  // Create a vector to track visited vertices
  vector<bool> visited(numVertices, false);

  cout << "BFS traversal starting from vertex " << startVertex << ": ";
  start = clock();
  BFS(graph, startVertex, visited);
  end = clock();
  runtime = end - start;

  cout << endl;
  cout << "Time taken by BFS graph traversal is " << (double)(runtime) / (double)(CLOCKS_PER_SEC) << endl;
  cout << endl;

  return 0;
}
