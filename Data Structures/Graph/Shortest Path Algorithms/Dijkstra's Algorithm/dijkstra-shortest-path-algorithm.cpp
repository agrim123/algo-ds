#include<bits/stdc++.h>

using namespace std;

#define SIZE 100000 + 1
#define for0(j) for(int i = 0; i < j; i++)
#define pb push_back
#define mk make_pair

vector<pair<int, int>> v[SIZE];
bool visited[SIZE];

// Time complexity: O(V + ElogV)
void dijkstra() {
    vector<int> distance(SIZE, INT_MAX);
    memset(visited, false, sizeof(visited));  // mark all vertices as unvisited
    distance[1] = 0;

    multiset<pair<int, int>> s;

    s.insert(mk(0,1)); // source node with distance 0

    while (!s.empty()) {
        pair<int, int> p = *s.begin();  // pop vertex with minimum distance
        s.erase(s.begin());

        int x = p.second, weight = p.first;
        if (visited[x]) continue;  // if already visited

        visited[x] = true;

        for0(v[x].size()) {
            int e = v[x][i].first, w = v[x][i].second;

            if (distance[x] + w < distance[e]) {
                distance[e] = distance[x] + w;
                s.insert(mk(distance[e], e));
            }
        }
    }
}

int main() {
    return 0;
}
