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
#define node ListNode*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        node a = new ListNode(0);
        node head = a;
        int carry = 0;
        int sum = 0;
        while(l1&&l2)
        {
            sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            a->next = new ListNode(sum);
            a = a->next;
            l1 = l1 ->next;
            l2 = l2 -> next;
        }
        while(l1)
        {
            sum = l1->val + carry;
            carry = sum/10;
            sum = sum%10;
            a -> next = new ListNode(sum);
            a = a->next;
             l1 = l1 ->next;
            
        }
        while(l2)
        {
            sum = l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            a -> next = new ListNode(sum);
            a = a->next;
             l2 = l2 ->next;
            
        }
        if(carry)
        {
            a->next = new ListNode(carry);
        }
        return head->next;
    }
};