class Solution {
public:
    string predictPartyVictory(string senate) {
        int len = senate.length();

        int radiant = 0, dire = 0;
        queue<char> q;
        int r=0, d=0;
        for(auto s : senate)    {
            q.push(s);
            if(s == 'R') radiant++;
            else dire++;
        }
        
        int re = 0, de = 0;
        while(radiant > 0 && dire > 0)  {
            char c = q.front(); q.pop();
            
            if(c == 'R')    {
                re++;
                if(re > de) q.push(c);
                else radiant--;
            }
            else    {
                de++;
                if(de > re) q.push(c);
                else dire--;
            }
        }
        
        return radiant == 0 ? "Dire" : "Radiant";
    }
};