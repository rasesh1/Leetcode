class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if(k > 26) return 0;
        int n = s.length();
        
        unordered_map<char,int> mp;
        int left = 0, right = 0;
        int ans = 0;
        
        while(left <= n-k && right < n) {
            char c = s[right];
            if(mp.find(c) == mp.end()) mp[c] = 0;
            mp[c]++;
            
            while(mp[c] > 1)    {
                mp[s[left]]--;
                left++;
            }
            
            if(right-left+1 == k)   {
                ans++;
                mp[s[left]]--;
                left++;
            }
            right++;
        }
        return ans;
    }
};