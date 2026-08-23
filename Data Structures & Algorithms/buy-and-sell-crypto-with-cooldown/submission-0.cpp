class Solution {
public:
    int dfs(vector<int>& prices, int i,int b,vector<vector<int>> &dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][b]!=-1) return dp[i][b];
        if(b){
            int sell=prices[i]+dfs(prices,i+2,0,dp);
            int notsell=dfs(prices,i+1,1,dp);
            return dp[i][b]=max(sell,notsell);
        }
        else{
            int buy=dfs(prices,i+1,1,dp)-prices[i];
            int notbuy=dfs(prices,i+1,0,dp);
            return dp[i][b]=max(buy,notbuy);
        }

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return dfs(prices,0,0,dp);
    }
};
