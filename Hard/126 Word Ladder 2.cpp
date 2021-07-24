class Solution {
private:
    unordered_map<string, vector<string>> mp;
    unordered_map<string, int> visited;
    vector<vector<string>> ans;
    unordered_set<string> words_set;
    int destNode = -1;
        
    void buildGraph(string beginWord, string endWord)    {
        int len = beginWord.length();
        
        int level=0;
        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = level;
        
        q.push("");
        level++;
        
        while(!q.empty())   {
            string temp = q.front();
            string word = q.front();
            mp[word] = {};
            q.pop();
            
            if(word == endWord) destNode = 1;
            
            if(word == "")  {
                if(q.empty() || destNode != -1) return;
                
                level++;
                q.push("");
                continue;
            }
            
            for(int i=0; i<len; i++)    {
                char old = temp[i];

                for(char j='a'; j<='z'; j++)    {
                    temp[i] = j;
                    if(words_set.find(temp) != words_set.end()) {
                        
                        if(visited.find(temp) == visited.end() || visited[temp] == level)   {
                            mp[word].push_back(temp);
                            visited[temp] = level;
                            q.push(temp);
                        }
                    }
                }
                temp[i] = old;
            }
        }
        return;
    }
    
    void backtrack(string src, vector<string>& path, string endWord)    {
        if(src == endWord)  {
            ans.push_back(path);
            return;
        }
        
        vector<string> neighbours = mp[src];
        for(auto neigh : neighbours)    {
            path.push_back(neigh);
            backtrack(neigh, path, endWord);
            path.pop_back();
        }
        return;
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        for(auto s : wordList)
            words_set.insert(s);
        
        buildGraph(beginWord, endWord);
        
        if(destNode == -1) return ans;
        
        vector<string> path = {beginWord};
        backtrack(beginWord, path, endWord);
        return ans;
    }
};