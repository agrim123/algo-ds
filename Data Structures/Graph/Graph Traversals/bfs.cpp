/*
 * Breath First Search
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
public:
    Graph(int V);
    void add_edge(int x, int y);
    void BreadthFirstSearch(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adjlist = new list<int>[V];
}

void Graph::add_edge(int x, int y) {
    adjlist[x].push_back(y); // Add y to x's list.
}

void Graph::BreadthFirstSearch(int s) {
    // Initialize a visited list
    bool *visited = new bool[V];

    // Mark all the vertices as not visited
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Initialize a queue for Breadth First Search
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty()) {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";

        // Pop that element
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex 's'
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adjlist[s].begin(); i != adjlist[s].end(); ++i) {
            if(!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
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

    cout << "Breadth First Traversal (starting from vertex 1) n ";
    g.BreadthFirstSearch(1);
    cout<<endl;
    return 0;
}
