#include <cstring>
class Solution {
public:
int dp[101];
    int dfs(vector<int> &nums,int n){
        if(n>=nums.size()) return 0;
        if(dp[n]!=-1) return dp[n];

        return dp[n]=max(dfs(nums,n+1),nums[n]+dfs(nums,n+2));

    }


    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return dfs(nums,0);
    }
};
