/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* swapPairs(ListNode *head)
        {
            if (!head || !head->next) return head;
            ListNode *curr = head, *next = head->next;
            while (next && next->next)
            {
                swap(curr->val, next->val);
                curr = curr->next->next, next = next->next->next;
            }
            if (curr && next) swap(curr->val, next->val);
            return head;
        }
};