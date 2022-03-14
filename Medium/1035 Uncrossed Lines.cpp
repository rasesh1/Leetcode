class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        vector<vector<int>> A(len1+1, vector<int>(len2+1,0));
        
        int maxLen = 0;
        for(int i=0; i<len1; i++)   {
            for(int j=0; j<len2; j++)   {
                
                if(nums1[i] == nums2[j])    {
                    A[i+1][j+1] = 1 + A[i][j];
                    maxLen = max(maxLen, A[i+1][j+1]);
                }
                    
                else    {
                    A[i+1][j+1] = max(A[i+1][j], A[i][j+1]);
                }
                
            }
        }
        return maxLen;
    }
};