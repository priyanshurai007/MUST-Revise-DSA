class Node{
public:
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int _key, int _value){
        key=_key;
        value=_value;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*> mp;
    int cap=0;
    Node* head;
    Node* tail;

    void insertAtHead(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next=node;
        node->next->prev=node;
    }

    void deleteNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;    
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* node=mp[key];
        deleteNode(node);
        insertAtHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cap==0) return;
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            deleteNode(node);
            insertAtHead(node);
            node->value=value;
        }else{
            Node* node=new Node(key,value);
            if(mp.size()==cap){
                Node* lru=tail->prev;
                deleteNode(lru);
                mp.erase(lru->key);
                mp[key]=node;
                insertAtHead(node);
            }else{
                mp[key]=node;
                insertAtHead(node);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */