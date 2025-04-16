class Node{
    public:
    Node*next;
    Node*prev;
    int val;
    int key;
    Node(int val,int key){
      this->val=val;
      this->key=key;
       next=NULL;
       prev=NULL;
    }
};
class LRUCache {
  private:
  public:
   Node* head=new Node(-1,-1);
   Node * tail=new Node(-1,-1);
   unordered_map<int,Node*>m;
   
    // Constructor for initializing the cache capacity with the given value.
    int size;
    LRUCache(int cap) {
        // code here
        head->next=tail;
        tail->prev=head;
        size=cap;
    }
    void addNode(Node *c){
       Node * nex=head->next;
       head->next=c;
       c->prev=head;
       c->next=nex;
       nex->prev=c;
    }
    void delNode(Node* d){
        Node*c=d->prev;
        Node*c2=d->next;
        c->next=c2;
        c2->prev=c;
    }
    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        if(m.find(key)==m.end()){
          return -1;  
        }
        Node *currnode=m[key];
        delNode(currnode);
        addNode(currnode);
        m[key]=head->next;
        return head->next->val;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        if(m.find(key)!=m.end()){
            Node * c=m[key];
            delNode(c);
            c->val=value;
            addNode(c);
            m[key]=head->next;
        }
        else{
          if(m.size()==size){
              Node*c=tail->prev;
              m.erase(c->key);
              delNode(c);
              Node* n=new Node(value,key);
              addNode(n);
              m[key]=n;
          }
          else{
              Node* n=new Node(value,key);
              addNode(n); 
              m[key]=n;
          }
        }
    }
};