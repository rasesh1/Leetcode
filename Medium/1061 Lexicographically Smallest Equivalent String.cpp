class Solution {

private:
    vector<int> parent;
    
    int Find(int i) {
        if(i == parent[i]) return i;
        
        int p = Find(parent[i]);
        parent[i] = p;
        return p;
    }
    
    bool SameSet(int i, int j)  {
        int p1 = Find(i);
        int p2 = Find(j);
        
        return p1 == p2;
    }
    
    void Union(int i, int j)    {
        int p1 = Find(i);
        int p2 = Find(j);
        
        if(p1 == p2) return;
        
        if(p1 > p2)   {
            parent[p1] = p2;
        }
        else    {
            parent[p2] = p1;
        }
        return;
    }
    
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string ans = baseStr;
        
        for(int i=0; i<26; i++) {
            parent.push_back(i);
        }
        
        for(int i=0; i<s1.length(); i++)    {
            int char1 = s1[i]-'a';
            int char2 = s2[i]-'a';
            
            Union(char1, char2);
        }
        
        for(int i=0; i<baseStr.length(); i++)   {
            char c = Find(baseStr[i]-'a') + 'a';
            ans[i] = c;
        }
        return ans;
    }
};