class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> A(n,INT_MAX);
        A[0]=0;
        int maxIndexReached = 0;
        
        for(int i=0; i<n; i++)  {
            int val = nums[i];
            for(int j=maxIndexReached+1; j<=i+val && j<n; j++)
                A[j] = 1+A[i];
            maxIndexReached = max(maxIndexReached, i+val);
        }
        return A[n-1];
    }
};