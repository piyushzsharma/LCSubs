class Solution {
public:
int dfs(string &s, int i,int j,vector<vector<int>>& dp){
        if(i>=j) return dp[i][j]=1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]!=s[j]){
            return dp[i][j]=0;
        }
        return dp[i][j]=dfs(s,i+1,j-1,dp);
    }
    int countSubstrings(string s) {
        int ans=0;
        vector<vector<int>> dp(s.length(),vector<int>(s.length()+1,-1));
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
            ans+=dfs(s,i,j,dp);                 
            }
        }
        return ans;
    }
};
