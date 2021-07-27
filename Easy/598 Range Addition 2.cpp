class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int rows = ops.size();
        
        int minx = m;
        int miny = n;
        for(int i=0; i<rows; i++)   {
            int x = ops[i][0];
            int y = ops[i][1];
            
            if(x < minx) minx = x;
            if(y < miny) miny = y;
        }
        return minx*miny;
    }
};