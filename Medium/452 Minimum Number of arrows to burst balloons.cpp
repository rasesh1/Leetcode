static bool cmp(const vector<int>& v1, const vector<int>& v2)   {
    return v1[1] < v2[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int n = points.size();
        
        int count = 1;
        int lastEnding = points[0][1];
        
        for(int i=1; i<n; i++)  {
            if(lastEnding < points[i][0])  {
                lastEnding = points[i][1];
                count++;
            }
        }
        return count;
    }
};