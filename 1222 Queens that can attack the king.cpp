class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        set<vector<int>> s;
        vector<vector<int>> ans;
        
        int numQueens = queens.size();
        if(numQueens == 0) return ans;
        
        for(int i=0; i<numQueens; i++)  {
            s.insert({queens[i][0], queens[i][1]});
        }
        
        vector<int> xs = {-1,0,1,1,1,0,-1,-1};
        vector<int> ys = {-1,-1,-1,0,1,1,1,0};
        
        for(int i=0; i<8; i++)  {
            int x = king[0];
            int y = king[1];
            
            while(x>=0 && x<8 && y>=0 && y<8)   {
                if(s.find({x,y}) == s.end())   {
                    x = x + xs[i];
                    y = y + ys[i];
                }
                else    {
                    ans.push_back({x,y});
                    break;
                }
            }
        }
        return ans;
    }
};