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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        
        if(head == NULL || head->next == NULL || k==1) return head;
        ListNode* dummy = new ListNode(-1,head);
        head = dummy;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while(curr != NULL) {
            
            // Check if k nodes exist
            ListNode* xxx = prev;
            int nodesCount=0;
            while(xxx != NULL && nodesCount<k) {
                xxx = xxx->next;
                nodesCount++;
            }
            if(xxx == NULL) break;
            
            ListNode* temp = curr, *start = prev;
            count=1;
            while(count < k)    {
                ListNode* xxx = temp->next;
                temp->next = xxx->next;
                xxx->next = start->next;
                start->next = xxx;
                count++;
                
                prev = temp;
                if(prev->next == NULL) break;
                curr = prev->next;
            }
            
        }
        return head->next;
    }
};