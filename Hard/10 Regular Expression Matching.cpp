class Solution {
private:
    char preceding;
    vector<vector<int>> A;
    bool recurse(string s, string p, int i, int j)  {
        int len1 = s.length();
        int len2 = p.length();
        
        if(i < len1 && j >= len2) return false;
        
        else if(i >= len1)   {
            if(j >= len2) return true;
            else if(j+1 < len2 && p[j+1] == '*')
                return recurse(s, p, i, j+2);
            return false;
        }
        
        if(A[i][j] != -1) return A[i][j];
        
        if(j+1 < len2 && p[j+1] == '*') {
            
            if(s[i] == p[j] || p[j] == '.') {
                bool val1 = recurse(s, p, i, j+2);
                bool val2 = recurse(s, p, i+1, j);
                bool val3 = recurse(s, p, i+1, j+2);
                A[i][j] = val1 || val2 || val3;
            }
            else    {
                A[i][j] = recurse(s, p, i, j+2);
            }
        }
        
        else if(p[j] != '.')  {
            if(s[i] == p[j]) A[i][j] = recurse(s, p, i+1, j+1);
            else A[i][j] = 0;
        }
        
        else if(p[j] == '.')    {
            A[i][j] = recurse(s, p, i+1, j+1);
        }
        
        return A[i][j];
    }
    
public:
    bool isMatch(string s, string p) {
        int len1 = s.length();
        int len2 = p.length();
        
        A.resize(len1, vector<int>(len2, -1));
        A[0][0] = recurse(s, p, 0, 0);
        return A[0][0];
    }
};