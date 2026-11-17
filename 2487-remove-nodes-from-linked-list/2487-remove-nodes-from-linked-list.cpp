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
    ListNode* removeNodes(ListNode* head) {
        if(head->next==nullptr)return head;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr){
            ListNode* nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        int currmax=prev->val;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        temp->next=new ListNode(currmax);
        temp=temp->next;
        while(prev->next!=nullptr){
            if(prev->next->val>=currmax){
                temp->next=new ListNode(prev->next->val);
                currmax=prev->next->val;
                temp=temp->next;
            }
            prev=prev->next;
        }
        temp->next=nullptr;
        ListNode* newhead=dummy->next;
        prev=nullptr;
        curr=newhead;
        while(curr!=nullptr){
            ListNode* nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        return prev;
    }
};