class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.length();
        int len2 = p.length();
        
        vector<vector<int>> A(len2+1, vector<int>(len1+1));
        A[0][0] = 1;
        
        // First Row => false
        for(int i=1; i<=len1; i++) A[0][i] = 0;
        
        // First Column
        for(int i=1; i<=len2; i++)  {
            if(p[i-1] == '*') A[i][0] = A[i-1][0];
            else A[i][0] = 0;
        }
        
        for(int i=1; i<=len2; i++)  {
            for(int j=1; j<=len1; j++)  {
                
                if(p[i-1] == '*')   {
                    A[i][j]  = A[i][j-1] || A[i-1][j];
                }
                else  if(p[i-1] == '?' || p[i-1] == s[j-1])  {
                    A[i][j] = A[i-1][j-1];
                }
                else A[i][j] = false;
            }
        }
        return A[len2][len1];
    }
};