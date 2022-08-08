#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

 //Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resultHead = new ListNode();
        ListNode* resultP = resultHead;
        int addition = 0;
        int tmpResult = 0;
        while (l1 && l2)
        {
            tmpResult = l1->val + l2->val + addition;
            l1 = l1->next;
            l2 = l2->next;
            if (tmpResult > 9)
            {
                tmpResult -= 10;
                addition = 1;
            }
            else
            {
                addition = 0;
            }
            resultP->next = new ListNode(tmpResult);
            resultP = resultP->next;
        }
        while (l1)
        {
            tmpResult = l1->val + addition;
            l1 = l1->next;
            if (tmpResult > 9)
            {
                tmpResult -= 10;
                addition = 1;
            }
            else
            {
                addition = 0;
            }
            resultP->next = new ListNode(tmpResult);
            resultP = resultP->next;
        }
        while (l2)
        {
            tmpResult = l2->val + addition;
            l2 = l2->next;
            if (tmpResult > 9)
            {
                tmpResult -= 10;
                addition = 1;
            }
            else
            {
                addition = 0;
            }
            resultP->next = new ListNode(tmpResult);
            resultP = resultP->next;
        }
        if (addition == 1)
        {
            resultP->next = new ListNode(1);
        }
        return resultHead->next;
    }
};

int main()
{
    Solution solution = Solution();
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(6);
    l1->next->next->next = new ListNode(9);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    auto results = solution.addTwoNumbers(l1, l2);
    while (results)
    {
        std::cout << results->val << std::endl;
        results = results->next;
    }
    
    return 0;
}