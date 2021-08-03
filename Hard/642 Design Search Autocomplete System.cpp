class TrieNode  {
public:
    vector<TrieNode*> children;
    vector<string> suggs;
    bool isEnd;
    
    TrieNode()  {
        children.resize(27);
        for(int i=0; i<27; i++)
            children[i] = NULL;
        
        isEnd = false;
    }
};

unordered_map<string, int> mp;
    
bool cmp(const string s1, const string s2)   {
    if(mp[s1] == mp[s2])
        return s1 < s2;

    return mp[s1] > mp[s2];
}

class Trie  {
public:
    TrieNode* root;
    
    void updateSuggestions(TrieNode* node, string word)  {
        
        int freq = mp[word];
        vector<string> curr = node->suggs;
        
        // Check if already present
        if(find(curr.begin(), curr.end(), word) == curr.end())   {
            node->suggs.push_back(word);
        }
            
        sort(node->suggs.begin(), node->suggs.end(), cmp);

        if(node->suggs.size() > 3)  {
            node->suggs.pop_back();
        }
    }
    
public:
    Trie()  {
        root = new TrieNode();
    }
    
    void insert(string word)    {
        int freq = mp[word];
        int len = word.length();
        TrieNode* temp = root;
        
        for(int i=0; i<len; i++)    {
            char c = word[i];
            int ind = c-'a';
            if(c == ' ') ind = 26;
            
            if(temp->children[ind] == NULL) {
                TrieNode* newNode = new TrieNode();
                temp->children[ind] = newNode;
                temp = newNode;
            }
            else    {
                temp = temp->children[ind];
            }
            
            updateSuggestions(temp, word);
            
            if(i == len-1) temp->isEnd = true;
        }
        return;
    }
    
    vector<string> search(string word)    {
        
        int len = word.length();
        TrieNode* temp = root;
        
        for(int i=0; i<len; i++)    {
            char c = word[i];
            int ind = c-'a';
            if(c == ' ') ind = 26;
            
            if(temp->children[ind] == NULL) {
                return {};
            }
            else    {
                temp = temp->children[ind];
            }
            if(i == len-1)  {
                return temp->suggs;
            }
            
        }
        return {};
    }
    
};
 
class AutocompleteSystem {
private:
    string prev = "";
    Trie* trie;

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        trie = new Trie();
        
        for(int i=0; i<times.size(); i++)   {
            string word = sentences[i];
            int freq = times[i];
            
            mp[word] = freq;
            trie->insert(word);
        }
    }
    
    vector<string> input(char c) {
        if(c == '#')    {
            if(mp.find(prev) == mp.end())   {
                mp[prev] = 0;
            }
            mp[prev]++;
            trie->insert(prev);
            prev = "";
            return {};
        }
        
        prev = prev + c;
        vector<string> ans = trie->search(prev);
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */