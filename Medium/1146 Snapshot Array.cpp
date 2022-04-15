class SnapshotArray {
private:
    unordered_map<int, unordered_map<int,int>> mp;
    int snapid = 0;
    
public:
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        mp[-1][index] = val;
        return;
    }
    
    int snap() {
        mp[snapid] = mp[-1];
        return snapid++;
    }
    
    int get(int index, int snap_id) {
        if(mp[snap_id].find(index) == mp[snap_id].end()) return 0;
        return mp[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */