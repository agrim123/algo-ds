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
    list<int> *adjlist;
public:
    Graph(int V);
    void add_edge(int x, int y);
    void DepthFirstSearch(int s);
};

Graph::Graph(int V){
    this->V = V;
    adjlist = new list<int>[V];
}

void Graph::add_edge(int x, int y) {
    adjlist[x].push_back(y); // Add y to x's list.
}

void Graph::DepthFirstSearch(int s) {
    // Initialize mark all vertices as not visited
    vector<bool> visited(V, false);

    // Create a stack for Depth First Search
    stack<int> stack;

    stack.push(s);

    list<int>::iterator i;

    while(!stack.empty()) {
        s = stack.top();

        // Pop a vertex from stack
        stack.pop();

        // mark not visited node as visited
        if (!visited[s]) {
            cout<<s<<" ";
            visited[s] = true;
        }

        for (i = adjlist[s].begin(); i != adjlist[s].end(); ++i)
            if (!visited[*i])
                stack.push(*i);
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
