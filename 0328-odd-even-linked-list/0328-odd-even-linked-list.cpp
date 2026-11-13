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
    ListNode* oddEvenList(ListNode* head) {
        int size=0;
        ListNode* curr=head;
        while(curr!=nullptr){
            curr=curr->next;
            size++;
        }
        if(size<=2)return head;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            temp->next=new ListNode(fast->val);
            temp=temp->next;
            fast=fast->next->next;
        }
        if(size%2!=0){
            temp->next=new ListNode(fast->val);
            temp=temp->next;
        }
        fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            temp->next=new ListNode(fast->val);
            temp=temp->next;
            fast=fast->next->next;
        }
        if(size%2==0){
            temp->next=new ListNode(fast->val);
            temp=temp->next;
        }
        temp->next=nullptr;
        return dummy->next;
    }
};