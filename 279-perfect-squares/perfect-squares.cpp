class Solution {
public:
    int solvemem(int n, vector<int> &dp){
        if(n==0){
            return 0;
        }
        if(dp[n] !=-1)
            return dp[n];
        int ans=n;
        for(int i=1;i*i<=n;i++){
            ans=min( ans, 1+ solvemem(n-(i*i),dp) );
        }
        dp[n]=ans;
        return dp[n];
    }
    int solvetab(int n){
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        for(int j=1;j<=n;j++){
            for(int i=1;i*i<=n;i++){
                if((j-(i*i)) >= 0)
                    dp[j]=min( dp[j], 1+ dp[j-(i*i)] );
            }
        }
        return dp[n];
    }
    int numSquares(int n) {
        	// vector<int> dp(n+1,-1);
        	// return solvemem(n,dp);

            return solvetab(n);
        }
};