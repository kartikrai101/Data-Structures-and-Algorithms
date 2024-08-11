#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i=0; i<n; i++)
#define vi vector<int>
#define vii vector<vi>
#define pi pair<int, int>
#define li list<int> 
#define u_map unordered_map<int, list<pi> >
#define vb vector<bool>

int recursion(int x, int y, vii &matrix, int &maxi, vii &dp){
    // base case
    if(x >= matrix.size() || y >= matrix.size()){
        return 0;
    }

    if(dp[x][y] != -1){
        return dp[x][y];
    }

    int right = recursion(x+1, y, matrix, maxi, dp);
    int diagonal = recursion(x+1, y+1, matrix, maxi, dp);
    int down = recursion(x, y+1, matrix, maxi, dp);

    if(matrix[x][y] == 1){
        int ans = 1 + min(right, min(down, diagonal));
        maxi = max(maxi, ans);
        return ans;
    }else{
        return 0;
    }
}

int main(){
    int n, m; cin >> m >> n;
    vii matrix(m, vi(n, -1));

    loop(i, m){
        loop(j, n){
            cin >> matrix[i][j];
        }
    }

    vii dp(n+1, vi(m+1, -1));
    
    int maxi = 0;
    recursion(0, 0, matrix, maxi, dp);
    cout << maxi << endl;

    return 0;
}