#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i=0; i<n; i++)
#define vi vector<int>
#define vii vector<vi>
#define pi pair<int, int>
#define li list<int> 
#define u_map unordered_map<int, list<pi> >
#define vb vector<bool>

int memoisedSol(int index, vi &values, vi &weights, int W, vii &dp){
    // base case
    if(index == 0){
        if(weights[0] <= W)
            return values[0];
        else
            return 0;
    }

    // memo check
    if(dp[index][W] != -1) return dp[index][W];

    int include = 0;
    if(weights[index] <= W){
        include = values[index] + memoisedSol(index-1, values, weights, W-weights[index], dp);
    }
    int exclude = memoisedSol(index-1, values, weights, W, dp);

    return dp[index][W] = max(include, exclude);
}

int tabulationSol(int W, vi values, vi weights, int N){
    // construct our own table
    vii dp(N+1, vi(W+1, 0));

    // find the initial lookup values
    for(int w = weights[0]; w <= W; w++){
        if(weights[0] <= W){
            dp[0][w] = values[0];
        }else{
            dp[0][w] = 0;
        }
    }

    // run the loop and fill out the remaining table
    for(int index = 1; index < N; index++){
        for(int w = 0; w <= W; w++){
            int include = 0;
            if(weights[index] <= w)
                include = values[index] + dp[index-1][w-weights[index]];

            int exclude = dp[index-1][w];

            dp[index][w] = max(include, exclude);
        }
    }

    return dp[N-1][W];
}

int main(){
    int W; cin >> W; // max weight
    int N; cin >> N; // number of items

    vi values(N);
    vi weights(N);

    loop(i, N) cin >> values[i];
    loop(i, N) cin >> weights[i];

    vii dp(N+1, vi(W+1, -1));

    cout << memoisedSol(N-1, values, weights, W, dp) << endl;
    cout << tabulationSol(W, values, weights, N) << endl;

    return 0;
}