class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int len1 = sentence1.size();
        int len2 = sentence2.size();
        
        if(len1 != len2) return false;
        
        unordered_map<string,unordered_set<string>> mp;
        
        for(auto words : similarPairs)  {
            string w1 = words[0];
            string w2 = words[1];
            
            if(mp.find(w1) == mp.end()) {
                mp[w1] = {};
            }
                
            
            mp[w1].insert(w2);
            
            if(mp.find(w2) == mp.end())
                mp[w2] = {};
            
            mp[w2].insert(w1);
        }
        
        for(int i=0; i<len1; i++)   {
            string s1 = sentence1[i];
            string s2 = sentence2[i];
            
            if( (mp.find(s1) != mp.end() && mp[s1].find(s2) != mp[s1].end()) || s1 == s2)
                continue;
            else return false;
        }
        return true;
    }
};