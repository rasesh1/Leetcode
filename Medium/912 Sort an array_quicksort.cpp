class Solution {
private:
    void swap(vector<int>& nums, int i, int j)  {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
    
    int partition(vector<int>& nums, int low, int high)    {
        int i=low, j=low;
        int pivot = high;
        
        while(j < high)    {
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
    
    int partition_r(vector<int>& nums, int low, int high)   {
        int random = low + rand() % (high - low);
        swap(nums, random, high);
        int pivot = partition(nums, low, high);
        return pivot;
    }
    
    void quicksort(int low, int high, vector<int>& nums)    {
        if(high > low)  {
            int pivot = partition_r(nums, low, high);
            
            quicksort(low, pivot-1, nums);
            quicksort(pivot+1, high, nums);
        }
        return;
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(0, nums.size()-1, nums);
        return nums;
    }
};