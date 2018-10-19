#include<bits/stdc++.h>

using namespace std;

#define for0(j) for(int i = 0; i < j; i++)
#define pb push_back
#define mk make_pair

const int MAX = 1e4+5;
typedef pair<long long, int> PI;
bool marked[MAX];
vector<PI> adj[MAX];

long long prim(int x) {
    priority_queue<PI, vector<PI>, greater<PI> > Q;
    int y;
    long long minCost = 0;
    PI p;

    Q.push(mk(0, x));

    while (!Q.empty()) {
        p = Q.top(); // edge with min weight
        Q.pop();
        x = p.second;
        if (marked[x]) continue; // check for cycle

        minCost += p.first;
        marked[x] = true;
        for0 (adj[x].size())
        {
            y = adj[x][i].second;
            if (!marked[y]) Q.push(adj[x][i]);
        }
    }

    return minCost;
}

int main() {
    int nodes, edges, x, y;
    long long weight;
    cin>>nodes>>edges;

    for0 (edges)
    {
        cin>>x>>y>>weight;
        adj[x].pb(mk(weight, y));
        adj[y].pb(mk(weight, x));
    }

    cout<<prim(1)<<endl;
    return 0;
}
