class Solution {
private:
    double computeTime(vector<int>& dist, int speed)   {
        double ans = 0;
        for(int i=0; i<dist.size()-1; i++)  {
            ans = ans + dist[i]/speed;
            if(dist[i]%speed > 0) ans++;
        }
        ans = ans + 1.0*dist[dist.size()-1]/speed;
        return ans;
    }
    
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int maxDist = 10000000;
        
        if(n-1 >= hour) return -1;
        
        int left = 1, right = maxDist;
        int minSpeed = INT_MAX;
        while(left <= right)    {
            if(left == right)   {
                if(computeTime(dist, left) <= hour) return left;
                else if(minSpeed < INT_MAX) return minSpeed;
                else return -1;
            }
            int mid = left + (right-left)/2;
            
            double time = computeTime(dist, mid);
            if(time <= hour) {
                right = mid;
                minSpeed = mid;
            }
            else left = mid+1;
        }
        return -1;
    }
};