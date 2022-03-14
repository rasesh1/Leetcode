class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return {to_string(nums[0])};
        
        vector<string> ans;
        int i=0;
        while(i<n)  {
            string temp = to_string(nums[i]);
            bool add = false;
            
            while(++i < n)    {
                if(nums[i] == nums[i-1]+1)  {
                    add = true;
                    continue;
                }
                else break;
            }
            if(add) {
                temp = temp.append("->");
                temp = temp.append(to_string(nums[i-1]));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};