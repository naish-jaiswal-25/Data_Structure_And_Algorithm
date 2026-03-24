class Solution {
public:
    Node* flatten(Node* head) {
        flattenDFS(head);
        return head;
    }

    Node* flattenDFS(Node* head) {
        Node* curr = head;
        Node* last = NULL;

        while (curr) {
            Node* next = curr->next;

            if (curr->child) {
                Node* childHead = curr->child;
                Node* childTail = flattenDFS(childHead);

                curr->next = childHead;
                childHead->prev = curr;
                curr->child = NULL;

                if (next) {
                    childTail->next = next;
                    next->prev = childTail;
                }

                last = childTail;
                curr = childTail;
            } else {
                last = curr;
            }

            curr = curr->next;
        }

        return last;
    }
};