class Solution {
public:
    //RECURTION
    int solve(vector<int>& nums, int curr, int prev){
        if(curr >= nums.size()){
            return 0;
        }
        int include=0;
        // this -1 condition because we have to take the first element in any cost
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
        // -1 koi index hota hi nahi hai is lie hum prev +1 kar rahe hai aur -1 ko 0 se darsha rahe hai aur N+1 size islie lia hai

        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];

        int include=0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include= 1 + solveMem(nums, curr+1, curr, dp);
        }
        int exclude=  solveMem(nums, curr+1, prev, dp);
        
        return dp[curr][prev+1]=max(include,exclude);
    }

    //TABULATION
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

    //Space Optimization
    int solveSO(int n, vector<int>& nums){
        vector<int> currROW(n+1, 0);
        vector<int> nextROW(n+1, 0);

        for(int curr =n-1 ; curr>=0; curr--){
            for(int prev= n-1; prev>=-1; prev--){
                int include=0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include= 1 + nextROW[curr+1];
                }
                int exclude=  nextROW[prev+1];
                currROW[prev+1]=max(include,exclude);
            }
            nextROW=currROW;
        }
        return nextROW[0];
    }

    // we will include binary search in this to make TC=O(nlog(n)) from n^2 
    //Optimized solution
    int optimized(int n, vector<int>& nums){
        vector<int> ans;
        //first element to include karna hi hai 
        ans.push_back(nums[0]);

        for(int i=1;i<n;i++){
            // agar bada hua last element se to push
            if(nums[i] > ans.back())
                ans.push_back(nums[i]);
            else{
                //ans to already sorted hai
                // to ab vo index find karo ans me jiska element nums[i] se just bada ho OR find lower bound
                int index= lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                // replace it
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }


    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // //RECURTION
        // return solve(nums, 0, -1);

        // //MEMOIZATION
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        // return solveMem(nums, 0, -1, dp);

        //TABULATION
        // return solveTab(n, nums);

        // //Space Optimization
        // return solveSO(n, nums);

        //  OPTIMIZED
        return optimized(n, nums);
    }
};