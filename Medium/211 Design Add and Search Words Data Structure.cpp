class TrieNode  {
public:
    vector<TrieNode*> children;
    bool isEnd;
    
    TrieNode()  {
        children.resize(26);
        for(int i=0; i<26; i++)
            children[i] = NULL;
        isEnd = false;
    }
    
};

class WordDictionary {
private:
    TrieNode* root;
    
    int searchUtil(string word, TrieNode* head)    {
        if(word == "") return head->isEnd;
        
        int len = word.length();
        TrieNode* temp = head;
        
        for(int i=0; i<len; i++)    {
            char c = word[i];
            if(c == '.')    {
                
                int isPresent = 0;
                for(int j=0; j<26; j++) {
                    if(temp->children[j] == NULL) continue;
                    else {
                        isPresent = searchUtil(word.substr(i+1), temp->children[j]) + isPresent;
                    }
                }
                return isPresent;
            }
            else    {
                if(temp->children[c-'a'] == NULL) return false;
                else    {
                    temp = temp->children[c-'a'];
                    if(i == len-1) return temp->isEnd ? 1 : 0;
                }
            }
            
        }
        return 0;
    }
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        int len = word.length();
        
        TrieNode* temp = root;
        
        for(int i=0; i<len; i++)    {
            char c = word[i];
            if(temp->children[c-'a'] == NULL)    {
                TrieNode* newNode = new TrieNode();
                temp->children[c-'a'] = newNode;
                temp = newNode;
            }
            else    {
                temp = temp->children[c-'a'];
            }
            if(i == len-1) temp->isEnd = true;
        }
        return;
    }
    
    bool search(string word) {
        return searchUtil(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */