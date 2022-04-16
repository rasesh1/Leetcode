class Solution {
private:
    int evaluate(int num1, int num2, string& token) {
        int num = num1+num2;
        if(token == "-")
            num = num2-num1;
        else if(token == "*") num = num1*num2;
        else if(token == "/") num = num2/num1;
        return num;
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> s;
        vector<string> ops = {"+", "-", "*", "/"};
        int ans = 0;
        
        for(auto token : tokens)    {
            if(find(ops.begin(), ops.end(), token) != ops.end())    {
                // Operator
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();
                
                s.push(evaluate(num1, num2, token));
            }
            else
                s.push(stoi(token));
        }
        return s.top();
    }
};