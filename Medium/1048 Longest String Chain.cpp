bool cmp(const std::string& a, const std::string& b)
{
    return (a.size() < b.size());
}

class Solution {
private:
    bool isWordPredecessor(string& word1, string& word2)  {
        int len1 = word1.length();
        int len2 = word2.length();
        
        if(len2-len1 != 1) return false;
        
        int j=0, i=0;
        while(i<len1 && j<len2)   {
            if(word1[i] == word2[j])
                i++;
            j++;
        }
        return i==len1 && j>=len2-1;
    }
    
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), cmp);
        int maxi = 1;
        
        vector<int> A(n,0);
        A[0] = 1;
        
        for(int i=1; i<n; i++)  {
            A[i] = 1;
            for(int j=0; j<i; j++)  {
                if(isWordPredecessor(words[j], words[i]))   {
                    A[i] = max(A[i], 1+A[j]);
                }
            }
            maxi = max(maxi, A[i]);
        }
        return maxi;
    }
};