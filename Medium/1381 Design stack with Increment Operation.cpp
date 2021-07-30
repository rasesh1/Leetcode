class CustomStack {
private:
    vector<int> s;
    int maxi;
    int front;
    int back;
    
public:
    CustomStack(int maxSize) {
        maxi = maxSize;
        front = 0;
        back = 0;
        s.resize(maxSize);
    }
    
    void push(int x) {
        if(back-front == maxi) return;
        
        s[back++] = x;
        return;
    }
    
    int pop() {
        if(front == back) return -1;
        back--;
        
        return s[back];
    }
    
    void increment(int k, int val) {
        int num = back-front;
        
        for(int i=0; i<min(num,k); i++ )
            s[i+front] = s[i+front] + val;
        
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */