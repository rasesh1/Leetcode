class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int len = A.size();
        
        if(len < 3) return {-1,-1};
        int ones = 0;
        int zeros = 0;
        
        for(int i=0; i<len; i++)    {
            if(A[i] == 0)
                zeros++;
            else    {
                zeros=0;
                ones++;
            }
        }
        
        if(ones == 0) return {0,len-1};
        
        if(ones%3 != 0) return {-1,-1};
        
        int k = ones/3;
        int first, kth, two_kth, three_kth, kPlusFirst, twokPlusFirst;
        int count=0;
        for(int i=0; i<len; i++)    {
            if(A[i] == 1)   {
                count++;
                if(count == 1)
                    first = i;
                if(count == k)
                    kth = i;
                if (count == 2*k)
                    two_kth = i;
                if(count == k+1)
                    kPlusFirst = i;
                if(count == 2*k+1)
                    twokPlusFirst = i;
                if (count == 3*k)
                    three_kth = i;
            }
        }
        
        int x=first, y=kPlusFirst, z=twokPlusFirst;
        while(z < len)  {
            int x1 = A[x];
            int y1 = A[y];
            int z1 = A[z];
            
            if(x1 != y1 || y1 != z1) return {-1,-1};
            
            z++;
            x++;
            y++;
        }
        return {kth+zeros, two_kth+zeros+1};
    }
};