
class Solution {
   public:
    int longestCommonSubsequence(string& s1, string& s2) {
        vector<int> curr(max(s1.length(),s2.length())+1,0);
        vector<int> prev(max(s1.length(),s2.length())+1,0);
        for(int i=1;i<=s1.length();i++){
            for(int j=1;j<=s2.length();j++){
                if(s1[i-1]==s2[j-1])  curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[s2.length()];
    }
};