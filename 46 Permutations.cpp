class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int,int> mp;
    void permuteUtil(vector<int>& A, int len, vector<int>& soFar, int remain) {
        if(remain == 0) {
            ans.push_back(soFar);
            return;
        }
        
        for(int i=0; i<len; i++)    {
            if(!mp[i])  {
                soFar.push_back(A[i]);
                mp[i] = 1;
                permuteUtil(A, len, soFar, remain-1);
                soFar.pop_back();
                mp[i] = 0;
            }
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& A) {
        int len = A.size();
        if(len == 1) return {{A[0]}};
        
        for(int i=0; i<len; i++)
            mp[i] = 0;
                
        vector<int> current;
        permuteUtil(A, len, current, len);
        return ans;
    }
};