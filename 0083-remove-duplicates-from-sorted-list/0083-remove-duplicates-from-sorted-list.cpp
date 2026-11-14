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
        if(head==nullptr || head->next==nullptr)return head;
        unordered_map<int,int> mp;
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ListNode* nextnode=temp->next;
            if(mp.find(temp->val)!=mp.end()){
                ListNode* todel=temp;
                prev->next=nextnode;
                temp=nextnode;
                delete todel;
            }
            else{
                mp[temp->val]=1;
                prev=temp;
                temp=nextnode;
            }
        }
        return head;
    }
};