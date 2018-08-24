/*
 * Depth First Search (Recursive Approach use function call stack)
 *
 * Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.
 */

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
    int V;
    list<int> *adj;
    void DepthFirstSearchUtil(int v, vector<bool>& visited);
public:
    Graph(int V);
    void add_edge(int v, int w);
    void DepthFirstSearch(int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::add_edge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DepthFirstSearchUtil(int v, vector<bool>& visited) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DepthFirstSearchUtil(*i, visited);
}

void Graph::DepthFirstSearch(int v) {
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    DepthFirstSearchUtil(v, visited);
}

int main() {
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    cout << "Depth First Traversal (starting from vertex 2) ";
    g.DepthFirstSearch(2);
    cout<<endl;

    return 0;
}
