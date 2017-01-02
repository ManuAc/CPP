#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph
{
  int V;
  list<int>* adj;

  public:
    Graph(int V);
    void addEdge(int v, int w);
    void bfs(int start = 0);
};

Graph::Graph(int size) {
  V = size;
  adj = new list<int>[size];
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

void Graph::bfs(int start) {
  queue<int> q;
  bool* visited = new bool[V];

  for(int i=0; i<V; i++)
    visited[i] = false;

  q.push(start);

  while(!q.empty()){
    // Get the front node and pop it out from the queue
    int s = q.front();
    q.pop();

    // Print node and mark it as visited
    cout << s << " ";
    visited[s] = true;

    list<int>::iterator it;
    for(it = adj[s].begin(); it != adj[s].end(); ++it)
      if(!visited[*it])
        q.push(*it);
  }
}

// If the graph is disconnected then traverse through each node and if its not marked as visited then call bfs on that node

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
  g.bfs(start);
}
