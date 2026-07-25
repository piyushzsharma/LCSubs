class Solution {
public:
    int dfs(string &s, int i,int j,vector<vector<int>>& dp){
        if(i>=j) return dp[i][j]=1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]!=s[j]){
            return dp[i][j]=0;
        }
        i++;
        j--;
        return dp[i][j]=dfs(s,i,j,dp);
    }
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
        int size=0;
        int idx=0;
        for(int i=0;i<s.length();i++){
            for(int j=0;j<s.length();j++){
                if(dfs(s,i,j,dp)){
                    if(size<j-i+1){
                        size=j-i+1;
                        idx=i;
                    }
                }
            }
        }
        return s.substr(idx,size);
    }
};