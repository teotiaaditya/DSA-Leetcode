class Solution {
public:
    int memoization(vector<int>& nums, int target,vector<int> &dp){
        if(target==0)
            return 1;
        if(target<1)
            return 0;
        if(dp[target]!=-1)
            return dp[target];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans +=memoization(nums,target-nums[i],dp);
        }
        dp[target]=ans;
        return dp[target];
    }
    // int tabulation(vector<int>& nums, int target){
    //     vector<int> dp(target+1,0);
    //     dp[0]=1;
        
    //     for(int i=1;i<=target;i++){
    //         for(int j=0;j<nums.size();j++){
    //             if(i-nums[j] >=0)
    //                 dp[i] +=dp[i-nums[j]];
    //         }
    //     }
    //     return dp[target];
    // }.
    int tabulation(vector<int>& nums, int target) {
    vector<long long> dp(target + 1, 0); // Use long long to handle large values
    dp[0] = 1; // Base case: one way to make a sum of 0.
    
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < nums.size(); j++) { // Use int j for the inner loop
            if (i - nums[j] >= 0) {
                dp[i] += dp[i - nums[j]];
                if (dp[i] > INT_MAX) { // Avoid overflow if the result exceeds the 32-bit limit
                    dp[i] = INT_MAX;
                }
            }
        }
    }
    return dp[target] > INT_MAX ? INT_MAX : dp[target]; // Ensure result is within 32-bit integer limits
}
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return memoization(nums,target,dp);

        // return tabulation(nums,target);
    }
};