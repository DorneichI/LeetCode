/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void merge(struct ListNode* head, int mid, int length) {
    int* leftList = malloc(mid * sizeof(int));
    int* rightList = malloc((length - mid) * sizeof(int));

    struct ListNode* cpy = head;
    int i;
    for (i = 0; i < mid; i++) {
        leftList[i] = cpy->val;
        cpy = cpy->next;
    }
    for (; i < length; i++) {
        rightList[i - mid] = cpy->val;
        cpy = cpy->next;
    }

    cpy = head;
    i = 0;
    int j = 0;
    while (i < mid && j < length - mid) {
        if (leftList[i] < rightList[j]) cpy->val = leftList[i++];
        else cpy->val = rightList[j++];
        cpy = cpy->next;
    }
    while (i < mid) {
        cpy->val = leftList[i++];
        cpy = cpy->next;
    }
    while (j < length - mid) {
        cpy->val = rightList[j++];
        cpy = cpy->next;
    }
    free(leftList);
    free(rightList);
}

void mergeSort(struct ListNode* head, int length) {
    if (length > 1) {
        int mid = length / 2;
        struct ListNode* rightHead = head;
        for (int i = 0; i < mid; i++) {
            rightHead = rightHead->next;
        }
        
        mergeSort(head, mid);
        mergeSort(rightHead, length - mid);
        merge(head, mid, length);
    }
}

struct ListNode* sortList(struct ListNode* head) {
    int length;
    struct ListNode* cpy = head;
    for (length = 0; cpy; length++) cpy = cpy->next;
    mergeSort(head, length);
    return head;
}

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */
// void merge(int* array, int left, int mid, int right) {
//     int i, j, k;
//     int leftSize = mid - left + 1;
//     int rightSize = right - mid;

//     int* leftCopy = malloc(leftSize * sizeof(int));
//     int* rightCopy = malloc(rightSize * sizeof(int));

//     for (i = 0; i < leftSize; i++) {
//         leftCopy[i] = array[left + i];
//     }
//     for (j = 0; j < rightSize; j++) {
//         rightCopy[j] = array[mid + 1 + j];
//     }

//     i = 0;
//     j = 0;
//     k = left;
//     while (i < leftSize && j < rightSize) {
//         if (leftCopy[i] < rightCopy[j]) array[k++] = leftCopy[i++];
//         else array[k++] = rightCopy[j++];
//     }
//     while (i < leftSize) {
//         array[k++] = leftCopy[i++];
//     }
//     while (j < rightSize) {
//         array[k++] = rightCopy[j++];
//     }
//     free(leftCopy);
//     free(rightCopy);
// }

// void mergeSort(int* array, int left, int right) {
//     if (left < right) {
//         int mid = left + (right - left) / 2;
//         mergeSort(array, left, mid);
//         mergeSort(array, mid + 1, right);

//         merge(array, left, mid, right);
//     }
// }

// struct ListNode* sortList(struct ListNode* head) {
//     int length;
//     struct ListNode* cpy = head;
//     for (length = 0; cpy; length++) cpy = cpy->next;
//     int* array = malloc(length * sizeof(int));
//     cpy = head;
//     for (length = 0; cpy; length++) {
//         array[length] = cpy->val;
//         cpy = cpy->next;
//     }
//     mergeSort(array, 0, length - 1);
//     cpy = head;
//     for (length = 0; cpy; length++) {
//         cpy->val = array[length];
//         cpy = cpy->next;
//     }
//     free(array);
//     return head;
// }