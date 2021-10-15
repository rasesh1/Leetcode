class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    
    UnionFind(int n)    {
        for(int i=0; i<n; i++)  {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    int Find(int x) {
        if(x == parent[x]) return x;
        
        int px = Find(parent[x]);
        parent[x] = px;
        return px;
    }
    
    bool Union(int x, int y)    {
        int px = Find(x);
        int py = Find(y);
        
        if(px == py) return false;
        
        if(size[px] < size[py]) {
            parent[px] = py;
            size[py] = size[px]+size[py];
            size[px]=0;
        }
        else    {
            parent[py] = px;
            size[px] = size[px]+size[py];
            size[py]=0;
        }
        return true;
    }
    
};

class Solution {
private:
    //this function will be used to sort a string alphabetically using bubble sort
    string bsort(string str) {
        int l = str.length() -1;
        while (l > 0) {
            for (int i = 0; i < l; i++) {
                if (str[i] > str[i+1]) swap(str[i], str[i+1]);
            }
            l--;
        }
        return str;
    }
    
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        
        UnionFind* obj = new UnionFind(n);
        
        for(auto pair : pairs)  {
            obj->Union(pair[0], pair[1]);
        }
        
        // Make parent as root
        for(int i=0; i<n; i++)  {
            obj->parent[i] = obj->Find(obj->parent[i]);
        }
        
        // Form groups of strings
        unordered_map<int,priority_queue<char,vector<char>,greater<char>>> groups;
        for(int i=0; i<n; i++)  {
            int p = obj->parent[i];            
            groups[p].push(s[i]);
        }
        
        // Form answer
        string res = "";
        for(int i=0; i<n; i++)  {
            int parent = obj->parent[i];
            char c = groups[parent].top();
            groups[parent].pop();
            
            res.push_back(c);
        }
        return res;
    }
};