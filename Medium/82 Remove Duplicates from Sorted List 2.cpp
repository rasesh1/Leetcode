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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* fakeHead = new ListNode(-1, head);
        ListNode* prev = fakeHead;
        
        while(prev != NULL && prev->next != NULL)   {
            ListNode* curr = prev->next;
            int val = curr->val;
            
            if(curr->next != NULL && curr->next->val != val) {
                prev = curr;
                continue;
            }
            
            curr = curr->next;
            if(curr == NULL) break;
            while(curr != NULL && val == curr->val)   {
                curr = curr->next;
            }

            prev->next = curr;
            
        }
        return fakeHead->next;
    }
};