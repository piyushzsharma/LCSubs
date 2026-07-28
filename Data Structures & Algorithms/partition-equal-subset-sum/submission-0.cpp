class Solution {
public:
int target=0;
int dp[201][20001];
int rec(int i,int target,vector<int>&nums){
    if(i==0) return (target==nums[0]);
    if(target==0) return 1;

    if(dp[i][target]!=-1) return dp[i][target];
    int notTake= rec(i-1,target,nums);
    int Take=0;
    if(nums[i]<=target) Take=rec(i-1,target-nums[i],nums);
    return dp[i][target]=Take||notTake;

    }
    bool canPartition(vector<int>& nums) {
        for(auto it:nums) target+=it;
        if ((target%2)!=0) return false;
        target/=2;
        int n=nums.size();
        vector<int> curr(target+1);
        vector<int> prev(target+1);
        prev[0]=curr[0]=1;
        for(int i=1;i<nums.size();i++){
            for(int sum=1;sum<=target;sum++){
                curr[sum]= ((sum>=nums[i])?prev[sum-nums[i]]:0 )|| prev[sum];
            }
            prev=curr;
        }
        return prev[target];

        
    }
};