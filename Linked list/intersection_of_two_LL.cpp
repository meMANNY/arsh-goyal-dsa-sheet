/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    int getdiff(ListNode *headA, ListNode *headB)
    {
        int len1 = 0;
        int len2 = 0;
        while (headA != NULL)
        {
            len1++;
            headA = headA->next;
        }
        while (headB != NULL)
        {
            len2++;
            headB = headB->next;
        }
        return len1 - len2;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;
        int diff = getdiff(headA, headB);
        if (diff < 0)
        {
            while (diff++ != 0)
            {
                headB = headB->next;
            }
        }
        else
        {
            while (diff-- != 0)
            {
                headA = headA->next;
            }
        }
        while (headA != NULL)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};