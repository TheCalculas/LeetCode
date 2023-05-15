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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* start = head;
        int cnt = k-1;
        while(cnt--) start = start->next;
        ListNode* temp = start;
        ListNode* end = head;
        while(temp->next)
        {
            temp = temp->next;
            end = end->next;
        }
        int a = start->val;
        start->val = end->val;
        end->val = a;
        return head;
        
    }
};