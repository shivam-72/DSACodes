/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
        return NULL;
        Node*curr=head;
        while(curr!=NULL){
          Node*next=curr->next;
         curr->next=new Node(curr->val);
         curr->next->next=next;
         curr=next;
        }
        Node*temp=head;
        while(temp!=NULL){
            //Node*next=temp->next;
            temp->next->random=(temp->random)?temp->random->next:NULL;
            temp=temp->next->next;
        }
        Node*ans=new Node(-1);
        Node*dummy=ans;
        temp=head;
        while(temp!=NULL){
         Node*next=temp->next;
         temp->next=temp->next->next;
         ans->next=next;
         ans=next;
         temp=temp->next;
        }
        return dummy->next;
    }
};