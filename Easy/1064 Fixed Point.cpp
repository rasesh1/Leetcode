class Solution {
private:
    int answer = -1;
    void binarySearch(vector<int>& arr, int start, int end)   {
        if(end < start) return;
        
        int mid = start + (end-start)/2;
        if(start == end)    {
            if(arr[start] == start) answer = start;
            else if(answer == -1) answer = -1;
            return;
        }
        
        if(arr[mid] > mid)
            binarySearch(arr, start, mid-1);
        else if(arr[mid] < mid)
            binarySearch(arr, mid+1, end);
        else    {
            answer = mid;
            binarySearch(arr, start, mid-1);
        }
        return;
    }
    
public:
    int fixedPoint(vector<int>& arr) {
        binarySearch(arr, 0, arr.size()-1);
        return answer;
    }
};