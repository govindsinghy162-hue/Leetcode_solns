
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        ListNode* temp = head;
        int n = 1;

        // Find length and last node
        while (temp->next != nullptr) {
            temp = temp->next;
            n++;
        }

        // Connect last node to head
        temp->next = head;

        // Find the new last node
        k = k % n;
        int steps = n - k;

        ListNode* newLast = head;

        for (int i = 1; i < steps; i++) {
            newLast = newLast->next;
        }

        // Break the circle
        ListNode* newHead = newLast->next;
        newLast->next = nullptr;

        return newHead;
    }
};
