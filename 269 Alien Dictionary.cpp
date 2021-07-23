class Solution {
private:
    unordered_map<char, unordered_set<char>> mp;
    unordered_map<char, int> indegrees;
    bool possible = true;
    
    void buildGraph(vector<string>& words) {
        
        int numWords = words.size();
        
        for(int i=0; i<numWords-1; i++) {
            string s1 = words[i];
            string s2 = words[i+1];
            
            int smallerLen = s1.length() < s2.length() ? s1.length() : s2.length();
            bool found = false;
            for(int j=0; j<smallerLen; j++) {
                char c1 = s1[j];
                char c2 = s2[j];
                
                if(c1 != c2)    {
                    if(mp[c1].find(c2) == mp[c1].end())   {
                        mp[c1].insert(c2);
                        indegrees[c2]++;
                        cout << c1 << " " << c2 << endl;
                    }
                    found = true;
                    break;
                }
            }
            if(s1.length() > s2.length() && found==false)
                possible = false;
        }
        return;
    }
    
public:
    string alienOrder(vector<string>& words) {
        int numWords = words.size();
        
        string ans = "";
        
        for(int i=0; i<words.size(); i++)   {
            for(int j=0; j<words[i].length(); j++)  {
                
                char c = words[i][j];
                if(mp.find(c) == mp.end())  {
                    mp[c] = {};
                    indegrees[c] = 0;
                }
            }
        }
        
        buildGraph(words);
        
        if(!possible) return "";
        
        // Topological sort
        queue<int> q;
        int count = 0;
        unordered_map<char,int>::iterator iter;
        for(iter=indegrees.begin(); iter != indegrees.end(); ++iter) {
            if(iter->second == 0)   {
                q.push(iter->first);
                count++;
            }  
        }
    
        while(!q.empty())   {
            char top = q.front();
            q.pop();
            ans = ans + top;
            
            unordered_set<char>::iterator iter_set;
            for(iter_set=mp[top].begin(); iter_set != mp[top].end(); ++iter_set)  {
                if(--indegrees[*iter_set] == 0)  {
                    q.push(*iter_set);
                    count++;
                }
            }
        }
        
        return count < indegrees.size() ? "" : ans;
    }
};