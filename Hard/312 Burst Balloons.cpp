typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class Solution {
    
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.emplace_back(1);
        
        int n = nums.size();
        vvi A(n, vector<int>(n));
        
        for(int delta=0; delta<n-1; delta++)  {
            for(int i=1; i+delta<n-1; i++)    {
                int x = i;
                int y = i+delta;
                
                if(x == y)  {
                    A[x][x] = nums[x-1]*nums[x]*nums[y+1];
                    continue;
                }
                
                A[x][y]=0;
                int currentCoins = 0;
                for(int k=x; k<=y; k++)    {
                    
                    int left = A[x][k-1];
                    int right = A[k+1][y];
                    
                    int gain = nums[k]*nums[x-1]*nums[y+1];
                    
                    int newCoins = left + gain + right;
                    if(newCoins > A[x][y]) A[x][y] = newCoins;
                }
            }
        }
        return A[1][n-2];
    }
};