class Solution {
private:
    unordered_map<int,char> mp;
    bool isLexSmaller(string s1, string s2) {
        if(s1 == s2) return true;
        
        int len1 = s1.length();
        for(int i=0; i<len1; i++)   {
            if(mp[s1[i]] < mp[s2[i]])
                return true;
            else if(mp[s1[i]] > mp[s2[i]])
                return false;
        }
        return s1.length() <= s2.length() ? true : false;
    }
    
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        for(int i=0; i<26; i++) {
            mp[order[i]] = i;
        }
            
        
        for(int i=0; i<words.size()-1; i++) {
            string s1 = words[i];
            string s2 = words[i+1];
            
            if(!isLexSmaller(s1,s2))
                return false;
        }
        return true;
    }
};