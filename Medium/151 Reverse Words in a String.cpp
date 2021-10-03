class Solution {
private:
    void reverse(string& s, int i, int j)    {
        int left=i, right=j;
        while(left < right) {
            char c = s[left];
            s[left] = s[right];
            s[right] = c;
            left++; right--;
        }
        return;
    }
    
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        
        reverse(s, 0, s.length()-1);
        
        int i=0;
        int j = i+1;
        while(i < s.length() && j < s.length())  {
            while(i < s.length() && s[i] == ' ') i++;
            j = i+1;
            
            while(j<s.length() && s[j] != ' ') j++;
            
            if(i >= s.length()) break;
            reverse(s, i, j-1);

            ans = ans + " " + s.substr(i, j-i);
            i=j;
        }
        return ans.substr(1,ans.length()-1);
    }
};