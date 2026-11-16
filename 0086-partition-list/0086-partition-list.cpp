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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* curr=head;
        ListNode* dummy2=new ListNode(-1);
        ListNode* temp2=dummy2;
        while(curr!=nullptr){
            if(curr->val<x){
                temp->next=new ListNode(curr->val);
                temp=temp->next;
            }
            else{
                temp2->next=new ListNode(curr->val);
                temp2=temp2->next;
            }
            curr=curr->next;
        }
        temp->next=dummy2->next;
        temp2->next=nullptr;
        return dummy->next;
    }
};