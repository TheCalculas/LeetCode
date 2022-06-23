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
        ListNode* insertionSortList(ListNode *head)
        {
            ListNode *dummy = new ListNode(0);
            dummy->next = head;
            ListNode *prev = head;
            ListNode *curr = head;
            while (curr)
            {
                if (curr->val >= prev->val)
                {
                    prev = curr;
                    curr = curr->next;
                    continue;
                }
                else
                {
                    ListNode *temp = dummy;
                    while (temp->next->val < curr->val)
                    {
                        temp = temp->next;
                    }
                    prev->next = curr->next;
                    curr->next = temp->next;
                    temp->next = curr;
                    curr = prev->next;
                }
            }
            return dummy->next;
        }
};