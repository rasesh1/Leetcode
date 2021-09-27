class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        if(n == 1) return s;
        int A[n][n];
        A[n-1][n-1] = 1;
        
        int maxLen = 1;
        int begin=0;
        for(int i=0; i<n-1; i++)  {
            A[i][i] = 1;
            if(s[i] == s[i+1]) {
                A[i][i+1] = 1;
                maxLen = 2;
                begin = i;
            }
            else A[i][i+1] = 0;
        }
        
        for(int delta=2; delta<n; delta++)  {
            for(int i=0; i+delta<n; i++)    {
                
                A[i][i+delta] = 0;
                if(s[i] == s[i+delta] && A[i+1][i+delta-1] == 1)  {
                    A[i][i+delta] = 1;
                    if(maxLen < delta+1)  {
                        maxLen = delta+1;
                        begin = i;
                    }
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};