class Solution {
public:
    double myPow(double x, int n) {
        
        if(n==-1) return 1/x;
        if(n==0) return 1;
        if(n==1) return x;
        
        long t = n;
        if(n<0) {
            x = 1/x;
            t = -t;
        }
        
        double ans = myPow(x, abs(t/2) );
        
        if(n%2 == 0)
            return ans*ans;
        
        return ans*ans*x;
        
    }
};