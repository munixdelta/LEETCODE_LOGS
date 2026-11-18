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
    int pairSum(ListNode* head) {
        vector<int> pairsum;
        ListNode* curr = head;
        while (curr != nullptr) {
            pairsum.push_back(curr->val);
            curr = curr->next;
        }
        int sum=0;
        int index=pairsum.size()-1;
        for(int i=0;i<pairsum.size()/2;i++){
            if(pairsum[i]+pairsum[index]>sum){
                sum=pairsum[i]+pairsum[index];
            }
            index--;
        }
        return sum;
    }
};