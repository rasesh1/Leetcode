typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class Solution {    
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        
        vvi A(m+1, vector<int>(m+1,0));
        for(int i=m-1; i>=0; i--) {
            for(int left=i; left>=0; left--)    {
                
                int mult = multipliers[i];
                int right = n-1-(i-left);
                int score_left = mult*nums[left];
                int score_right = mult*nums[right];
                
                A[i][left] = max(score_left+A[i+1][left+1],
                                score_right+A[i+1][left]);
                    
            }
        }
        return A[0][0];
    }
};