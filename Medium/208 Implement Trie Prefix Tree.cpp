class TrieNode {    
public:
    
    bool isEnd;
    vector<TrieNode*> children;
    
    TrieNode()  {
        children.resize(26, NULL);
        return;
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
        root->isEnd = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int len = word.length();
        TrieNode* temp = root;
        
        for(int i=0; i<len; i++)    {
            char c = word[i];
            if(temp->children[c-'a'] != NULL)   {
                temp = temp->children[c-'a'];
            }
            else    {
                TrieNode* newNode = new TrieNode();
                temp->children[c-'a'] = newNode;
                newNode->isEnd = false;
                temp = newNode;
            }
            if(i == len-1)
                temp->isEnd = true;
        }
        return;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* temp = root;
        
        for(int i=0; i<word.length(); i++)  {
            char c = word[i];
            
            if(temp->children[c-'a'] == NULL)
                return false;
            else   {
                temp = temp->children[c-'a'];
                if(i == word.length()-1)
                    return temp->isEnd;
            }
        }
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        
        for(int i=0; i<prefix.length(); i++)  {
            char c = prefix[i];
            
            if(temp->children[c-'a'] != NULL)
                temp = temp->children[c-'a'];
                
            else return false;
            
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */