class Solution	{ 
private:
    vector<int> parent;
    vector<int> s;
    int Find(int i)	{
        if( i == parent[i]) return i;

        int p = Find(parent[i]);
        parent[i] = p;
        return p;
    }

    bool SameSet(int i, int j)		{ 
        int p1 = Find(i);
        int p2 = Find(j);
        return p1 == p2;
    }

    void Union(int i, int j)	{
        int p1 = Find(i);
        int p2 = Find(j);

        if(s[p1] <= s[p2])	{ 
        parent[p1] = p2;
        s[p2] = s[p1]+s[p2];
        s[p1] = 0;
        }
        else	{ 
            parent[p2] = p1;
            s[p1] = s[p1]+s[p2];
            s[p2] = 0;
        }
    return;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)	{
        
        parent.push_back(0);
        s.push_back(1);
        
        for(int i=1; i<=edges.size(); i++)	{ 
            parent.push_back(i);
            s.push_back(1);
        }

        for(auto edge : edges)	{ 
            if(SameSet(edge[0], edge[1]))
                return edge;
            else    {
                Union(edge[0], edge[1]);
            }
        }
        return {};
    }
};
