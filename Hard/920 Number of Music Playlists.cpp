class Solution {
private:
    int k;
    int n;
    int goal;
    int MOD = 1000000007;
    
    long int recurse(int songsRemain, int uniqueSongsRemain, map<vector<int>,int>& mp)  {
        if(songsRemain == 0)    {
            if(uniqueSongsRemain == 0)    {
                return 1;
            }
            return 0;
        }
        if(uniqueSongsRemain < 0) return 0;
        
        if(mp.find({songsRemain,uniqueSongsRemain}) != mp.end()) {
            return mp[{songsRemain,uniqueSongsRemain}];
        }
        
        int ways = 0;
        
        long long int newSong = (uniqueSongsRemain * recurse(songsRemain - 1, uniqueSongsRemain - 1, mp)%MOD );
        long long int usedSong = (max(0, n-uniqueSongsRemain-k) * recurse(songsRemain - 1, uniqueSongsRemain, mp)%MOD );
        
        mp[{songsRemain,uniqueSongsRemain}] = (newSong + usedSong)%MOD;
        
        return mp[{songsRemain,uniqueSongsRemain}];
    }
    
public:
    int numMusicPlaylists(int n, int goal, int k) {
        this->k = k;
        this->n = n;
        this->goal = goal;
        if(n > goal) return 0;
        
        map<vector<int>,int> mp;
        
        int ways = recurse(goal, n, mp);
        return mp[{goal,n}];
    }
};