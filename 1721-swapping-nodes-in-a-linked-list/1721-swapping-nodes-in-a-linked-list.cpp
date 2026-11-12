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
    ListNode* swapNodes(ListNode* head, int k) {
        int size=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            temp=temp->next;
            size++;
        }
        ListNode* firstk=head;
        for(int i=1;i<k;i++){
            firstk=firstk->next;
        }
        ListNode* lastk=head;
        for(int i=1;i<=size-k;i++){
            lastk=lastk->next;
        }
        int firstval=firstk->val;
        int secondval=lastk->val;
        lastk->val=firstval;
        firstk->val=secondval;
        return head;
    }
};