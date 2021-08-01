class unionFind {
    
public:
    vector<int> parent;
    vector<int> sizes;
    
    unionFind() { }
    
    int Find(int i) {
        if(i == parent[i]) return i;
        
        int j = Find(parent[i]);
        parent[i] = j;
        return j;
    }
    
    void Union(int i, int j)    {
        int p1 = Find(i);
        int p2 = Find(j);
        
        if(p1 == p2) return;
        
        if(sizes[p1] < sizes[p2])   {
            parent[p1] = p2;
            sizes[p2] = sizes[p1]+sizes[p2];
            sizes[p1]=0;
        }
        else    {
            parent[p2] = p1;
            sizes[p1] = sizes[p1]+sizes[p2];
            sizes[p2]=0;
        }
        return;
    }
};

class Solution {
public:
    unordered_map<string,int> ind_word;
    int index=0;
    
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int len1 = sentence1.size();
        int len2 = sentence2.size();
        
        if(len1 != len2) return false;
        
        unionFind* obj = new unionFind();
        
        for(int i=0; i<similarPairs.size(); i++)    {
            string w1 = similarPairs[i][0];
            string w2 = similarPairs[i][1];
            
            if(ind_word.find(w1) == ind_word.end()) {
                ind_word[w1] = index;
                obj->parent.push_back(index);
                obj->sizes.push_back(1);
                index++;
            }
                
            
            if(ind_word.find(w2) == ind_word.end()) {
                ind_word[w2] = index;
                obj->parent.push_back(index);
                obj->sizes.push_back(1);
                index++;
            }
            
            obj->Union(ind_word[w1], ind_word[w2]);
        }
        
        for(int i=0; i<len1; i++)   {
            string s1 = sentence1[i];
            string s2 = sentence2[i];
            
            if(s1 == s2) continue;
            
            if(ind_word.find(s1) == ind_word.end() || ind_word.find(s2) == ind_word.end()) return false;
            
            int p1 = obj->Find(ind_word[s1]);
            int p2 = obj->Find(ind_word[s2]);
            
            if(p1 != p2) return false;
        }
        return true;
    }
};