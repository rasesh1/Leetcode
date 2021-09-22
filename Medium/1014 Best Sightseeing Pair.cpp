class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        
        int maxVal = 0;
        int prevVal = values[0];
        
        for(int i=1; i<n; i++)  {
            maxVal = max(maxVal, values[i]+prevVal-1);
            prevVal = max(prevVal-1, values[i]);
        }
        return maxVal;
    }
};