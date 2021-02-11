#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1)
			return l2;
		if (!l2)
			return l1;
		ListNode* head = new ListNode(-1);
		ListNode* result_pre = head;
		while (l1 && l2)
		{
			if (l1->val > l2->val)
			{
				head->next = l2;
				l2 = l2->next;
			}
			else
			{
				head->next = l1;
				l1 = l1->next;
			}
			head = head->next;
		}
		if (l1)
			head->next = l1;
		else if (l2)
			head->next = l2;
		return result_pre->next;
	}
};

int main()
{
	Solution solution = Solution();
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(4);
	ListNode* l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);
	auto result = solution.mergeTwoLists(l1, l2);
	while (result)
	{
		std::cout << result->val << std::endl;
		result = result->next;
	}
	return 0;
}