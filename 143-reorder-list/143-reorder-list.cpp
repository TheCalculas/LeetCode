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
        void reorderList(ListNode *head)
        {
           	// find the mid point
            auto slow = head;
            auto fast = head;
            while (fast->next && fast->next->next)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            // we got the mid point -> slow
            ListNode* prev = NULL;
            auto next = slow;
            auto curr = slow;
            while(curr)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            auto mid = prev;
            auto start = head;
            while(start&&mid)
            {
                auto tstart = start->next;
                start->next = mid;
                auto tmid = mid->next;
                mid ->next = tstart;
                mid = tmid;
                start = tstart;
            }
            // return head;
            
        }
};