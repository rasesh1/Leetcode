class TrieNode 	{ 
public:
	bool isEnd;
	int sum;
	vector<TrieNode*> children;

	TrieNode(int s)	{ 
        children.resize(26);
        for(int i=0; i<26; i++)
            children[i] = NULL;
        sum = s;
        isEnd = false;
        return;
    }
};

class MapSum {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    unordered_map<string, int> words;
    MapSum() {
        root = new TrieNode(0);
    }
    
    void insert(string key, int val) {
        int diff = val;
        if(words.find(key) != words.end())    {
            diff = diff - words[key];
        }
        
        int len = key.length();
        TrieNode* temp = root;
        
        for(int i=0; i<len; i++)    {
            char c = key[i];
            if(temp->children[c-'a'] == NULL)   {
                TrieNode* newNode = new TrieNode(val);
                temp->children[c-'a'] = newNode;
                temp = newNode;
            }
            else    {
                temp = temp->children[c-'a'];
                temp->sum = temp->sum + diff;
            }
            
            if(i == len-1) temp->isEnd = true;
            words[key] = val;
        }
        return;
    }
    
    int sum(string prefix) {
        int len = prefix.length();
        TrieNode* temp = root;
        
        for(int i=0; i<len; i++)    {
            char c = prefix[i];
            if(temp->children[c-'a'] == NULL)
                return 0;
            else    {
                temp = temp->children[c-'a'];
                if(i == len-1) return temp->sum;
            }
        }
        return 0;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */