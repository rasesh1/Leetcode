class Solution {
private:
    int A[33];
    
public:
    int findIntegers(int n) {
        
        A[0] = 0;
        A[1] = 1;
        A[2] = 2;
        
        for(int i=3; i<=32; i++)
            A[i] = A[i-1] + A[i-2];
        
        int i=31, sum=0, prev_bit=0;
        while(i >= 0)   {
            
            if((n & (1 << i)) != 0) {
                sum = sum + A[i+1];
                if(prev_bit == 1)   {
                    sum--;
                    break;
                }
                
                prev_bit = 1;
            }
            else prev_bit = 0;
            i--;
        }
        return sum+1;
    }
};