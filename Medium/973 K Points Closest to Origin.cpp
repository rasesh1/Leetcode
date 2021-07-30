typedef pair<double,int> pi;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pi> pq;
        
        for(int i=0; i<points.size(); i++)  {
            int x = points[i][0];
            int y = points[i][1];
            
            double dist = pow( (x*x+y*y),0.5 );
            
            if(pq.size() < k)  {
                pq.push(make_pair(dist,i));
                continue;
            }
            
            pi top = pq.top();
            if(top.first > dist)    {
                pq.pop();
                pq.push(make_pair(dist,i));
            }
        }
        
        // Popping one-by-one
        vector<vector<int>> ans;
        while(!pq.empty())  {
            pi top = pq.top();
            pq.pop();
            
            ans.push_back(points[top.second]);
        }
        
        return ans;
    }
};