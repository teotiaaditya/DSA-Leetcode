class Solution {
public:
    //RECURTION
    int solve(vector<int>& nums, int curr, int prev){
        if(curr >= nums.size()){
            return 0;
        }
        int include=0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include= 1 + solve(nums, curr+1, curr);
        }
        int exclude= solve(nums, curr+1, prev);
        return max(include,exclude);
    }

    //MEMOIZATION
    int solveMem(vector<int>& nums, int curr, int prev, vector<vector<int>> &dp){
        if(curr == nums.size()){
            return 0;
        }
        // -1 koi index hota hi nahi hai is lie hum prev +1 kar rahe hai aur -1 ko 0 se darsha rahe hai aur N-1 size islie lia hai

        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];

        int include=0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include= 1 + solveMem(nums, curr+1, curr, dp);
        }
        int exclude=  solveMem(nums, curr+1, prev, dp);
        
        return dp[curr][prev+1]=max(include,exclude);
    }
    int solveTab(int n, vector<int>& nums){
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for(int curr =n-1 ; curr>=0; curr--){
            for(int prev= n-1; prev>=-1; prev--){
                int include=0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include= 1 + dp[curr+1][curr+1];
                }
                int exclude=  dp[curr+1][prev+1];
                dp[curr][prev+1]=max(include,exclude);
            }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // //RECURTION
        // return solve(nums, 0, -1);

        // //MEMOIZATION
        // vector<vector<int>> dp(n, vector<int> (n+1, -1));
        // return solveMem(nums, 0, -1, dp);

        //TABULATION
        return solveTab(n, nums);
    }
};