// Merge two sorted linked lists and return it as a new list. The new list
// should be made by splicing together the nodes of the first two lists.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l = new ListNode(0);
        ListNode* cur = l;
        while (l1 != NULL || l2 != NULL) {
            cur->next = new ListNode(0);
            if (l1 != NULL && l2 != NULL) {
                if (l1->val < l2->val) {
                    cur->next->val = l1->val;
                    l1 = l1->next;
                } else {
                    cur->next->val = l2->val;
                    l2 = l2->next;
                }
            } else {
                if (l1) {
                    cur->next->val = l1->val;
                    l1 = l1->next;
                } else {
                    cur->next->val = l2->val;
                    l2 = l2->next;
                }
            }
            cur = cur->next;
        }
        ListNode* re = l->next;
        delete l;
        return re;
    }
};
