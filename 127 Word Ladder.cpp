class Solution {
private:
    typedef vector<vector<int>> graph;
    int destNode = -1;
    
    int computeDistance(string s1, string s2)   {
        int len = s1.length();
        int dist=0;
        for(int i=0; i<len; i++)    {
            if(s1[i] != s2[i])
                dist++;
        }
        return dist;
    }
    
    graph buildGraph(string beginWord, string endWord, vector<string>& words)    {
        int numWords = words.size();
        
        graph g(numWords+1, vector<int>({}));
        
        for(int i=0; i<numWords; i++)   {
            if(computeDistance(beginWord, words[i]) == 1)    {
                g[numWords].push_back(i);
                g[i].push_back(numWords);
            }
        }
        
        for(int i=0; i<numWords; i++)   {
            
            if(words[i] == endWord)
                destNode = i;
                
            for(int j=i+1; j<numWords; j++) {
                if(computeDistance(words[i], words[j]) == 1)    {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        return g;
    }
    
    int bfs(graph g, int src, int dest, vector<int>& visited)   {
        queue<int> q;
        q.push(src);
        int dist = 0;
        visited[src] = dist;
        q.push(-1);
        dist++;
        
        while(!q.empty())   {
            int front = q.front();
            q.pop();
            
            if(front == -1)   {
                dist++;
                if(!q.empty())  {
                    q.push(-1);
                    continue;
                }
                else return 0;
            }
            
            vector<int> neighbours = g[front];
            for(auto neigh : neighbours)    {
                if(visited[neigh] == -1)    {
                    q.push(neigh);
                    visited[neigh] = dist;
                    
                    if(neigh == destNode) return dist+1;
                }
            }
        }
        return 0;
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int numWords = wordList.size();
        
        graph g = buildGraph(beginWord, endWord, wordList);
        if(destNode == -1) return 0;
        
        vector<int> visited(numWords+1, -1);
        return bfs(g, numWords, destNode, visited);
    }
};