class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        
        vector<vector<long long int>> A(len2, vector<long long int>(len1, 0));
        
        // First row
        if(s[0] == t[0]) A[0][0] = 1;
        for(int j=1; j<len1; j++)   {
            A[0][j] = A[0][j-1];
            if(t[0] == s[j]) A[0][j]++;
        }
        
        for(int i=1; i<len2; i++)   {
            for(int j=i; j<=len1-len2+i; j++)   {
                
                if(s[j] == t[i])    {
                    A[i][j] = A[i-1][j-1] + A[i][j-1];
                }
                else    {
                    A[i][j] = A[i][j-1];
                }
            }
        }
        return A[len2-1][len1-1];
    }
};1