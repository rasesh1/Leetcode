class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts, ends;
        
        for(auto interval : intervals)  {
            starts.push_back(interval[0]);
            ends.push_back(interval[1]);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int count = 0, rooms=0;
        int i=0, j=0;
        while(i < intervals.size()) {
            int start = starts[i];
            int end = ends[j];
            
            if(end <= start)    {
                count--;
                j++;
            }
                
            else {
                count++;
                i++;
            }
                        
            rooms = max(rooms, count);
        }
        return rooms;
    }
};