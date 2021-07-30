typedef pair<int,string> pd;

class Solution {
private:
    unordered_map<string,int> mp;
    
    struct cmp {
    bool operator()(pd const& p1, pd const& p2)
    {
        if(p1.first == p2.first)
            return p1.second < p2.second;
        return p1.first > p2.first;
    }
};
    
    priority_queue<pd, vector<pd>, cmp> pq;
    
    void formFreqMapping(vector<string>& words)  {
        
        for(auto word : words)  {
            if(mp.find(word) == mp.end())   {
                mp[word] = 0;
            }
            mp[word]++;
        }
        return;
    }
    
    void populateHeap(int k) {
        unordered_map<string,int>::iterator iter;
        for(iter = mp.begin(); iter != mp.end(); ++iter)    {
            
            if(pq.size() < k)   {
                pq.push(make_pair(iter->second, iter->first));
                continue;
            }
            
            pd top = pq.top();
            if( (top.first < iter->second) || (top.first == iter->second && iter->first < top.second))   {
                pq.pop();
                pq.push(make_pair(iter->second, iter->first));
            }
        }
        return;
    }
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        
        formFreqMapping(words);
        populateHeap(k);
        
        vector<string> ans;
        while(!pq.empty())  {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};