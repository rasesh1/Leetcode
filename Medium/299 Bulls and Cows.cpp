class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> mp;
        int bulls=0,cows=0;
        
        for(int i=0; i<guess.length(); i++) {
            char c = guess[i];
            char s = secret[i];
            if(c == s)
                bulls++;
            else    {
                if(mp.find(c) == mp.end()) mp[c] = 0;
                else if(mp[c] > 0)  {
                    cows++;
                }
                mp[c]--;
                
                if(mp.find(s) == mp.end()) mp[s] = 0;
                else if(mp[s] < 0)
                    cows++;
                mp[s]++;
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};