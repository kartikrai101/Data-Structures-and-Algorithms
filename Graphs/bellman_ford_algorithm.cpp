// Bellman Ford Algorithm works for directed plus undirected graph with negative weights as well, given that no negative cycle is present in the graph
// We use the same formula n-1 times for each node and another time after that to check if there is a negative cycle present in the graph

#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i=0; i<n; i++)
#define vi vector<int>
#define vii vector<vi>
#define pi pair<int, int>
#define li list<int> 
#define u_map unordered_map<int, list<pi> >
#define vb vector<bool>

int main(){
    int v, e;
    cin >> v >> e;

    vii edges(e, vi (3, -1));

    loop(i, e){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    u_map adj;

    loop(i, e){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    findShortestDistance(v, adj, 0);

    return 0;
}