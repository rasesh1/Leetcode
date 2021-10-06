typedef pair<int,int> pi;

class Solution {
private:
    unordered_map<int,int> calcFreqs(vector<int>& nums)   {
        unordered_map<int,int> mp;
        
        for(auto n : nums)  {
            if(mp.find(n) == mp.end()) mp[n]=0;
            mp[n]++;
        }
        return mp;
    }
    
    priority_queue<pi> insertIntoHeap(unordered_map<int,int>& mp)   {
        priority_queue<pi> pq;
        unordered_map<int,int>::iterator iter;
        for(iter = mp.begin(); iter != mp.end(); ++iter)    {
            pq.push(make_pair(iter->second, iter->first));
        }
        return pq;
    }
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int> mp = calcFreqs(nums);
        
        
        priority_queue<pi> pq = insertIntoHeap(mp);
        
        vector<int> ans;
        while(ans.size() < k)   {
            pi top = pq.top(); pq.pop();
            
            ans.push_back(top.second);
        }
        
        return ans;
    }
};