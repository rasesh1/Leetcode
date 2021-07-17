class Solution {
public:
    int fourSumCount(vector<int>& A1, vector<int>& A2, vector<int>& A3, vector<int>& A4) {
        int len1 = A1.size();
        int len2 = A2.size();
        int len3 = A3.size();
        int len4 = A4.size();
        
        if(len1 == 0 || len2 == 0 || len3 == 0 || len4 == 0)
            return 0;
        
        unordered_map<int,int> mp1;
        
        for(int i=0; i<len1; i++)   {
            for(int j=0; j<len2; j++)   {
                int sum = A1[i]+A2[j];
                if(mp1.find(sum) == mp1.end())
                    mp1[sum] = 0;
                mp1[sum]++;
            }
        }
        
        int count=0;
        for(int i=0; i<len3; i++)   {
            for(int j=0; j<len4; j++)   {
                int sum = A3[i]+A4[j];
                if(mp1.find(-sum) == mp1.end())
                    continue;
                count = count + mp1[-sum];
            }
        }
        
        return count;
    }
};