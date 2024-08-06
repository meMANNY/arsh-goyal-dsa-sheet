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

class comper
{

public:
    vector<ListNode *> &arr;
    comper(vector<ListNode *> &a) : arr(a) {}

    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto cmp = comper(lists);

        priority_queue<ListNode *, vector<ListNode *>, comper> pq(cmp);

        for (ListNode *list : lists)
        {
            if (list != nullptr)
            {
                pq.push(list);
            }
        }
        ListNode head(0);
        ListNode *tail = &head;

        while (!pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next != nullptr)
            {
                pq.push(node->next);
            }
        }

        return head.next;
    }
};