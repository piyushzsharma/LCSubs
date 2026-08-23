class Solution {
    vector<vector<int>>dp ;

    int f(int i, int amt,vector<int>&coins){
        ///////////////////////////////////////
        if(amt==0) return 1 ;                              
        if(i==0)  return dp[i][amt] = amt%coins[0]==0 ?  1 : 0 ;
        if(dp[i][amt]!=-1) return dp[i][amt] ; 
        ///////////////// BASE CASES ///////////                       
       
        // CASE1 : TAKE IT
        int take = amt>=coins[i]? f(i,amt-coins[i],coins) : 0 ;
        // CASE2 : NTAKE IT
        int ntake = f(i-1,amt,coins) ;

        return dp[i][amt] = take+ntake ;
    }

public:

    int change(int amount, vector<int>& coins) {  
        int n = coins.size();
        dp = vector<vector<int>>(n,vector<int>(amount+1,-1)) ;
        return f(n-1,amount,coins) ;
    }


};