/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        if(!head->next) return NULL;
        if(!head->next->next) return NULL;
        auto fast = head;
        auto slow = head;
        slow = slow ->next;
        fast = fast ->next->next;
        while(fast->next&&fast->next->next&&slow!=fast&&fast!=NULL)
        {
            slow = slow ->next;
            fast = fast -> next->next;
            
        }
        // if it is not equal;
        if(slow!=fast)
        {
            return NULL;
        }
        slow = head;
        while(slow!=fast)
        {
            slow = slow->next;
            fast  = fast->next;
        }
        return fast;
    }
};