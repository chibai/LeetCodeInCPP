#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head->next)
			return nullptr;
		ListNode* first = new ListNode(-1);
		first->next = head;
		ListNode* second = first;
		while (n > 0)
		{
			second = second->next;
			n--;
		}
		while (second->next)
		{
			first = first->next;
			second = second->next;
		}
		first->next = first->next->next;
		return first->val == -1 ? first->next: head;
	}
};

int main()
{
	Solution solution = Solution();
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	auto result = solution.removeNthFromEnd(head, 5);
	while (result)
	{
		std::cout << result->val << std::endl;
		result = result->next;
	}
	return 0;
}