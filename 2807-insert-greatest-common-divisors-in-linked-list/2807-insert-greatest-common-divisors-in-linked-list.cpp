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
    int gcd(int a, int b) {
        int ans = 1;
        for (int i = 1; i <= min(a, b); i++) {
            if (a % i == 0 && b % i == 0)
                ans = i;
        }
        return ans;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head->next == nullptr)
            return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* prev = head;
        ListNode* curr = head->next;
        temp->next = new ListNode(prev->val);
        temp = temp->next;
        while (curr != nullptr) {
            ListNode* nextnode = curr->next;
            int toinsert = gcd(prev->val, curr->val);

            temp->next = new ListNode(toinsert);
            temp = temp->next;
            temp->next = new ListNode(curr->val);
            temp = temp->next;
            prev = curr;
            curr = nextnode;
        }
        temp->next = nullptr;
        return dummy->next;
    }
};