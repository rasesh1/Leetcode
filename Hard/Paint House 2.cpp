class Solution {
private:
    vector<int> findTwoSmallest(vector<int>& ans)    {
        int smallest=INT_MAX, nextSmallest=INT_MAX;
        int smallestIndex=0, nextSmallestIndex=0;
        
        for(int i=0; i<ans.size(); i++) {
            if(ans[i] < smallest)   {
                nextSmallest = smallest;
                smallest = ans[i];
                
                nextSmallestIndex = smallestIndex;
                smallestIndex=i;
                
            }
            else if(ans[i] < nextSmallest)  {
                nextSmallest = ans[i];
                nextSmallestIndex = i;
            }
        }
        
        return {smallestIndex, nextSmallestIndex};
    }
    
public:
    int minCostII(vector<vector<int>>& A) {
        int n = A.size();
        int k = A[0].size();
        
        vector<int> prev(k, 0);
        vector<int> curr(k, 0);
        vector<int> twoSmallest(2,0);
        
        // Base Case
        for(int i=0; i<k; i++)  {
            curr[i] = A[0][i];
        }
        twoSmallest = findTwoSmallest(curr);
        if(n == 1) return curr[twoSmallest[0]];
        
        
        for(int i=1; i<n; i++)  {
            prev = curr;
            for(int j=0; j<k; j++)  {
                
                if(twoSmallest[0] == j)  {
                    curr[j] = prev[twoSmallest[1]] + A[i][j];
                }
                else    {
                    curr[j] = prev[twoSmallest[0]] + A[i][j];
                }
            }
            twoSmallest = findTwoSmallest(curr);
        }
        return curr[twoSmallest[0]];
    }
};