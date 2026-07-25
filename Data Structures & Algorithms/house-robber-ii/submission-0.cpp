#include <cstring>
class Solution {
public:
int dp[101];
int dfs(vector<int>& nums,int i,int n){
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    return dp[i]=max(dfs(nums,i+1,n),dfs(nums,i+2,n)+nums[i]);

}
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        memset(dp,-1,sizeof(dp));
        int case1 = dfs(nums,0,nums.size()-1);

        memset(dp,-1,sizeof(dp));
        int case2 = dfs(nums,1,nums.size());

        return max(case1, case2);
    }
};
