/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* current = &dummy;
    struct ListNode* returnNode;
    while (1) {
        while(current->next->val != 0) {
            current->val += current->next->val;
            current->next = current->next->next;
        }
        if (current->next->next) {
            current = current->next;
        } else {
            current->next = NULL;
            break;
        }
    }
    return dummy.next;
}