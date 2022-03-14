// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int num1 = rand7();
        int num2 = rand7();
        
        int num = 7*(num1-1) + num2;
        if(num > 40) return rand10();
        else if(num%10 == 0) return 10;
        return num%10;
    }
};