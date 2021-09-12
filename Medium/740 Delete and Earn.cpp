class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        
        for(auto n : nums)  {
            if(mp.find(n) == mp.end()) mp[n] = 0;
            mp[n]++;
        }
        
        map<int,int>::iterator iter;
        vector<int> vec;
        for(iter = mp.begin(); iter != mp.end(); ++iter)
            vec.push_back(iter->first);
        
        n = vec.size();
        int A[n+1];
        A[0]=0; A[1] = mp[vec[0]]*vec[0];
        
        for(int i=2; i<=n; i++) {
            int curr = vec[i-1];
            if(curr-vec[i-2] == 1)  {
                A[i] = max(A[i-1], A[i-2]+mp[curr]*curr);
            }
            else A[i] = A[i-1]+mp[curr]*curr;
        }
        return A[n];
    }
};