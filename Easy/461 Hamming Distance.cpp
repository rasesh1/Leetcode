class Solution {
public:
    int hammingDistance(int x, int y) {
        int XOR = x^y;
        
        int count = 0;
        while( XOR != (XOR & (XOR-1)) )   {
            XOR = (XOR & (XOR-1));
            count++;
        }
        return count;
    }
};