#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i=0; i<n; i++)
#define vi vector<int>
#define vii vector<vi>
#define pi pair<int, int>
#define li list<int> 
#define u_map unordered_map<int, list<pi> >
#define vb vector<bool>

int findWays(int target, vi &arr, vi &dp){
    // base case
    if(target < 0) return 0;
    if(target == 0) return 1;

    if(dp[target] != -1) return dp[target];

    int ans = 0;
    for(int i=0; i<arr.size(); i++){
        ans += findWays(target-arr[i], arr, dp);
    }

    return dp[target] = ans;
}

int findWaysTabulation(int target, vi &arr){
    vi dp(target+1, 0);

    dp[0] = 1;

    for(int i=1; i<= target; i++){
        for(int j=0; j<arr.size(); j++){
            if(i - arr[j] >= 0){
                dp[i] += dp[i-arr[j]];
            }
        }
    }

    return dp[target];
}

int main(){
    // you have to tell the number of ways to select values from the array such that their sum is equal to the target value
    int n; cin >> n;
    vi arr(n); loop(i, n) cin >> arr[i];
    int target; cin >> target;

    cout << findWaysTabulation(target, arr) << endl;

    return 0;
}