class Solution {
private:
    static bool cmp(const string a, const string b)   {
        return a+b > b+a;
    }
    
public:
    string largestNumber(vector<int>& nums) {
        int len = nums.size();
        
        vector<string> A;
        for(int i=0; i<len; i++)    {
            A.push_back(to_string(nums[i]));
        }
        
        if(len == 1) return A[0];
        
        sort(A.begin(), A.end(), cmp);
        
        string ans = "";
        for(int i=0; i<len; i++)
            ans = ans + A[i];
            
        
        while(ans[0] == '0' && ans.length() > 1)
            ans = ans.substr(1);
        
        return ans;
    }
};