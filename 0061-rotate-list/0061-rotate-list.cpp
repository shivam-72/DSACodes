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
    ListNode* rotateRight(ListNode* head, int k) {
        int c=1;
        if(k==0||head==NULL||head->next==NULL)
        return head;
        ListNode*curr=head;
       while(curr->next){
           curr=curr->next;
           c++;
       }
       k=k%c;
       int d=c-k;
       curr->next=head;
       while(d--){
           curr=curr->next;
       }
       head=curr->next;
       curr->next=NULL;
       return head;
    }
};