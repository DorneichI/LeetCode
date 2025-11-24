/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    int value = 0;
    while (head) {
        value = value * 2 + head->val;
        head = head->next;
    }
    return value;
}
