class Solution {
public:
    int solve(int n, vector<int> &days, vector<int> &cost, int index){
        if(index>=n){
            return 0;
        }
        // 1 day cost
        int option1=cost[0] + solve(n,days,cost,index+1);

        // cost for 7 days
        // check till where 7 day pass is covered
        int i;
        for(i=index; i<n && days[i] < days[index]+7; i++);
        
        int option2=cost[1] + solve(n,days,cost,i);

        // cost for 30 days
        // check till where 7 day pass is covered
        for(i=index; i<n && days[i] < days[index]+30; i++);
        
        int option3=cost[2] + solve(n,days,cost,i);

        return min(option1, min(option2, option3));
    }


    int solvemem(int n, vector<int> &days, vector<int> &cost, int index,vector<int> &dp){
        if(index>=n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        // 1 day cost
        int option1=cost[0] + solvemem(n,days,cost,index+1,dp);

        // cost for 7 days
        // check till where 7 day pass is covered
        int i;
        for(i=index; i<n && days[i] < days[index]+7; i++);
        
        int option2=cost[1] + solvemem(n,days,cost,i,dp);

        // cost for 30 days
        // check till where 7 day pass is covered
        for(i=index; i<n && days[i] < days[index]+30; i++);
        
        int option3=cost[2] + solvemem(n,days,cost,i,dp);

        dp[n]= min(option1, min(option2, option3));
        return dp[n];
    }


    int solvetab(int n, vector<int> &days, vector<int> &cost){
        vector<int> dp(n+1, 0);
        dp[n]=0;
        for(int index=n-1; index>=0; index--){
            // 1 day cost
            int option1=cost[0] + dp[index+1];

            // cost for 7 days
            // check till where 7 day pass is covered
            int i;
            for(i=index; i<n && days[i] < days[index]+7; i++);
            
            int option2=cost[1] + dp[i];

            // cost for 30 days
            // check till where 7 day pass is covered
            for(i=index; i<n && days[i] < days[index]+30; i++);
            
            int option3=cost[2] + dp[i];

            dp[index]= min(option1, min(option2, option3));
        }
        return dp[0];
    }

    int spaceOpt(vector<int> &days, vector<int> &cost){
        int ans=0;

        queue<pair<int,int>> month;
        queue<pair<int,int>> week;

        for(int day:days){
            //agar koi element 30 din se bahar ka hai to hata do OR remove expired dates
            while(!month.empty() && month.front().first +30 <= day)
                month.pop();
            while(!week.empty() && week.front().first +7 <= day)
                week.pop(); 
            
            // add current day and its cost in the queue
            month.push(make_pair(day, ans+cost[2]));
            week.push(make_pair(day, ans+cost[1]));

            ans=min(ans+cost[0], min(month.front().second, week.front().second));
        }
        return ans;
    }


    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();

        // return solve(n,days,costs,0);

        // vector<int> dp(n+1, -1);
        // return solvemem(n,days,costs,0,dp);

        // return solvetab(n,days,costs);

        return spaceOpt(days,costs);
    }
};