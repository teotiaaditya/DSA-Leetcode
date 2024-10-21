class Solution {
public:
int recurtion(vector<int> &nums, int i){
    if(i<0)
        return 0;
    if(i==0)
        return nums[0];
    
    int include=recurtion(nums, i-2) + nums[i];
    int exclude= recurtion(nums, i-1)+0;

    return max(include, exclude);
}
int memoisation(vector<int> &nums, int i,vector<int> &dp){
    if(i<0)
        return 0;
    if(i==0)
        return nums[0];
    if(dp[i] != -1)
        return dp[i];

    int include=memoisation(nums, i-2, dp) + nums[i];
    int exclude= memoisation(nums, i-1, dp)+0;

    dp[i]= max(include, exclude);
    return dp[i];
}
int tabulation(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];

    for(int i=1;i<n;i++){
        int include= dp[i-2] + nums[i];
        int exclude= dp[i-1]+0;
        dp[i] = max(include, exclude);
    }
    return dp[n-1];
}
int spaceOptimization(vector<int> &nums){
    int n=nums.size();
    
    int prev2=0;
    int prev1=nums[0];

    for(int i=1;i<n;i++){
        int include= prev2 + nums[i];
        int exclude= prev1 +0;
        int ans = max(include, exclude);

        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
    int rob(vector<int>& nums) {
        int n=nums.size();
    // return recurtion(nums,n-1);

    // // MEMOISATION
    // vector<int> dp(n+1,-1);
    // return memoisation(nums,n-1,dp);

    // return tabulation(nums);

    return spaceOptimization(nums);
    }
};