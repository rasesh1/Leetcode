class Solution {
private:
    bool isContained(map<char,int>& S, map<char,int>& T)  {
        
        map<char,int>::iterator iter;
        for(iter=T.begin(); iter!=T.end(); ++iter) {
            char i = iter->first;
            int freq = iter->second;
            
            if(S.find(i) == S.end() || S[i] < freq) return false;
        }
        return true;
    }
    
public:
    string minWindow(string s, string t) {
        
        if(t.length() == 0) return "";
        
        map<char,int> T;
        map<char,int> S;
        
        // Preprocess t
        for(auto i : t) {
            if(T.find(i) == T.end())
                T[i]=0;
            T[i]++;
        }
        
        // Remove unnecassary characters from s
        vector<pair<int,char>> s1;
        for(int i=0; i<s.length(); i++) {
            char c = s[i];
            if(T.find(c) != T.end())    {
                s1.push_back(make_pair(i, c));
            }
        }

        int left=0, right=0;
        string ans = "";
        while(right < s1.size())  {
            
            // Move right pointer
            while(right < s1.size())   {
                char i = s1[right].second;
                
                if(S.find(i) == S.end())
                    S[i]=0;
                S[i]++;
                
                if(isContained(S,T))  {
                    if(ans.length() == 0 || ans.length() > s1[right].first-s1[left].first+1) {
                        ans = s.substr(s1[left].first, s1[right].first-s1[left].first+1);
                    }
                    break;
                }
                right++;
            }
                        
            // Move left pointer
            while(left <= right)   {
                if(left == right){
                    if(s.substr(s1[left].first, 1) == t){
                        ans = s.substr(s1[left].first, s1[right].first-s1[left].first+1);
                        return ans;
                    }
                }
                
                char c = s1[left].second;
                S[c]--;
                if(S[c] == 0)
                    S.erase(c);
                
                left++;
                if(isContained(S,T))    {
                    if(ans.length() == 0 || ans.length() > s1[right].first-s1[left].first+1) {
                        ans = s.substr(s1[left].first, s1[right].first-s1[left].first+1);
                    }
                }
                else    {
                    right++;
                    break;
                }
            }
        }
        return ans;
    }
};