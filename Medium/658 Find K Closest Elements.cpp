class Solution {
private:
    int findSmallerOrEqual(vector<int>& arr, int num)   {
        int n = arr.size();
        
        int left=0;
        int right = n-1;
        while(left <= right)    {
            if(left == right) return left;
            else if(right-left == 1)    {
                if(arr[left] <= num) return left;
                return right;
            }
            int mid = left + (right-left)/2;
            if(arr[mid] == num) return mid;
            else if(arr[mid] > num) right = mid-1;
            else left = mid;
        }
        return left;
    }
    
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        
        // Binary search to find index just smaller than or equal to k
        int smaller = findSmallerOrEqual(arr, x);
        int larger = smaller+1;
        
        int left = max(0,smaller-k+1);
        int right = left+k;
        while( right < n && x-arr[left] > arr[right]-x ) {
            left++;
            right++;
        }
        
        while(ans.size() < k)   {
            ans.push_back(arr[left++]);
        }
        return ans;
    }
};