class Solution {
public:
    int threeSumClosest(vector<int>& A, int target) {
        int len = A.size();
        int closest = INT_MAX;
        int closestSum = INT_MAX;
        
        sort(A.begin(), A.end());
        for(int i=0; i<len; i++)    {
            int j=i+1, k=len-1;
            while(j < k)    {
                int sum = A[i] + A[j] + A[k];
                if(abs(sum-target) < closest)   {
                    closest = abs(sum-target);
                    closestSum = sum;
                }
                
                if(A[i] + A[j] + A[k] > target)
                    k--;
                else if(A[i]+A[j]+A[k] < target)
                    j++;
                else return A[i]+A[j]+A[k];
            }
        }
        return closestSum;
    }
};