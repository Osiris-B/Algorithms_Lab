#include <bits/stdc++.h>
using namespace std;

// Function to find sum of weights of edges of the Minimum Spanning Tree.
int MST(int V, vector<vector<int>> adj[])
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> vis(V, 0);

  pq.push({0, 0});
  int sum = 0;
  while (!pq.empty())
  {
    auto it = pq.top();
    pq.pop();

    int node = it.second;
    int wt = it.first;

    if (vis[node] == 1)
      continue;

    vis[node] = 1;
    sum += wt;

    for (auto it : adj[node])
    {
      int adjNode = it[0];
      int edgeWt = it[1];

      if (!vis[adjNode])
      {
        pq.push({edgeWt, adjNode});
      }
    }
  }
  return sum;
}

int main()
{
  int V, E;
  cout << "Enter the number of vertices and edges of the graph:\n";
  cin >> V >> E;
  vector<vector<int>> adj[V];

  cout << "Enter the adjacency list with edge weights:\n";
  for (int i = 0; i < E; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  cout << MST(V, adj) << "\n";

  return 0;
}