class NumArray {
private:
    vector<int> A;
    int n;
    
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        A.resize(2*n);
        
        for(int i=0; i<n; i++)
            A[n+i] = nums[i];
        
        for(int i=n-1; i>=1; i--)   {
            A[i] = A[2*i] + A[2*i+1];
        }
        return;
    }
    
    void update(int index, int val) {
        int diff = val - A[n+index];
        
        int i=n+index;
        while(i > 0)   {
            A[i] = diff + A[i];
            i = i/2;
        }
        
        return;
    }
    
    int sumRange(int left, int right) {
        if(left == right) return A[n+left];
        
        int i=n+left;
        int j=n+right;
        
        int sum = A[i] + A[j];
        
        while( i/2 != j/2  ) {
            if(i%2 == 0) sum = sum + A[i+1];
            if(j%2 == 1) sum = sum + A[j-1];
            
            i = i/2;
            j = j/2;
        }
        
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */