class Solution {
private:
    vector<string> ans;
    
    void generateParenthesisUtil(int n, int open, int close, string curr)    {
        if(open == 0 && close == 0) {
            ans.push_back(curr);
            return;
        }
        
        if(open > 0) generateParenthesisUtil(n, open-1, close, curr+'(');
        if(open < close) generateParenthesisUtil(n, open, close-1, curr+')');
        return;
    }
    
public:
    vector<string> generateParenthesis(int n) {
        generateParenthesisUtil(n, n, n, "");
        return ans;
    }
};