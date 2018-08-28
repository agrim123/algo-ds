/*
 * Breath First Search
 *
 * Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.
 */

#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph {
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void add_edge(int v, int w);
    void BreadthFirstSearch(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::add_edge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BreadthFirstSearch(int V) {
    vector<bool> visited(V, false);

    // Initialize a queue for Breadth First Search
    queue<int> Q;

    // Mark the current node as visited and enqueue it
    visited[V] = true;
    Q.push(V);

    while(!Q.empty()) {
        V = Q.front();
        cout << V << " ";

        Q.pop();

        // Get all adjacent vertices of the dequeued vertex 'V'
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(auto i = adj[V].begin(); i != adj[V].end(); ++i) {
            if(!visited[*i]) {
                visited[*i] = true;
                Q.push(*i);
            }
        }
    }
}

int main() {
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    cout << "Breadth First Traversal (starting from vertex 1) ";
    g.BreadthFirstSearch(1);
    cout<<endl;
    return 0;
}
