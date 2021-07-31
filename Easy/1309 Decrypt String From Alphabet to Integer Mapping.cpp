class Solution {
public:
    string freqAlphabets(string s) {
        string ans = "";
        
        int i=0;
        while(i < s.length())   {
            if(i+2 < s.length() && s[i+2] == '#')   {
                string temp = s.substr(i, 2);
                int num = stoi(temp);
                ans = ans + (char)(96+num);
                i = i+3;
            }
            else    {
                string temp = s.substr(i, 1);
                int num = stoi(temp);
                ans = ans + (char)(96+num);
                i++;
            }
        }
        return ans;
    }
};