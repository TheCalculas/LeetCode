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
    int pairSum(ListNode* head) {
        int n = 0;
        auto h = head;
        while(h)
        {
            h = h->next;
            n++;
        }
        // n has the size of the linked list now
        vector<int> v(n/2, 0);
        h = head;
        for(int i = 0; h&& i<(n/2); h=h->next, i++)
        {
            v[i%(n/2)] += h->val;
        }
        reverse(v.begin(), v.end());
        for(int i = 0; h&& i<(n/2); h=h->next, i++)
        {
            v[i%(n/2)] += h->val;
        }
        for(auto x: v) cout<<x<<" ";
        cout<<endl;
        return *max_element(v.begin(), v.end());
    }
};