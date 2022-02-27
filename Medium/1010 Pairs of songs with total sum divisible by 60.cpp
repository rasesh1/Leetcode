class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        sort(time.begin(), time.end());
        
        unordered_map<int,int> mp;
        int ans = 0;
        
        for(int i=0; i<time.size(); i++)    {
            int t = time[i]%60;
            if(mp.find( (60-t)%60 ) == mp.end()) mp[(60-t)%60] = 0;
            
            if(mp.find(t) != mp.end()) ans = ans + mp[t];
            
            mp[(60-t)%60]++;
        }
        return ans;
    }
};