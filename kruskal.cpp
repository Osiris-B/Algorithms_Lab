#include <bits/stdc++.h>
using namespace std;

// DSU Implementation
vector<int> parent;
vector<pair<int, int>> ans;

int find(int u)
{
  if (parent[u] == u)
    return u;
  return parent[u] = find(parent[u]);
}

void unionSet(int u, int v)
{
  int pu = find(u);
  int pv = find(v);
  if (pu != pv)
    parent[pu] = pv;
}

// Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<pair<int, pair<int, int>>> &edges)
{
  // Sort edges in non-decreasing order of weights
  sort(edges.begin(), edges.end());

  // Initialize parent array for DSU
  parent.resize(V);
  for (int i = 0; i < V; ++i)
    parent[i] = i;

  int sum = 0;
  for (auto edge : edges)
  {
    int wt = edge.first;
    int u = edge.second.first;
    int v = edge.second.second;

    if (find(u) != find(v))
    {
      sum += wt;
      unionSet(u, v);
      ans.push_back({u, v});
    }
  }
  return sum;
}

int main()
{
  int V, E;
  cout << "Enter the number of vertices and edges of the graph:\n";
  cin >> V >> E;
  vector<pair<int, pair<int, int>>> edges;
  cout << "Enter the adjacency list and weights:\n";
  for (int i = 0; i < E; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({w, {u, v}});
  }

  cout << spanningTree(V, edges) << "\n";
  for (auto x : ans)
  {
    cout << x.first << '-' << x.second << endl;
  }

  return 0;
}
