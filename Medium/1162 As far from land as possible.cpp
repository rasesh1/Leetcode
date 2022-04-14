typedef vector<vector<int>> vvi;
typedef pair<int,int> pi;

class Point {
public:
    int x;
    int y;
    int dist;
    
    Point(int r,int c, int d)   {
        x = r;
        y = c;
        dist = d;
        return;
    }
};

class Solution {
private:
    int rows, cols;
public:
    int maxDistance(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        vvi visited(rows, vector<int>(cols,0));
        int maxDist = -1;
        
        queue<Point*> q;

        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                if(grid[i][j] == 1) {
                    q.push(new Point(i,j,0));
                    visited[i][j] = 1;
                }
            }
        }

        while(!q.empty())   {
            Point* top = q.front();
            q.pop();

            int x = top->x;
            int y = top->y;
            int dist = top->dist;

            vector<int> hor = {-1,0,1,0};
            vector<int> ver = {0,1,0,-1};
            for(int k=0; k<4; k++)  {
                int r = x+hor[k];
                int c = y+ver[k];

                if(r<0 || c<0 || r>=rows || c>=cols || visited[r][c]) continue;
                visited[r][c] = 1;
                q.push(new Point(r,c,dist+1));
                maxDist = dist+1;
            }
        }
        return maxDist;
    }
};