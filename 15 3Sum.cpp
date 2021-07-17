class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        int len = A.size();
        vector<vector<int>> ans;
        map<pair<int,int>,int> mp;
        
        if(len <= 2) return ans;
        sort(A.begin(), A.end());
        
        int i=0;
        for(i=0; i<=len-3; i++)    {
            int j=i+1, k=len-1;
            while(j < k)    {
                if(A[j]+A[k]+A[i] == 0) {
                    mp[{A[i],A[j]}] = A[k];
                    j++;
                    k--;
                }
                else if(A[j] + A[k] > -A[i])    {
                    k--;
                    while(k > i && A[k] == A[k+1])
                        k--;
                }
                else    {
                    j++;
                    while(j < len && A[j] == A[j-1]) j++;
                }
            }
        }
        
        map<pair<int,int>,int>::iterator iter;
        for(iter = mp.begin(); iter != mp.end(); ++iter)    {
            pair<int,int> key = iter->first;
            int third = iter->second;
            
            ans.push_back({key.first, key.second, third});
        }
        return ans;
        
    }
};