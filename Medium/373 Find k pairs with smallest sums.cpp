typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& A1, vector<int>& A2, int k) {
        int i=0, j=0;
        priority_queue<vi, vector<vi>, greater<vi>> pq;
        set<pair<int,int>> s;
        vvi ans;
        pq.push({A1[0]+A2[0], 0, 0});
        s.insert(make_pair(0,0));

        while(!pq.empty() && k>0)	{
            vi top = pq.top(); pq.pop();
            ans.push_back({ A1[top[1]], A2[top[2]]});
            int x = top[1];
            int y = top[2];

            if(x+1 < A1.size() && s.find(make_pair(x+1,y)) == s.end())  {
                pq.push({A1[x+1]+A2[y], x+1, y});
                s.insert(make_pair(x+1, y));
            }
                
            if(y+1 < A2.size() && s.find(make_pair(x,y+1)) == s.end())  {
                pq.push({A1[x]+A2[y+1], x, y+1});
                s.insert(make_pair(x,y+1));
            } 
            k--;

        }
        return ans;
    }
};