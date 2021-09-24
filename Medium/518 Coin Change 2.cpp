class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<int> A(amount+1,0);
        A[0]=1;
        
        for(auto denom : coins)     {
            
            for(int j=0; j<=amount; j++)    {
                int newIndex = j+denom;
                if(newIndex > amount || A[j] == 0) continue;
                
                A[newIndex] = A[newIndex] + A[j];
            }
        }
        return A[amount];
    }
};