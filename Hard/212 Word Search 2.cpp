typedef vector<vector<string>> vvs;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;

class TrieNode  {
public:
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode* parent;
    
    TrieNode()  {
        children.resize(26);
        for(int i=0; i<26; i++)
            children[i] = NULL;
    }
};

class Trie  {
    public:
    TrieNode* root;
    
    Trie()  {
        root = new TrieNode();
        root->parent = NULL;
    }
    
    void insert(string word)    {
        TrieNode* temp = root;
        int len = word.length();
        
        for(int i=0; i<len; i++)    {
            char c = word[i];
            
            if(temp->children[c-'a'] == NULL)   {
                TrieNode* newNode = new TrieNode();
                temp->children[c-'a'] = newNode;
                newNode->isEnd = false;
                newNode->parent = temp;
                temp = newNode;
            }
            else    {
                temp = temp->children[c-'a'];
            }
            if(i == len-1)
                temp->isEnd = true;
        }
        return;
    }
    
    bool search(string word)    {
        TrieNode* temp = root;
        int len = word.length();
        
        for(int i=0; i<len; i++)    {
            char c = word[i];
            
            if(temp->children[c-'a'] == NULL)   {
                return false;
            }
            else    {
                temp = temp->children[c-'a'];
                if(i == len-1) return temp->isEnd;
            }
            
        }
        return false;
    }
    
    TrieNode* startsWith(string prefix)  {
        TrieNode* temp = root;
        
        int len = prefix.length();
        for(int i=0; i<len; i++)    {
            char c = prefix[i];
            
            if(temp->children[c-'a'] == NULL)
                return NULL;
            else    {
                temp = temp->children[c-'a'];
                if(i == len-1)
                    return temp;
            }
        }
        return NULL;
    }
};

class Solution {
private:
    unordered_set<string> output;
    vector<string> ans;
    
    void backtrack(Trie* trie, vvi& visited, int x, int y, string curr, vvc& board, TrieNode* node)   {
        if(trie->search(curr))   {
            if(output.find(curr) == output.end())   {
                ans.push_back(curr);
                output.insert(curr);
            }
        }
        
        vector<int> xs = {-1,0,1,0};
        vector<int> ys = {0,1,0,-1};
        
        for(int k=0; k<4; k++)  {
            int i = x + xs[k];
            int j = y + ys[k];
            
            if(i >= 0 && i < board.size() && j >=0 && j < board[0].size() && visited[i][j] == 0)   {
                char c = board[i][j];
                if(node->children[c - 'a'] == NULL)
                    continue;
                
                visited[i][j] = 1;
                backtrack(trie,visited,i,j,curr + board[i][j],board,node->children[c - 'a']);
                visited[i][j] = 0;
            }
        }
        
        
        // Optimization to remove 
        for(int i=0; i<26; i++) {
            if(node->children[i] != NULL) return;
        }
        
        TrieNode* parent = node->parent;
        for(int i=0; i<26; i++) {
            if(parent->children[i] == node) {
                parent->children[i] = NULL;
                return;
            }
        }
        
        return;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows = board.size();
        int cols = board[0].size();
        
        int n = words.size();
        
        Trie* trie = new Trie();
        for(auto word : words)
            trie->insert(word);
        
        vvi visited(rows, vector<int>(cols,0));
        
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)       {
                string curr(1, board[i][j]);
                
                TrieNode* node = trie->startsWith(curr);
                if(node == NULL) continue;
                
                visited[i][j] = 1;
                backtrack(trie, visited, i, j, curr, board, node);
                visited[i][j] = 0;
            }
        }
        return ans;
    }
};