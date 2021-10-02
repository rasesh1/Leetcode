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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        if(head == NULL) return head;
        
        ListNode* fakeHead = new ListNode(-1, head);
        ListNode* curr = fakeHead;
        while(curr->next != NULL) {
            
            int hops = 0;
            while(hops++ < m && curr != NULL) {
                curr = curr->next;
            }
            if(curr == NULL) break;
            
            int deleted = 0;
            while(deleted++ < n && curr->next != NULL)  {
                curr->next = curr->next->next;
            }
        }
        return head;
    }
};