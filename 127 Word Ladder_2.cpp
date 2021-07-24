#include<map>
#include<string>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
private:
    int destNode = -1;
    unordered_map<string, vector<string>> mp;
    
    void buildGraph(string beginWord, string endWord, vector<string>& words)    {
        int numWords = words.size();
        int wordLen = beginWord.length();
        
        string temp = beginWord;
        for(int j=0; j<wordLen; j++)    {
            temp[j] = '*';
            if(mp.find(temp) == mp.end())
                mp[temp] = {};
            mp[temp].push_back(beginWord);
            temp[j] = beginWord[j];
        }
        
        for(int i=0; i<numWords; i++)   {
            
            if(words[i] == endWord)
                destNode = i;
                
            string temp = words[i];
            for(int j=0; j<wordLen; j++) {
                temp[j] = '*';
                if(mp.find(temp) == mp.end())
                    mp[temp] = {};
                mp[temp].push_back(words[i]);
                temp[j] = words[i][j];
            }
        }
        return;
    }
    
    int bfs(vector<string>& words, string beginWord, string endWord, unordered_map<string,int>& visited)   {
        
        queue<string> q;
        q.push(beginWord);
        int dist = 0;
        visited[beginWord] = dist;
        q.push("");
        dist++;
        
        while(!q.empty())   {
            string front = q.front();
            q.pop();
            
            if(front == "")   {
                dist++;
                if(!q.empty())  {
                    q.push("");
                    continue;
                }
                else return 0;
            }
            
            string temp = front;
            for(int j=0; j<temp.length(); j++)  {
                temp[j] = '*';
                vector<string> ws = mp[temp];
                for(auto w : ws)    {
                    if(visited.find(w) == visited.end())    {
                        visited[w] = dist;
                        q.push(w);
                        
                        if(w == endWord) return dist+1;
                    }
                }
                temp[j] = front[j];
            }
        }
        return 0;
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int numWords = wordList.size();
        
        buildGraph(beginWord, endWord, wordList);
        if(destNode == -1) return 0;
        
        unordered_map<string,int> visited;
        return bfs(wordList, beginWord, endWord, visited);
    }
};