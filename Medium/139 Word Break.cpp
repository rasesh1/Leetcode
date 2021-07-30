class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        int len = s.length();
        
        unordered_set<string> words;
        for(auto word : wordDict)   {
            words.insert(word);
        }
        
        int A[len+1];
        A[0] = 1;
        for(int i=1; i<=len; i++)    {
            A[i] = 0;
            for(int j=i-1; j>=0; j--)   {
                if(A[j] == 1 && words.find(s.substr(j, i-j)) != words.end() )   {
                    A[i] = 1;
                    break;
                }
            }
        }
        return A[len];
    }
};