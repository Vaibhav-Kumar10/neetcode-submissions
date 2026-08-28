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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode *cur = dummy, *temp1 = l1, *temp2 = l2;

        int carry = 0;
        while (temp1 != NULL || temp2 != NULL || carry != 0) {
            int v1 = (temp1 != NULL) ? temp1->val : 0;
            int v2 = (temp2 != NULL) ? temp2->val : 0;

            int val = v1 + v2 + carry;
            carry = val / 10;
            val = val % 10;
            cur->next = new ListNode(val);

            cur = cur->next;
            temp1 = (temp1 != NULL) ? temp1->next : temp1;
            temp2 = (temp2 != NULL) ? temp2->next : temp2;
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};