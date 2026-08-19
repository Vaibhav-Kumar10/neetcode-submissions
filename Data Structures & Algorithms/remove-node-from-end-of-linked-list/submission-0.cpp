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
        ListNode *slow = head, *fast = head, *temp;
        while (n > 0 && fast != NULL) {
            fast = fast->next;
            n--;
        }
        // If fast reaches last node => the nth node from last is the first node
        if (fast == NULL) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        temp = slow->next;
        slow->next = temp->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
};
