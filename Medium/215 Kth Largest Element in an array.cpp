class Solution {
private:
    void swap(vector<int>& nums, int i, int j)  {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
    
    int partition(vector<int>& nums, int low, int high)   {
        int i = low, j = low;
        int pivot = high;
        
        while(j < high) {
            int num1 = nums[j];
            int num2 = nums[pivot];
            
            if(num1 <= num2)    {
                swap(nums, i, j);
                i++;
            }
            
            j++;
        }
        swap(nums, pivot, i);
        return i;
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0, high = n-1;
        
        while(low <= high)   {
            int index = partition(nums, low, high);
            if(index == n-k) return nums[index];
            
            if(index > n-k) high = index-1;
            else low = index+1;
        }
        return -1;
    }
};