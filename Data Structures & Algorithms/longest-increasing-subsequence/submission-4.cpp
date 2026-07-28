class Solution {
public:
    int dfs(vector<int>& nums,int i,int prev,vector<vector<int>>& dp){
        if(i==0) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        if(prev==nums.size()||nums[i-1]<nums[prev]) {
            int take=1+dfs(nums,i-1,i-1,dp);
            int nottake=dfs(nums,i-1,prev,dp);
            return dp[i][prev]=max(take,nottake);
        }
        else return dp[i][prev]=dfs(nums,i-1,prev,dp);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        //if(n==1) return 1;
        return dfs(nums,n,n,dp);
    }
};
