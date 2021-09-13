class Solution {
private:
    static bool cmp(vector<int>& v1, vector<int>& v2)   {
        if(v1[1] == v2[1])
            return v1[0]<v2[0];
        return v1[1]<v2[1];
    }
    
    bool AreOverlapping(vector<int>& v1, vector<int>& v2)   {
        if(v1[1] > v2[0]) return true;
        return false;
    }
    
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        
        int count = 0;
        vector<int> prev = intervals[0];
        for(int i=1; i<n; i++)   {
            bool overlap = prev[1] > intervals[i][0]; // AreOverlapping(prev, intervals[i]);
            if(overlap) count++;
            else prev = intervals[i];
        }
        return count;
    }
};