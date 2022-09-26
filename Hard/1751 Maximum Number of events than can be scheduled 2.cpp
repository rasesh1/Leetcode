static bool cmp(const vector<int>& v1, const vector<int>& v2)   {
    if(v1[1] == v2[1])
        return v1[0] > v2[0];
    return v1[1] < v2[1];
}

class Solution {
private:
    int findPreviousEvent(vector<vector<int>>& events, int right)    {
        int left = 0;
        int val = events[right][0]-1;
        
        while(left <= right)    {
            if(left == right) {
                if(events[left][1] <= val) return left;
                return -1;
            }
            else if(right-left == 1)    {
                if(events[right][1] <= val) return right;
                else if(events[left][1] <= val) return left;
                else return -1;
            }
            
            int mid = left + (right-left)/2;
            int midval = events[mid][1];
            
            if(midval == val) return mid;
            else if(midval > val) right = mid-1;
            else left = mid;
        }
        return -1;
    }
    
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> A(k+1, vector<int>(n,0));
        sort(events.begin(), events.end(), cmp);
        
        for(int i=0; i<=k; i++) {
            for(int j=0; j<n; j++)  {
                if(i == 0)  {
                    A[i][j] = 0;
                    continue;
                }
                else if(j == 0) {
                    A[i][j] = events[j][2];
                    continue;
                }
                
                // Not attend
                A[i][j] = A[i][j-1];
                
                // Attend
                int prev_j = findPreviousEvent(events, j);
                A[i][j] = max(A[i][j], events[j][2] + (prev_j >= 0 ? A[i-1][prev_j] : 0));
                
            }
        }
        return A[k][n-1];
    }
};