#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i=0; i<n; i++)
#define vi vector<int>
#define vii vector<vi>
#define pi pair<int, int>
#define li list<int> 
#define u_map unordered_map<int, list<pi> >
#define vb vector<bool>

void printMST(vi parents){
    loop(i, parents.size()){
        cout << i << " -> " << parents[i] << endl;
    }
}

void createMinSpanningTree(u_map adj, int v, int src){
    vi dist(v, INT_MAX);
    vb mst(v, false);
    vi parent(v, -1);

    // initialize the first things first
    dist[src] = 0;
    parent[src] = -1;

    for(int i=0; i<v; i++){
        // find the minimum element from the dist array that is not already present in the mst
        int mini = INT_MAX;
        int min_el;
        for(int j=0; j<v; j++){
            if(!mst[j] && dist[j] < mini){
                min_el = j;
                mini = dist[j];
            }
        }

        // now that we have our element, we need to traverse all the neighbours of current node and follow from there
        int currNode = min_el;
        mst[currNode] = true;

        list<pi> :: iterator it = adj[currNode].begin();

        while(it != adj[currNode].end()){
            int v = it -> first;
            int w = it -> second;

            if(mst[v] == false && w < dist[v]){
                parent[v] = currNode;
                dist[v] = w;
            }

            it++;
        }
    }

    printMST(parent);
    return;
}

int main(){
    int v, e;
    cin >> v >> e;

    vii edges(e, vector<int> (3, -1));

    loop(i, e){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        // u -> v -> w
    }

    // create the adjacency list
    u_map adj;

    loop(i, e){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // print the adj list
    // unordered_map<int, list<pair<int, int> > > :: iterator it = adj.begin();

    // while(it != adj.end()){
    //     cout << it -> first << " -> ";
        
    //     list<pair<int, int> > :: iterator _it = (it -> second).begin();
    //     while(_it != (it -> second).end()){
    //         cout << "[" << _it -> first << ", " << _it -> second << "] ";
    //         _it++;
    //     }cout << endl;
    //     it++;
    // }

    createMinSpanningTree(adj, v, 0);

    return 0;
}