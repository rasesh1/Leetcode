typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Point {
public:
    int node;
    int color;
    int dist;
    
    Point(int node, int color, int dist)    {
        this->node = node;
        this->color = color;
        this->dist = dist;
    }
};

class Solution {
private:
    void createGraph(vvi& redGraph, vvi& blueGraph, vvi& redEdges, vvi& blueEdges, int n)   {
        for(auto edge : redEdges)   {
            int src = edge[0];
            int dest = edge[1];
            
            redGraph[src].push_back(dest);
        }
        
        for(auto edge : blueEdges)   {
            int src = edge[0];
            int dest = edge[1];
            
            blueGraph[src].push_back(dest);
        }
        return;
    }
    
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> redGraph(n);
        vector<vector<int>> blueGraph(n);
        
        createGraph(redGraph, blueGraph, redEdges, blueEdges, n);
        vector<int> redVisited(n,0);
        vector<int> blueVisited(n,0);
        
        vector<int> ans(n,-1);
        
        queue<Point*> q;
        q.push(new Point(0,1,0));
        q.push(new Point(0,2,0));
        
        redVisited[0] = 1;
        blueVisited[0] = 1;
        ans[0] = 0;
        
        while(!q.empty())   {
            Point* top = q.front(); q.pop();
            int node = top->node;
            int color = top->color;
            int dist = top->dist;
            
            if(ans[node] == -1) ans[node] = dist;
            else ans[node] = min(ans[node], dist);
            
            if(color == 1)  {
                for(auto nbr : blueGraph[node])   {
                    if(!blueVisited[nbr])   {
                        blueVisited[nbr] = 1;
                        q.push(new Point(nbr, 2, dist+1));
                    }
                }
            }
            
            else    {
                for(auto nbr : redGraph[node])   {
                    if(!redVisited[nbr])   {
                        redVisited[nbr] = 1;
                        q.push(new Point(nbr, 1, dist+1));
                    }
                }
            }
        }
        return ans;
    }
};