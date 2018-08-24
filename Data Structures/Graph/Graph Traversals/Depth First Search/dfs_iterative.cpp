/*
 * Depth First Search (Iterative Approach uses stack)
 *
 * Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void add_edge(int x, int y);
    void DepthFirstSearch(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::add_edge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DepthFirstSearch(int s) {
    // Initialize mark all vertices as not visited
    vector<bool> visited(V, false);

    stack<int> S;

    S.push(s);

    while(!S.empty()) {
        s = S.top();

        S.pop();

        // mark not visited node as visited
        if (!visited[s]) {
            cout<<s<<" ";
            visited[s] = true;
        }

        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            if (!visited[*i])
                S.push(*i);
    }
}

int main()
{
    Graph graph(5);
    graph.add_edge(1, 0);
    graph.add_edge(0, 2);
    graph.add_edge(2, 1);
    graph.add_edge(0, 3);
    graph.add_edge(1, 4);

    cout << "Depth First Traversal\n";
    graph.DepthFirstSearch(0);

    return 0;
}
