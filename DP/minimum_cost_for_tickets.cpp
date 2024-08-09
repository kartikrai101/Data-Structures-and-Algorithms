#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i=0; i<n; i++)
#define vi vector<int>
#define vii vector<vi>
#define pi pair<int, int>
#define li list<int> 
#define u_map unordered_map<int, list<pi> >
#define vb vector<bool>

int recursion(int index, int n, vi &cost, vi &days, vi &dp){
    // base case
    if(index >= n) return 0;

    if(dp[index] != -1) return dp[index];

    int path1 = cost[0] + recursion(index+1, n, cost, days, dp);
    
    int i;
    for(i=index; i<n && days[i] < days[index] + 7; i++);
    int path2 = cost[1] + recursion(i, n, cost, days, dp);

    for(i=index; i<n && days[i] < days[index] + 30; i++);
    int path3 = cost[2] + recursion(i, n, cost, days, dp);

    return min(path1, min(path2, path3));
}

int tabulation(int n, vi &days, vi &cost){
    vi dp(n+1, INT_MAX);

    dp[n] = 0;

    for(int k = n-1; k >= 0; k--){
        int path1 = cost[0] + dp[k+1];

        int i;
        for(i = k; i<n && days[i] < days[k] + 7; i++);
        int path2 = cost[1] + dp[i];

        for(i=k; i < n && days[i] < days[k] + 30; i++);
        int path3 = cost[2] + dp[i];

        dp[k] = min(path1, min(path2, path3));
    }

    return dp[0];
}

int main(){
    int n; cin >> n;
    vi days(n); loop(i, n) cin >> days[i];
    vi cost(3); loop(i, 3) cin >> cost[i];

    // 1 -> cost[0]
    // 7 days -> cost[1]
    // 30 days -> cost[20]
    vi dp(n+1, -1);
    cout << tabulation(n, days, cost) << endl;

    return 0;
}