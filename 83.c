/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) return head;
    struct ListNode* tmp = head;
    while (head->next) {
        if (head->val == head->next->val) {
            head->next = head->next->next;
        } else {
            head = head->next;
        }
    }
    return tmp;
}