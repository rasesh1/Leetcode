typedef vector<vector<int>> graph;

class Solution {
private:
    graph buildGraph(int numCourses, graph& prerequisites, vector<int>& indegrees)  {
        graph g(numCourses);
        
        for(int i=0; i<prerequisites.size(); i++)   {
            int course1 = prerequisites[i][0];
            int course2 = prerequisites[i][1];
            
            g[course1].push_back(course2);
            indegrees[course2]++;
        }
        return g;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> indegrees(numCourses,0);
        int coursesTaken = 0;
        
        graph g = buildGraph(numCourses, prerequisites, indegrees);
        
        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegrees[i] == 0)   {
                q.push(i);
                coursesTaken++;
            }
        }
        
        while(!q.empty())   {
            int course = q.front(); q.pop();
            
            for(int i=0; i<g[course].size(); i++)    {
                int nextCourse = g[course][i];
                if(--indegrees[nextCourse] == 0) {
                    q.push(nextCourse);
                    coursesTaken++;
                }
            }
        }
        
        return coursesTaken == numCourses;
    }
};