typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class Solution {
private:
    vi jobDifficulty;
    vi hardestRemaining;
    int recurse(vvi& A, int i, int day, int d) {
        if(A[i][day] != 0) return A[i][day];
        
        if(day == d)    return this->hardestRemaining[i];
        
        int lastJob = this->jobDifficulty.size() - 1 - (d-day);
        
        int maxi = INT_MIN;
        A[i][day] = INT_MAX;
        for(int j=i; j<=lastJob; j++)   {
            maxi = max(maxi, this->jobDifficulty[j]);
            A[i][day] = min(A[i][day], maxi + recurse(A, j+1, day+1, d));
        }
        return A[i][day];
    }
    
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        this->jobDifficulty = jobDifficulty;
        if(d > n) return -1;
        
        // Computing the hardest remaining job
        vi hardestRemaining(n,0);
        int hardest = INT_MIN;
        for(int i=n-1; i>=0; i--)   {
            hardest = max(hardest, jobDifficulty[i]);
            hardestRemaining[i] = hardest;
        }
        this->hardestRemaining = hardestRemaining;
        
        vvi A(n, vector<int>(d+1,0));
        return recurse(A, 0, 1, d);
    }
};