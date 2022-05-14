#include <algorithm>

typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef map<string,int> msi;
typedef map<string,vector<string>> msvi;
typedef map<string,bool> msb;

class Solution {
private:
    unordered_set<string> supplies_set;
    bool dfs(msvi& graph, string recipe, msi& visited, msb& isPossible)  {
        if(supplies_set.find(recipe) != supplies_set.end()) {
            return true;
        }
        
        if(isPossible.find(recipe) != isPossible.end())
            return isPossible[recipe];
        
        bool possible;
        
        vector<string> nbrs = graph[recipe];
        if(nbrs.size() == 0) return false;
        
        for(auto nbr : nbrs)    {
            if(visited.find(nbr) != visited.end() && visited[nbr])    {
                isPossible[recipe] = false;
                return false;
            }
            
            visited[nbr] = 1;
            bool canIt = dfs(graph, nbr, visited, isPossible);
            if(!canIt)  {
                isPossible[recipe] = false;
                return false;
            }
            visited[nbr] = 0;
        }
        
        isPossible[recipe] = true;
        return true;
    }
    
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        msvi graph;
        
        for(auto s : supplies)  {
            supplies_set.insert(s);
            graph[s] = {};
        }
        
        int n = recipes.size();
        for(int i=0; i<n; i++)  {
            string recipe = recipes[i];
            vector<string> ingredient = ingredients[i];
            
            if(graph.find(recipe) == graph.end()) graph[recipe] = {};
            
            for(auto ing : ingredient)  {
                if(graph.find(ing) == graph.end()) graph[ing] = {};
                
                graph[recipe].push_back(ing);
            }
        }
        
        vector<string> ans;
        msb isPossible;
        for(int i=0; i<n; i++)  {
            string recipe = recipes[i];
            
            bool canBeMade;
            if(isPossible.find(recipe) == isPossible.end()) {
                msi visited;
                canBeMade = dfs(graph, recipe, visited, isPossible);
                isPossible[recipe] = canBeMade;
            }
            else
                canBeMade = isPossible[recipe];
            
            if(canBeMade) ans.push_back(recipe);
        }
        return ans;
    }
};