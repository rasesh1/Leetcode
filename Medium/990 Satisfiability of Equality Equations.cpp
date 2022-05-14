class Solution {
private:
    vector<int> parent;
    vector<int> s;
    
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
        
        if(s[p1] < s[p2])   {
            parent[p1] = p2;
            s[p2] = s[p1] + s[p2];
            s[p1] = 0;
        }
        else    {
            parent[p2] = p1;
            s[p2] = s[p1] + s[p2];
            s[p2] = 0;
        }
        return;
    }
    
public:
    bool equationsPossible(vector<string>& equations) {
        for(int i=0; i<26; i++) {
            parent.push_back(i);
            s.push_back(1);
        }
        
        for(auto equation : equations)  {
            if(equation[1] == '=')  {
                int src = equation[0] - 'a';
                int dest = equation[3] - 'a';
                
                Union(src, dest);
            }
        }
        
        for(auto equation : equations)  {
            if(equation[1] == '!')  {
                int src = equation[0] - 'a';
                int dest = equation[3] - 'a';
                
                if(SameSet(src, dest)) return false;
            }
        }
        return true;
    }
};