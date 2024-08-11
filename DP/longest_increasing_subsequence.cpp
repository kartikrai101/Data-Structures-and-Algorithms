#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define vii vector<vi>
#define loop(i, n) for(int i=0; i<n; i++)

int recursion(int curr, vi &arr, int prev, vii &dp){
    // base case
    if(curr == arr.size()){
        return 0;
    }

    if(dp[curr][prev+1] != -1){
        return dp[curr][prev+1];
    }

    // include/exclude condition
    int include = 0;
    if(prev == -1 || arr[curr] > arr[prev]){
        include = 1 + recursion(curr + 1, arr, curr, dp);
    }
    int exclude = 0 + recursion(curr + 1, arr, prev, dp);

    return dp[curr][prev+1] = max(include, exclude);
}

int tabulation(vi &arr, int n){
    // create your dp
    vii dp(n+1, vi(n+1, 0));

    for(int curr = n-1; curr >= 0; curr--){
        for(int prev = curr-1; prev >= -1; prev--){
            int include = 0;
            if(prev == -1 || arr[curr] > arr[prev])
                include = 1 + dp[curr+1][curr+1];
            int exclude = dp[curr+1][prev+1];

            dp[curr][prev+1] = max(include, exclude);
        }
    }
    return dp[0][0];
}

int main(){
    int n; cin >> n;
    vi arr(n);

    loop(i, n) cin >> arr[i];

    cout << tabulation(arr, n) << endl;

    return 0;
}