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
        if(head==nullptr || head->next==nullptr)return head;
        if(k==0)return head;
        int size=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            temp=temp->next;
            size++;
        }
        k=k%size;
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        ListNode* findk=head;
        for(int i=0;i<size-k;i++){
            findk=findk->next;
        }
        while(findk!=nullptr){
            curr->next=new ListNode(findk->val);
            findk=findk->next;
            curr=curr->next;
        }
        temp=head;
        for(int i=1;i<=size-k;i++){
            curr->next=new ListNode(temp->val);
            temp=temp->next;
            curr=curr->next;
        }
        curr->next=nullptr;
        return dummy->next;
    }
};