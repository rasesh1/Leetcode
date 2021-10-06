typedef pair<int,int> pi;

class Solution {
private:
    unordered_map<int,int> calcFreqs(vector<int>& nums)   {
        unordered_map<int,int> mp;
        
        for(auto n : nums)  {
            if(mp.find(n) == mp.end()) mp[n]=0;
            mp[n]++;
        }
        return mp;
    }
    
    void swap(vector<int>& nums, int i, int j)  {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
    
    int partition(unordered_map<int,int>& mp, vector<int>& A, int low, int high)    {
        int i = low, j=low;
        int pivot = A[high];
        
        while(j < high)   {
            int num = A[j];
            
            if(mp[num] <= mp[pivot]) {
                swap(A, i, j);
                i++;
            }
            j++;
        }
        swap(A, i, high);
        return i;
    }
    
    void quickselect(vector<int>& A, int low, int high, int k, unordered_map<int,int>& mp) {
        
        if(low < high)  {
            int pivot = partition(mp, A, low, high);
            
            if(pivot == k) return;
            
            else if(pivot < k)   quickselect(A, pivot+1, high, k, mp);
            
            else    quickselect(A, low, pivot-1, k, mp);
        }
        return;
    }
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int> mp = calcFreqs(nums);
                
        // Unique Array
        unordered_map<int,int>::iterator iter;
        vector<int> A;
        for(iter = mp.begin(); iter != mp.end(); ++iter)    {
            A.push_back(iter->first);
        }
        
        int n1 = A.size();
        quickselect(A, 0, n1-1, n1-k, mp);
        vector<int> ans;
        
        for(int i=n1-k; i<n1; i++)
            ans.push_back(A[i]);
        return ans;
    }
};