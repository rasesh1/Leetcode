class Solution {
private:
    int SumTwoNumbers(int a, int b) {
        
        int sign = (a >= 0) ? 1 : -1;
        a = abs(a);
        b = abs(b);

        while(b > 0)    {
            int carry = (a&b) << 1;
            a = a^b;
            b = carry;
        }
        return a*sign;
    }
    
    int diffTwoNumbers(int a, int b)    {
        
        if(a < 0) return diffTwoNumbers(b,a);
        
        int sign = 1;
        if(abs(a) < abs(b)) sign = -1;
        
        b = abs(b);
        while(b != 0)   {
            int borrow = ((~a) & b) << 1;
            a = a^b;
            b = borrow;
        }
        
        return a*sign;
    }
    
public:
    int getSum(int a, int b) {
        
        if(a*b >= 0)
            return SumTwoNumbers(a,b);
        
        return diffTwoNumbers(a,b);
    }
};