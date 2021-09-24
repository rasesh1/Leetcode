class Solution {
private:
    vector<string> ans;
    unordered_map<char,string> mp;
    
    void letterCombinationsUtil(string digits, string curr, int index) {
        int n = digits.length();
        if(index == n) {
            ans.push_back(curr);
            return;
        }
        
        char c = digits[index];
        string str = mp[c];
        for(int j=0; j<str.length(); j++)   {
            char s = str[j];
            letterCombinationsUtil(digits, curr+s, index+1);
        }
        return;
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return ans;
        
        mp['2'] = "abc"; mp['3'] = "def";
        mp['4'] = "ghi"; mp['5'] = "jkl"; mp['6'] = "mno";
        mp['7'] = "pqrs"; mp['8'] = "tuv"; mp['9'] = "wxyz";
        
        string curr = "";
        letterCombinationsUtil(digits, curr, 0);
        return ans;
    }
};