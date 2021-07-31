class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        if(n <= 1) return 0;
        
        int sum = 0;
        int left=0, right=n-1;
        int leftMax = 0, rightMax = 0;
        while(left < right) {
            if(height[left] < height[right])   {
                if(height[left] < leftMax) {
                    sum = sum + leftMax-height[left];
                }
                else    {
                    leftMax = height[left];
                }
                left++;
            }
            else    {
                int curr = height[right];
                if(curr < rightMax)
                    sum = sum + rightMax-curr;
                else
                    rightMax = curr;
                right--;
            }
        }
        return sum;
    }
};