/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* middle = head;
    while (head && head->next) {
        middle = middle->next;
        head = head->next->next;
    }
    return middle;
}