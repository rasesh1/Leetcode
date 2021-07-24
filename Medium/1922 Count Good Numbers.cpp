class Solution {
private:
    int MOD = 1000000007;
    long long int power(long long int a, long long int n)   {
        if(n == 0) return 1;
        
        long long int pow = power(a, n/2);
        pow = (pow * pow) % MOD;
        
        if (n%2 == 1) return ((a % MOD) * pow) % MOD;
        return pow;
    }
    
public:
    int countGoodNumbers(long long n) {
        long long ans=1;
        
        long long int evens = ceil(1.0*n/2);
        long long int odds = n/2;
        
        return ((power(4,odds)%MOD) * (power(5, evens))%MOD)%MOD;
    }
};