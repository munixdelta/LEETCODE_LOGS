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
        if(head==nullptr)return head;
        unordered_map<Node*,Node*> mp;//old node(curr),new node(temp->next)
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        Node* curr=head;
        while(curr!=nullptr){
            temp->next=new Node(curr->val);
            mp[curr]=temp->next;
            temp=temp->next;
            curr=curr->next;
            
        }
        temp->next=nullptr;
        curr=head;
        temp=dummy->next;
        while(temp!=nullptr){
            if(curr->random!=nullptr)
                temp->random=mp[curr->random];
            temp=temp->next;
            curr=curr->next;
        }
        return dummy->next;
    }
};