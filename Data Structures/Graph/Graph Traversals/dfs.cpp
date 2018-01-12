/*
 * Depth First Search (Recursive Approach use function call stack)
 *
 * Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.
 */

#include <iostream>
#include <list>

using namespace std;

// A directed graph using adjacency list representation
class Graph {
    int V;
    list<int> *adjlist;
    void DepthFirstSearchUtil(int v, bool visited[]);
public:
    Graph(int V);
    void add_edge(int v, int w);
    void DepthFirstSearch(int v);
};

Graph::Graph(int V) {
    this->V = V;
    adjlist = new list<int>[V];
}

void Graph::add_edge(int v, int w) {
    adjlist[v].push_back(w);
}

void Graph::DepthFirstSearchUtil(int v, bool visited[]) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;

    for (i = adjlist[v].begin(); i != adjlist[v].end(); ++i)
        if (!visited[*i])
            DepthFirstSearchUtil(*i, visited);
}

// DepthFirstSearch traversal of the vertices reachable from v.
// It uses recursive DepthFirstSearchUtil()
void Graph::DepthFirstSearch(int v) {
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call DepthFirstSearchUtil to print DepthFirstSearch traversal
    DepthFirstSearchUtil(v, visited);
}

int main() {
    // Create a graph given in the above diagram
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    cout << "Depth First Traversal (starting from vertex 2) n";
    g.DepthFirstSearch(2);

    return 0;
}
