class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge cases
        if (!head || !head->next || k == 0)
            return head;

        // Step 1: Find length
        int n = 1;
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
            n++;
        }

        // Step 2: Reduce k
        k = k % n;
        if (k == 0) return head;   // VERY IMPORTANT

        // Step 3: Make circular
        temp->next = head;

        // Step 4: Find new tail
        int steps = n - k;
        ListNode* newTail = head;

        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // Step 5: Break circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};