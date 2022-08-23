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
        if(head==NULL||head->next==NULL) return head;
        ListNode* temp = head;
        ListNode* hui = new ListNode(-1);
        ListNode* h = hui;
        int prev = -101;
        while(temp&&temp->next)
        {
            if(temp->val==prev)
            {
                temp = temp ->next;
                continue;
            }
            else{
                if(temp->val==temp->next->val) prev = temp->val;
                else{
                    hui -> next = new ListNode(temp->val);
                    hui = hui->next;
                }
                temp = temp->next;
            }
        }
        if(temp->val!=prev){
            hui->next = new ListNode(temp->val);
        }
        h = h->next;
        return h;
    }
};