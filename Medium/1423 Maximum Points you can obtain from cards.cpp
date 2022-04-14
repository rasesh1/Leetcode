class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0;
        for(int i=0; i<k; i++)
            leftSum = leftSum + cardPoints[i];
        
        int rightSum = 0, maxi = leftSum;
        for(int i=k; i>=1; i--) {
            leftSum = leftSum - cardPoints[i-1];
            rightSum = rightSum + cardPoints[n-1-(k-i)];
            maxi = max(maxi, leftSum+rightSum);
        }
        
        return maxi;
    }
};