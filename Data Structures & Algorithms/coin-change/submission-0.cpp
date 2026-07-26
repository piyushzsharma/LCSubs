class Solution {
public:
int dfs(vector<int>& coins, int amount,vector<vector<int>> &dp,int i){
    if(amount==0) return dp[i][amount]=0;
    if(i<0) return INT_MAX-1;
    if(dp[i][amount]!=-1) return dp[i][amount];

    if(coins[i]<=amount){
        int take=1+dfs(coins,amount-coins[i],dp,i);
        int nottake=dfs(coins,amount,dp,i-1);
        return dp[i][amount]=min(take,nottake);
    }
    else return dp[i][amount]=dfs(coins,amount,dp,i-1);
    
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return (dfs(coins,amount,dp,n-1)==INT_MAX-1?-1:dfs(coins,amount,dp,n-1));
    }
};
