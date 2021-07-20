#include<bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <random>

class Solution {
public:
    vector<int> orig;
    int seed = 0;
    
    void swap(vector<int>& vec, int i, int j)   {
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
        return;
    }
    
    Solution(vector<int>& nums) {
        orig = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return orig;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> conf = orig;
        
        srand (seed++);
        for(int i=0; i<conf.size(); i++)    {
            swap(conf, i, rand() % (conf.size()-i) + i);
        }
        
        return conf;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */