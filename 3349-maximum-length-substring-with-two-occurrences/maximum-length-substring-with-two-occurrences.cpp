class Solution {
public:

    int maximumLengthSubstring(string s) {
        int n=s.length();
        vector<int> v(26,0);
        v[s[0] -'a']=1;
        int i=0;
        int j=1;
        int maxi=0;
        while(j<n){
            if(v[s[j] -'a'] +1 > 2){
                v[s[i] -'a']--;
                i++;
            }
            else{
                v[s[j] -'a']++;
                j++;
            }
            maxi=max(maxi, j-i);
        }
        return maxi;
    }
};