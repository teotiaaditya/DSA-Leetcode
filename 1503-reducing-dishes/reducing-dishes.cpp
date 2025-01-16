class Solution {
public:
    int solve(vector<int>& satisfaction, int index, int time){
        if(index == satisfaction.size()){
            return 0;
        }
        int include= satisfaction[index] * (time) + solve(satisfaction, index+1, time+1);
        int exclude= 0 + solve(satisfaction, index+1, time);
        // int ans=max(include, exclude);
        return max(include, exclude);

    }
    int solveMem(vector<int>& satisfaction, int index, int time,vector<vector<int>> &dp){
        if(index == satisfaction.size()){
            return 0;
        }
        if(dp[index][time] != -1){
            return dp[index][time];
        }
        int include= satisfaction[index] * (time) + solveMem(satisfaction, index+1, time+1, dp);
        int exclude= 0 + solveMem(satisfaction, index+1, time, dp);
        dp[index][time]=max(include, exclude);
        return dp[index][time];

    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(satisfaction.size()+1, vector<int> (satisfaction.size()+1, -1));
        return solveMem(satisfaction, 0, 1, dp);
    }
};