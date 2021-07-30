class DisjointSets  {
public:
    vector<int> parent;
    vector<int> sizes;
    
    DisjointSets() {
    }
    
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
        
        if(sizes[p1] <= sizes[p2])  {
            parent[p1] = p2;
            sizes[p2] = sizes[p1]+sizes[p2];
            sizes[p1] = 0;
        }
        else    {
            parent[p2] = p1;
            sizes[p1] = sizes[p1]+sizes[p2];
            sizes[p2] = 0;
        }
        return;
    }
    
};

class Solution {
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        
        unordered_map<string,string> mail_name;
        unordered_map<string,int> mail_ind;
        
        DisjointSets * unionSet = new DisjointSets();
        vector<string> ind_email;
        int index=0;
        
        for(auto account : accounts)  {
            string name = account[0];
            
            for(int j=1; j<account.size(); j++) {
                string mail = account[j];
                
                if(mail_ind.find(mail) == mail_ind.end())   {
                    mail_ind[mail] = index;
                    ind_email.push_back(mail);
                    mail_name[mail] = name;
                    
                    unionSet->parent.push_back(index);
                    unionSet->sizes.push_back(1);
                    unionSet->Union(index, mail_ind[account[1]]);
                    index++;
                }
                else
                    unionSet->Union(mail_ind[account[j]], mail_ind[account[1]]);
            }
        }
        
        for(int i=0; i<ind_email.size(); i++)
            unionSet->Find(i);
        
        unordered_map<int, vector<string>> set_mail;
        vector<int> parents = unionSet->parent;
        for(int i=0; i<parents.size(); i++) {
            string mail = ind_email[i];
            int temp = parents[i];
            
            if(set_mail.find(temp) == set_mail.end())  {
                set_mail[temp] = {mail_name[mail]};
            }
            
            set_mail[temp].push_back(mail);
        }
        
        vector<vector<string>> ans;
        unordered_map<int, vector<string>>::iterator iter;
        
        for(iter=set_mail.begin(); iter != set_mail.end(); ++iter)  {
            vector<string> temp = iter->second;
            sort(temp.begin()+1, temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};