class Solution {
private:
    vector<int> sums;
    vector<int> stoneValue;
    int recurse(int start, string chance, vector<int>& alice, vector<int>& bob)    {
        int n = stoneValue.size();
        if(start >= n) return 0;
        
        int oneStone = stoneValue[start];
        int twoStone = oneStone + (start+1 < n ? stoneValue[start+1] : 0);
        int threeStone = twoStone + (start+2 < n ? stoneValue[start+2] : 0);
        
        if(chance == "bob") {
            if(bob[start] != INT_MIN) return bob[start];
            
            if(start+1 < n) oneStone = oneStone + sums[start+1] - recurse(start+1, "alice", alice, bob);
            if(start+2 < n) twoStone = twoStone + sums[start+2] - recurse(start+2, "alice", alice, bob);
            if(start+3 < n) threeStone = threeStone + sums[start+3] - recurse(start+3, "alice", alice, bob);
            
            bob[start] = max(oneStone, max(twoStone, threeStone));
            return bob[start];
        }
        
        if(alice[start] != INT_MIN) return alice[start];
        
        if(start+1 < n) oneStone = oneStone + sums[start+1] - recurse(start+1, "bob", alice, bob);
        if(start+2 < n) twoStone = twoStone + sums[start+2] - recurse(start+2, "bob", alice, bob);
        if(start+3 < n) threeStone = threeStone + sums[start+3] - recurse(start+3, "bob", alice, bob);
        
        int maxi = max(oneStone, max(twoStone, threeStone));
        alice[start] = maxi;
        return maxi;
    }
    
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        this->stoneValue = stoneValue;
        
        sums.resize(n,0);
        sums[n-1] = stoneValue[n-1];
        for(int i=n-2; i>=0; i--)
            sums[i] = sums[i+1] + stoneValue[i];
        
        vector<int> alice(n,INT_MIN);
        vector<int> bob(n,INT_MIN);
        
        int maxi = recurse(0, "alice", alice, bob);
        int sum = sums[0];
        
        if(2*maxi == sum) return "Tie";
        else if(2*maxi > sum) return "Alice";
        return "Bob";
    }
};