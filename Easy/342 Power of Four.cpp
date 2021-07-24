class Solution {
public:
    bool isPowerOfFour(int x) {
        if(x == 0) return false;
        
        long n = x;
        return (((n & (-n)) == n) && ( (n & 0xaaaaaaaa) == 0));
    }
};