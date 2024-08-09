#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i=0; i<n; i++)
#define vi vector<int>
#define vii vector<vi>
#define pi pair<int, int>
#define li list<int> 
#define u_map unordered_map<int, list<pi> >
#define vb vector<bool>

int recursion(int num, vi &dp){
    // base case
    if(num == 0) return 0;

    if(dp[num] != -1)
        return dp[num];

    // run a loop for all the numbers from 1 to range
    int ans = INT_MAX;
    for(int i=1; i*i <= num; i++){
        ans = min(ans, 1 + recursion(num - i*i, dp));
    }

    return dp[num] = ans;
}

int tabulation(int num){
    vi dp(num+1, INT_MAX);

    dp[0] = 0;
    
    for(int i=1; i<=num; i++){
        for(int j=1; j*j <= i; j++){
            if(i - j*j >= 0){
                dp[i] = min(dp[i], 1 + dp[i - j*j]);
            }
        }
    }
    return dp[num];
}

int main(){
    int n; cin >> n;
    vi dp(n+1, -1);
    cout << tabulation(n) << endl;

    return 0;
}