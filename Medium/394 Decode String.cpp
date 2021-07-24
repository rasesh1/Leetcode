class Solution {
public:
    string decodeString(string s) {
        int len = s.length();
        
        stack<int> s1;
        stack<string> s2;
        
        int currentNumber=0;
        string currentString = "";
        
        for(int i=0; i<len; i++)    {
            char c = s[i];
            
            if(c >= '0' && c <= '9')    {
                currentNumber = 10*currentNumber + c-'0';
            }
            else if(c >= 'a' && c <= 'z')   {
                currentString = currentString + c;
            }
            else if(c == '[')   {
                s1.push(currentNumber);
                s2.push(currentString);
                
                currentNumber = 0;
                currentString = "";
            }
            else if(c == ']')   {
                int numTop = s1.top();
                s1.pop();
                
                string temp = "";
                for(int j=0; j<numTop; j++)
                    temp = temp + currentString;
                
                string s_top = s2.top();
                s2.pop();
                
                currentString = s_top + temp;
            }
        }
        return currentString;
    }
};