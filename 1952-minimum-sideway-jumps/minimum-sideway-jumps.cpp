class Solution {
public:
    int solveMem(vector<int>& obstacles, int pos, int lane, vector<vector<int>> &dp){
        int n=obstacles.size()-1;
        if(pos == n)
            return 0;

        if(dp[lane][pos] != -1)
            return dp[lane][pos];

        //move in same lane
        if(obstacles[pos+1] != lane){
            return solveMem(obstacles, pos+1, lane, dp);
        }
        //change the lane
        else{
            int ans=INT_MAX;
            for(int i=1; i<=3;i++){
                // same lane na ho aur os lane me obstical na ho to change kar do
                if(i != lane && obstacles[pos] != i)
                    ans= min(ans, 1+ solveMem(obstacles, pos, i, dp));
            }
            dp[lane][pos]= ans;
            return dp[lane][pos];
        }
    }
    int solveTab(vector<int>& obstacles, int n){
        vector<vector<int>> dp(4, vector<int> (n, 1e9));
        // analize base case and work accordingly
        for(int i=0;i<dp.size();i++){
            dp[i][n-1]=0;
        }
        for(int pos=n-2; pos>=0; pos--){
            for(int lane=1; lane<=3; lane ++){
                //move in same lane
                if(obstacles[pos+1] != lane){
                    dp[lane][pos]= dp[lane][pos+1];
                }
                //change the lane
                else{
                    int ans=1e9;
                    for(int i=1; i<=3;i++){
                        // same lane na ho aur os lane me obstical na ho to change kar do
                        if(i != lane && obstacles[pos] != i)
                        // please understand the game of pos+1 in video
                            ans= min(ans, 1+ dp[i][pos+1]);
                    }
                    dp[lane][pos]= ans;
                }
            }
        }
        return min(dp[2][0], min(dp[1][0]+1 , dp[3][0]+1));
    }
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();

        // vector<vector<int>> dp(4, vector<int> (n, -1));
        // return solveMem(obstacles, 0, 2, dp);

        return solveTab(obstacles, n);
    }
};