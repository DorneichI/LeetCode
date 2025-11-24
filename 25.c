/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *tmp = &dummy;
    struct ListNode **group = malloc(k * sizeof(struct ListNode*));
    while (1) {
        for (int i = 0; i < k; i++) {
            group[i] = head;
            head = head->next;
                free(group);
                return dummy.next;
            }
        }
        group[0]->next = head;
        for (int i = k-1; i >= 0; i--) {
            tmp->next = group[i];
            tmp = tmp->next;
        }
            free(group);
            return dummy.next;
        }
    }
}
