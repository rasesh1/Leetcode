class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        set<pair<int,int>> points_hash;
        
        for(auto point : points)
            points_hash.insert(make_pair(point[0],point[1]));
        
        int minArea = 0;
        for(int i=0; i<n; i++)  {
            int x1 = points[i][0];
            int y1 = points[i][1];
            
            for(int j=i+1; j<n; j++)    {
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                if(x1 == x2 || y1 == y2) continue;
                if(points_hash.find(make_pair(x2,y1)) == points_hash.end()) continue;
                if(points_hash.find(make_pair(x1,y2)) == points_hash.end()) continue;
                
                int area = abs(x1-x2)*abs(y1-y2);
                if(minArea > 0)
                    minArea = min(area,minArea);
                else minArea = area;
                
            }
        }
        return minArea;
    }
};