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
        if(head==NULL)
        return NULL;
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*next=NULL;
        int count=0;
        while(curr!=NULL&&count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(head!=NULL&&count==k)
        head->next=reverseKGroup(next,k);
        else{
        ListNode*curr=prev;
        ListNode*prev=NULL;
        ListNode*next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        }
        return prev;
    }
};