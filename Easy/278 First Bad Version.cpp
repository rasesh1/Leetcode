// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
private:
    int firstBadVersionUtil(int start, int end) {
        if(start == end)    {
            if(isBadVersion(start)) return start;
            else return 0;
        }
        
        if(end-start == 1)  {
            if(isBadVersion(start)) return start;
            else if(isBadVersion(end)) return end;
            return -1;
        }
        
        int mid = start + (end-start)/2;
        bool isMidBad = isBadVersion(mid);
        
        if(isMidBad && (mid == 0 || (mid-1 >= 1 && !isBadVersion(mid-1)) ) ) return mid;
        
        else if(isMidBad)
            return firstBadVersionUtil(start, mid-1);
        else return firstBadVersionUtil(mid+1, end);
        
        return -1;
    }
    
public:
    int firstBadVersion(int n) {
        if(n == 1)  {
            if(isBadVersion(1)) return 1;
            else return 0;
        }
        
        return firstBadVersionUtil(1,n);
    }
};