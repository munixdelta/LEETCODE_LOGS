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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int> mp;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* curr=head;
        while(curr!=nullptr){
            mp[curr->val]++;
            curr=curr->next;
        }
        curr=head;
        while(curr!=nullptr){
            if(mp.find(curr->val)!=mp.end() && mp[curr->val]==1){
                temp->next=new ListNode(curr->val);
                temp=temp->next;
            }
            curr=curr->next;
        }
        temp->next=nullptr;
        return dummy->next;
    }
};