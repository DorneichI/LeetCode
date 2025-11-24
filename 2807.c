/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    struct ListNode* returnHead = head;
    while(head->next) {
        int a, b, r, gcd;
        if (head->val < head->next->val) {
            a = head->val;
            b = head->next->val;
        } else {
            a = head->next->val;
            b = head->val;
        }
        r = a;
        while (r != 0) {
            gcd = r;
            r = a % b;
            a = b;
            b = r;
        }
        struct ListNode* gcdNode = malloc(sizeof(struct ListNode));
        gcdNode->val = gcd;
        gcdNode->next = head->next;
        head->next = gcdNode;
        head = head->next->next;
    }
    return returnHead;
}