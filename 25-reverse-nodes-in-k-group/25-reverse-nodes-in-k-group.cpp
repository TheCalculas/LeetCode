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
        if(head == NULL || head->next==NULL) {
        return head;
        }
        if(k<=1){
            return head;
        }
        
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        if(count<k){
            return head;
        }else{
            temp=head;
            count=0;
        while(temp!=NULL && count<k){
            forward=temp->next;
            temp->next=prev;
            prev=temp;
            temp=forward;
            count++;
        }
        
        
        if(forward!=NULL){
            head->next=reverseKGroup(forward,k);
        }
        return prev;
        }
    }
};