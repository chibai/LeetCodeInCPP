#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

//Definition for singly linked list
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
		ListNode *resultNode = new ListNode();
		ListNode *head = resultNode;
		int carry = 0, current = 0;
		while (l1 && l2)
		{
			current = l1->val + l2->val + carry;
			if (current >= 10)
			{
				carry = 1;
				current = current - 10;
			}
			else
			{
				carry = 0;
			}
			resultNode->next = new ListNode(current);
			resultNode = resultNode->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1)
		{
			current = l1->val + carry;
			if (current >= 10)
			{
				carry = 1;
				current = current - 10;
			}
			else
			{
				carry = 0;
			}
			resultNode->next = new ListNode(current);
			resultNode = resultNode->next;
			l1 = l1->next;
		}
		while (l2)
		{
			current = l2->val + carry;
			if (current >= 10)
			{
				carry = 1;
				current = current - 10;
			}
			else
			{
				carry = 0;
			}
			resultNode->next = new ListNode(current);
			resultNode = resultNode->next;
			l2 = l2->next;
		}
		if (carry == 1)
		{
			resultNode->next = new ListNode(1);
		}
		return head->next;
	}
};

int main()
{
	Solution solution = Solution();
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	ListNode* l2 = new ListNode(5);
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