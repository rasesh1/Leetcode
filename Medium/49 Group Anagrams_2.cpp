typedef vector<vector<string>> vvs;

class Solution {
private:
    vvs ans;
    unordered_map<string,int> mp;
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        if(n == 1) return {strs};
        int index=0;
        
        for(int i=0; i<n; i++)  {
            string s = strs[i];
            string orig_s = s;
            sort(s.begin(), s.end());
            int currIndex=0;
            
            if(mp.find(s) == mp.end()) {
                mp[s] = index;
                currIndex = index;
                ans.push_back({});
                index++;
            }
            else currIndex = mp[s];
            ans[currIndex].push_back(orig_s);
        }
        return ans;
    }
};