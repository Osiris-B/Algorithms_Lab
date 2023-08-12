#include <bits/stdc++.h>
#include <time.h>
using namespace std;

// Recursive function to perform DFS traversal of the graph
void DFS(vector<vector<int>> &graph, int start)
{
  int n = graph.size();

  // Create a vector to track visited vertices
  vector<bool> visited(n, false);

  // Stack to store vertices to be explored
  stack<int> stk;

  // Push the start vertex onto the stack
  stk.push(start);

  // Mark the start vertex as visited
  visited[start] = true;

  cout << "DFS traversal starting from vertex " << start << ": ";

  while (!stk.empty())
  {
    int current = stk.top();
    stk.pop();

    cout << current << " ";

    // Traverse all adjacent vertices of the current vertex
    for (int i = 0; i < n; ++i)
    {
      if (graph[current][i] == 1 && !visited[i])
      {
        stk.push(i);
        visited[i] = true;
      }
    }
  }

  cout << endl;
}

int main()
{
  int n;
  cout << "Enter the number of vertices in the graph: ";
  cin >> n;

  // Create an adjacency matrix representation of the graph
  vector<vector<int>> graph(n, vector<int>(n, 0));

  cout << "Enter the adjacency matrix:\n";
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cin >> graph[i][j];
    }
  }

  int start;
  cout << "Enter the starting vertex for DFS traversal: ";
  cin >> start;

  DFS(graph, start);

  return 0;
}
