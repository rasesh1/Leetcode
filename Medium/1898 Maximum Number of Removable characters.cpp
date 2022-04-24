class Solution {
private:
    int lens;
    int lenp;
    int n;
    
    bool isSubsequence(string s, string p, vector<int>& removable, int index)  {
        unordered_set<int> sse;
        for(int i=0; i<=index; i++)  {
            sse.insert(removable[i]);
        }
        
        int i=0, j=0;
        while(i<lens && j<lenp) {
            if(sse.find(i) != sse.end()) {
                i++;
                continue;
            }
            
            if(s[i] == p[j])    {
                j++;
            }
            i++;
        }
        
        return j == lenp;
    }
    
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        lens = s.length();
        lenp = p.length();
        n = removable.size();
        
        int left=0, right=n-1;
        
        while(left <= right)    {
            if(right == left)   {
                if(isSubsequence(s, p, removable, left)) return left+1;
                else return 0;
            }
            if(right-left == 1) {
                if(isSubsequence(s, p, removable, right)) return right+1;
                else if(isSubsequence(s, p, removable, left)) return left+1;
                else return 0;
            }
            
            int mid = left + (right-left)/2;
            if(isSubsequence(s,p,removable,mid))    {
                left = mid;
            }
            else {
                right=mid-1;
            }
            
        }
        return 0;
    }
};