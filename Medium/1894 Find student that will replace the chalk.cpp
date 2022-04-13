class Solution {
private:
    int findIndexJustLarger(vector<long int>& chalk, int k)  {
        int n = chalk.size();
        int left=0, right=n-1;
        
        while(left <= right)    {
            if(left == right) return left;
            
            int mid = left + (right-left)/2;
            if(chalk[mid] <= k) left = mid+1;
            else right = mid;
        }
        return left;
    }
    
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long int> sum;
        long int currSum = 0;
        for(auto c : chalk) {
            currSum = currSum + c;
            sum.push_back(currSum);
        }
        
        long int totalSum = sum[n-1];
        k = k%totalSum;
        
        // Find index just larger than k
        return findIndexJustLarger(sum,k);
    }
};