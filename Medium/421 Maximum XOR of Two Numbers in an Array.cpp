class TrieNode  {
public:
    vector<TrieNode*> children;
    bool isEnd;
    
    TrieNode()  {
        children.resize(2);
        for(int i=0; i<2; i++)
            children[i] = NULL;
    }
};

class Trie  {
private:
    TrieNode* root;
public:
    Trie()  {
        root = new TrieNode();
        root->isEnd = false;
    }
    
    void insert(string num) {
        int len = num.length();
        TrieNode* temp = root;
        
        for(int i=0; i<len; i++)    {
            char c = num[i];
            
            if(temp->children[c-'0'] == NULL)   {
                TrieNode* newNode = new TrieNode();
                temp->children[c-'0'] = newNode;
                newNode->isEnd = false;
                temp = newNode;
            }
            else    {
                temp = temp->children[c-'0'];
            }
            if(i==len-1) temp->isEnd = true;
        }
        return;
    }
    
    string traverse(string num) {
        int len = num.length();
        TrieNode* temp = root;
        
        string ans = "";
        
        for(int i=0; i<len; i++)    {
            char c = num[i];
            
            if(temp == NULL)    {
                ans = ans + '0';
                continue;
            }
            if(temp->children[0] == NULL && temp->children[1] == NULL)  {
                ans = ans + '0';
                continue;
            }
            
            char toggle = c=='1' ? '0' : '1';
            
            if(temp->children[toggle-'0'] == NULL)  {
                ans = ans + '0';
                temp = temp->children[c-'0'];
            }
            else    {
                ans = ans + '1';
                temp = temp->children[toggle-'0'];
            }
        }
        return ans;
    }
};

class Solution {
private:
    int bits=32;
    string decToBinary(int n)
    {
        string ans = "";
        // Size of an integer is assumed to be 32 bits
        for (int i = bits-1; i >= 0; i--) {
            int k = n >> i;
            if (k & 1) ans = ans + '1';
            else ans = ans + '0';
        }
        return ans;
    }
    
    int binaryToDec(string num)   {
        
        int ans = 0;
        for(int i=0; i<bits; i++) {
            if(num[i] == '1')
                ans = ans + pow(2,bits-1-i);
        }
        return ans;
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie* trie = new Trie();
        
        if(n == 1) return 0;
        
        int maxi = nums[0];
        for(auto num : nums)    {
            if(maxi < num)
                maxi = num;
        }
        
        bits = (int)log2(maxi)+1;
        
        string maxXOR(bits,'0');
        for(int i=0; i<nums.size(); i++)    {
            string binary_str = decToBinary(nums[i]);
            trie->insert(binary_str);
            
            string temp = trie->traverse(binary_str);
            if(temp > maxXOR) maxXOR = temp;
        }
        
        int ans = binaryToDec(maxXOR);
        return ans;
    }
};