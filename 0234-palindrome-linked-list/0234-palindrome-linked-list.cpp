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
    bool isPalindrome(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* curr1=head;
        while(curr1!=nullptr){
            temp->next=new ListNode(curr1->val);
            temp=temp->next;
            curr1=curr1->next;
        }
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr){
            ListNode* nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        ListNode* first=dummy->next;
        ListNode* second=prev;
        while(first!=nullptr &&  second!=nullptr){
            if(first->val!=second->val)return false;
            first=first->next;
            second=second->next;
        }
        return true;
    }
};