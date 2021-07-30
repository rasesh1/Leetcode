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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* evenHead = head->next;
        ListNode* odd_curr = head;
        ListNode* curr = evenHead;
        
        int index=3;
        while(curr->next != NULL) {
            if(index%2 == 0)    {
                curr = curr->next;
                index++;
                continue;
            }
            
            ListNode* next = curr->next;
            ListNode* next_next = next->next;
            
            curr->next = next_next;
            next->next = evenHead;
            odd_curr->next = next;
            
            odd_curr = next;
            index++;
        }
        return head;
    }
};