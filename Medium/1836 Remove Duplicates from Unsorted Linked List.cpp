/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> mp;
        if(head == NULL || head->next == NULL) return head;
        
        mp[head->val] = 1;
        
        // Fill the map
        ListNode* curr = head->next;
        ListNode* prev = head;
        while(curr != NULL) {
            int val = curr->val;
            if(mp.find(val) == mp.end())
                mp[val]=0;
            
            mp[val]++;
            if(mp[val] > 1)    prev->next = curr->next;
            else prev = prev->next;
            curr = curr->next;
        }
        
        curr = head->next;
        prev = head;
        while(curr != NULL) {
            int val = curr->val;
            if(mp[val] > 1)    prev->next = curr->next;
            else    prev = prev->next;
            
            curr = curr->next;
        }
        
        // Check HEAD
        int val = head->val;
        if(mp[val] > 1) head = head->next;
        
        return head;
    }
};