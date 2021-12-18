class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        
        if(len1 + len2 != len3) return false;
        
        vector<vector<int>> A(len1+1, vector<int>(len3+1,0));
        for(int i=0; i<len2; i++)   {
            if(s2[i] == s3[i]) A[0][i+1] = 1;
            else break;
        }
        A[0][0] = 1;
        
        for(int i=0; i<len3; i++)  {
            for(int j=0; j<i && j<len1; j++) {
                int remain = i - j - 1;
                
                if(s1[j] == s3[i] && A[j][i] == 1) A[j+1][i+1] = 1;
                if(remain < len2 && s2[remain] == s3[i] && A[j+1][i] == 1) A[j+1][i+1] = 1;
                
            }
            if(i<len1 && s1[i] == s3[i] && A[i][i] == 1) A[i+1][i+1] = 1;
        }
        
        return A[len1][len3];
    }
};