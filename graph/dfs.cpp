#include<iostream>
#include<list>
using namespace std;

class Graph
{
  int V;
  list<int>* adj;
  void dfsUtil(int v, bool visited[]);

  public:
    Graph(int V);
    void addEdge(int v, int w);
    void dfs(int start = 0);
};

Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

void Graph::dfsUtil(int v, bool visited[]) {
  visited[v] = true;
  cout << v << " ";

  list<int>::iterator it;
  for(it = adj[v].begin(); it!= adj[v].end(); ++it)
    if(!visited[*it])
      dfsUtil(*it, visited);
}

void Graph::dfs(int start) {
  bool *visited = new bool[V];
  // memset(visited, 0, V);
  for(int i=0; i<V; i++)
    visited[i] = false;

  // For connected graph
  dfsUtil(start, visited);
  
  // For disconnected graphs
  // for(int i=0; i<V; i++)
  //   if(!visited[i])
  //     dfsUtil(i, visited);
}

int main()
{
  int size = 4, start;
  
  Graph g(size);

  g.addEdge(0, 1); 
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3); 
  g.addEdge(3, 3);

  cout << "Enter start vertex:"<< endl;
  cin >> start;
  g.dfs(start);
}
