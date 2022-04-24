class Solution {
private:
    int computeBouquets(vector<int>& bloomDay, int day, int k)  {
        int ans = 0;
        int count = 0;
        for(int i=0; i<bloomDay.size(); i++)    {
            int d = bloomDay[i];
            if(d <= day)    {
                count++;
                if(count == k)  {
                    ans++;
                    count = 0;
                }
            }
            else    {
                count = 0;
            }
        }
        return ans;
    }
    
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        
        int left=1, right=maxi;
        int minDays = maxi;
        if(n < m*k) return -1;
        
        while(left <= right)    {
            int mid = left + (right-left)/2;
            int numBouquets = computeBouquets(bloomDay, mid, k);
            
            if(left == right)   {
                if(numBouquets >= m) return left;
                else return -1;
            }
            
            if(numBouquets < m) {
                left = mid+1;
            }
            else    {
                right = mid;
                minDays = mid;
            }
        }
        return minDays;
    }
};