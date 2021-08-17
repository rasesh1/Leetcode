class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return true;
        
        int A[n][n];
        // Base Cases
        A[n-1][n-1] = nums[n-1];
        for(int i=0; i<n-1; i++)  {
            A[i][i] = nums[i];
            A[i][i+1] = max(nums[i], nums[i+1]);
        }
        
        for(int delta=2; delta<n; delta++)  {
            for(int i=0; i+delta<n; i++)    {
                int x = i;
                int y = i+delta;
                
                int num1 = min(A[x][y-2], A[x+1][y-1]) + nums[y];
                int num2 = min(A[x+2][y], A[x+1][y-1]) + nums[x];
                
                A[x][y] = max(num1,num2);
            }
        }
        
        int sum=0;
        for(auto num : nums)
            sum = num + sum;
        
        return sum-A[0][n-1] > A[0][n-1] ? false : true;
    }
};