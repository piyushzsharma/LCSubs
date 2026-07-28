class Solution {
public:
vector<vector<int>> dp;
int bfs(int m, int n){
    if(m==0 && n==0) return 1;
    if(m<0 || n<0) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    return dp[m][n]=bfs(m-1,n)+bfs(m,n-1);
}
    int uniquePaths(int m, int n) {
        dp.resize(m+1, vector<int>(n+1, -1));
        return bfs(m-1,n-1);
    }
};