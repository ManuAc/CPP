#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph {
  private:
    int n;
    std::list<std::pair<int, int> >* adj;

  public:
    Graph(int v);
    void addEdge(int u, int v, int w);
    int minVertex(int distanceSet[], int stSet[]);
    void dijkstrasShortestPath(int src = 0);
};


Graph::Graph(int v) {
  n = v;
  adj = new std::list<std::pair<int, int> >[n];
}

void Graph::addEdge(int u, int v, int w) {
  adj[u].push_back(std::make_pair(v, w));
}

int Graph::minVertex(int distanceSet[], int stSet[]) {
  int min_value, min_index = INT_MAX;

  for(int i=0; i<n; i++) {
    if(stSet[i]==false && distanceSet[i] < min_value) {
      min_value = distanceSet[i];
      min_index = i;
    }
  }
  return min_index;
}

void Graph::dijkstrasShortestPath(int src) {
  // bool stSet[n];
  // int distanceSet[n];

  // for(int i=0; i<n; i++) {
    // stSet[i] = false;
    // distanceSet[i] = INT_MAX;
  // }

  // distanceSet[src] = 0;

  for(int i=0; i<n; i++) {
    // int v = minVertex(distanceSet, stSet);

    int v = i;

    std::list<std::pair<int, int> >::iterator it;
    for(it=adj[v].begin(); it != adj[v].end(); ++it) {
      cout << "Testing printing neghbours of " << v << " : " << it->first << it->second << endl;
    }
  }
}


int main() {
  Graph g(4);
  g.addEdge(0, 1, 4);
  g.addEdge(0, 2, 8);
  g.addEdge(1, 3, 3);
  g.addEdge(2, 4, 7);
  g.addEdge(3, 4, 9);
  g.addEdge(4, 1, 11);
  g.addEdge(2, 1, 2);

  g.dijkstrasShortestPath();
  return 0;
}
