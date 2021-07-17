class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& A, int target) {
        int len = A.size();
        vector<vector<int>> ans;
        if(len < 4) return ans;
        
        sort(A.begin(), A.end());
        
        set<vector<int>, greater<vector<int>> > s1;
        
        for(int i=0; i<len; i++)    {
            for(int j=i+1; j<len; j++)  {
                int sum = A[i]+A[j];
                
                int remain = target-sum;
                int x=j+1, y=len-1;
                while(x<y)  {
                    int temp_sum = A[x]+A[y];
                    if(temp_sum == remain)  {
                        s1.insert({A[i],A[j],A[x],A[y]});
                        if(x+1 == y) break;
                        if(A[x+1]+A[y] > A[y-1]+A[x])
                            y--;
                        else x++;
                        
                    }
                    else if(temp_sum > remain)
                        y--;
                    else x++;
                }
            }
        }
        
        set<vector<int>, greater<vector<int>> >::iterator iter;
        for(iter=s1.begin(); iter != s1.end(); ++iter)  {
            ans.push_back(*iter);
        }
        return ans;
    }
};