class Solution {
private:
    int sum = 0;
    vector<int> cumulative;
    
    int binarySearch(int target, int start, int end)  {
        if(start >= end) return start;
        
        int mid = start + (end-start)/2;
        if(cumulative[mid] < target) return binarySearch(target, mid+1, end);
        else return binarySearch(target, start, mid);
        return start;
    }
    
public:
    Solution(vector<int>& w) {
        for(int i=0; i<w.size(); i++) {
            sum = sum + w[i];
            cumulative.push_back(sum);
        }
        return;
    }
    
    int pickIndex() {
        int random = 1 + rand() % sum;
        int index = binarySearch(random, 0, cumulative.size()-1);
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */