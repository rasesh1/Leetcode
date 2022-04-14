class Solution {
private:
    bool isPossible(vector<int>& position, int dist, int target)    {
        int n = position.size();
        int count = 1;
        
        int prevPos = position[0];
        for(int i=1; i<n; i++)  {
            int pos = position[i];
            if(pos - prevPos >= dist)   {
                count++;
                prevPos = pos;
            }
        }
        return count >= target;
    }
    
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int left=1, right=position[n-1];
        int minForce = INT_MIN;
        
        while(left <= right)    {
            if(left == right) return left;
            else if(right-left == 1)    {
                if(isPossible(position, right, m)) return right;
                return left;
            }
            
            int mid = left + (right-left)/2;
            bool possible = isPossible(position, mid, m);
            if(!possible)   right = mid - 1;
            else    {
                left = mid;
                minForce = mid;
            }
        }
        return minForce;
    }
};