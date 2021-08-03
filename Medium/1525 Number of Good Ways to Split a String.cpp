class Solution {
private:
    unordered_map<char,int> leftMap;
    unordered_map<char,int> rightMap;
    
public:
    int numSplits(string s) {
        
        int left=0, right=0, count=0;
        
        for(int i=0; i<s.length(); i++) {
            if(rightMap.find(s[i]) == rightMap.end())   {
                rightMap[s[i]] = 0;
                right++;
            }
            rightMap[s[i]]++;
        }
        
        for(int i=0; i<s.length()-1; i++)   {
            char c = s[i];
            
            if(leftMap.find(s[i]) == leftMap.end()) {
                leftMap[s[i]] = 0;
                left++;
            }
            leftMap[s[i]]++;
            
            rightMap[s[i]]--;
            if(rightMap[s[i]] == 0) right--;
            
            if(left == right) count++;
        }
        return count;
    }
};