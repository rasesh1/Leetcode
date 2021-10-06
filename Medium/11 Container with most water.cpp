class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        
        int maximumWater = 0;
        int left = 0, right = n-1;
        
        while(left < right) {
            int num1 = heights[left];
            int num2 = heights[right];
            
            maximumWater = max(maximumWater, (right-left)*min(num1, num2) );
            
            if(num1 > num2) right--;
            else left++;
            
        }
        return maximumWater;
    }
};