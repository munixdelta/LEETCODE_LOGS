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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int size=0;
        while(temp!=nullptr){
            temp=temp->next;
            size++;
        }
        if(size<=1)return nullptr;
        ListNode* todel=head;
        ListNode* prev=nullptr;
        for(int i=0;i<size-n;i++){
            prev=todel;
            todel=todel->next;
        }
        if(todel==head){
            head=head->next;
            return head;
        }
        prev->next=todel->next;
        delete todel;
        return head;
    }
};