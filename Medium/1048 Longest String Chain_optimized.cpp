bool cmp(const std::string& a, const std::string& b)
{
    return (a.size() < b.size());
}

class Solution {
private:
    void dfs(unordered_map<string,int>& mp, unordered_set<string>& set, string& word, vector<string>& words)    {
        
        mp[word] = 1;
        for(int a=0; a<word.length(); a++)  {
            string newWord = word.substr(0,a) + word.substr(a+1,word.length()-a);
            if(set.find(newWord) == set.end()) continue;

            if(mp.find(newWord) == mp.end())    {
                dfs(mp, set, newWord, words);
            }
            mp[word] = max(mp[word], 1+mp[newWord]);
        }
        return;
    }
    
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int maxi = 1;
        
        unordered_set<string> set;
        for(auto word : words)  {
            set.insert(word);
        }
        
        unordered_map<string,int> mp;
        for(auto word : words)  {
            dfs(mp, set, word, words);
            maxi = max(maxi, mp[word]);
        }
        return maxi;
    }
};