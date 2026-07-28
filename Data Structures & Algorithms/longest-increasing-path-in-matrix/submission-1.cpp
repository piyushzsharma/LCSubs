class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int dfs(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1;
        for(int x=0;x<4;x++){
            int ni=i+dx[x];
            int nj=j+dy[x];
            if(ni<0 || ni>=matrix.size() || nj<0 ||nj>=matrix[0].size()) continue;
            else if( matrix[ni][nj]>matrix[i][j]) ans=max(ans, 1+dfs(matrix,ni,nj,dp));

            }
            return dp[i][j]=ans;
        }
       
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int ans=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dfs(matrix,i,j,dp));
            }
        }
        return ans;
    }
};