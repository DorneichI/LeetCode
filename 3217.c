/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubbleSort(int* nums, int numsSize) {
    int swapped;
    for (int i = 0; i < numsSize - 1; i++) {
        swapped = 0;
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(&nums[j], &nums[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

int binarySearch(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}


struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    bubbleSort(nums, numsSize);
    
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    int found;
    while (prev && prev->next) {
        found = binarySearch(nums, numsSize, prev->next->val);
        if (found >= 0) {
            prev->next = prev->next->next;
        } else {
            prev = prev->next;
        }
    }
    return dummy.next;
}