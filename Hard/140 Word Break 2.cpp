typedef unordered_map<int, vector<int>> mvi;
typedef vector<int> vi;
typedef vector<string> vs;

class Solution {
private:
    vector<string> ans;
    unordered_map<int, vector<int>> mp;
    
    void backtrackUtil(int index, vs& wordDict, vector<int>& curr, string s)    {
        
        if(index == 0)  {
            string temp = "";
            if(curr.size() == 1)    {
                ans.push_back(s);
                return;
            }
            
            for(int i=0; i<curr.size()-1; i++)    {
                int x = curr[i];
                int y = curr[i+1];
                if(temp != "")
                    temp = s.substr(y, x-y) + " " + temp;
                else temp = s.substr(y, x-y);
            }
            ans.push_back(temp);
            return;
        }
        
        vector<int> indices = mp[index];
        for(auto ind : indices) {
            curr.push_back(ind);
            backtrackUtil(ind, wordDict, curr, s);
            curr.pop_back();
        }
        return;
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        int len = s.length();
        
        unordered_set<string> words;
        for(auto word : wordDict)
            words.insert(word);
        
        vector<int> A(len+1,0);
        A[0] = 1;
                
        for(int i=1; i<=len; i++)  {
            A[i] = 0;
            mp[i] = {};
            
            for(int j=i-1; j>=0; j--)   {
                if( A[j] == 1 && words.find(s.substr(j, i-j)) != words.end())    {
                    A[i] = 1;
                    mp[i].push_back(j);
                }
            }
        }
        vector<int> current = {len};
        backtrackUtil(len, wordDict, current, s);
        return ans;
    }
};