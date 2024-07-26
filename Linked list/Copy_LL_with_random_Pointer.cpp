/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;

        unordered_map<Node *, Node *> mpp;
        Node *current = head;
        while (current)
        {
            mpp[current] = new Node(current->val);
            current = current->next;
        }
        current = head;
        while (current)
        {
            mpp[current]->next = mpp[current->next];
            mpp[current]->random = mpp[current->random];
            current = current->next;
        }
        return mpp[head];
    }
};