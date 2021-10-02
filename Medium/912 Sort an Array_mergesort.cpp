class Solution {
private:
    void swap(vector<int>& nums, int i, int j)  {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
    
    void merge(int low, int high,int mid, vector<int>& nums)    {
        int i=low, j=mid+1;
        vector<int> merged;
        
        while(i <= mid && j <= high)  {
            if(nums[i] <= nums[j])   {
                merged.push_back(nums[i]);
                i++;
            }
            else    {
                merged.push_back(nums[j]);
                j++;
            }
        }
        
        while(i > mid && j <= high) {
            merged.push_back(nums[j]);
            j++;
        }
        
        while(j >= high && i <= mid) {
            merged.push_back(nums[i]);
            i++;
        }
        
        i=0;
        for(auto n : merged)    {
            nums[low+i] = n;
            i++;
        }
        return;
    }
    
    void mergesort(int low, int high, vector<int>& nums)    {
        if(low < high)  {
            int mid = low + (high-low)/2;
            
            mergesort(low, mid, nums);
            mergesort(mid+1, high, nums);
            merge(low, high, mid, nums);
        }
        return;
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(0, nums.size()-1, nums);
        return nums;
    }
};