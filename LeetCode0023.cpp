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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
			return nullptr;
		return mergesort(lists, 0, lists.size() - 1);
	}
	ListNode* mergesort(vector<ListNode*>& lists, int left, int right)
	{
		if (left == right)
			return lists[left];
		else if (left + 1 == right)
			return merge2Lists(lists[left], lists[right]);
		else
		{
			int mid = (left + right) / 2;
			ListNode* left_part = mergesort(lists, left, mid);
			ListNode* right_part = mergesort(lists, mid + 1, right);
			return merge2Lists(left_part, right_part);
		}
	}

	ListNode* merge2Lists(ListNode* l1, ListNode* l2)
	{
		ListNode* head = new ListNode(-1);
		ListNode* current = head;
		while (l1 && l2)
		{
			if (l1 ->val > l2->val)
			{
				current->next = l2;
				l2 = l2->next;
			}
			else
			{
				current->next = l1;
				l1 = l1->next;
			}
			current = current->next;
		}
		if (l1)
			current->next = l1;
		else if (l2)
			current->next = l2;
		return head->next;
	}
	
};

int main()
{
	Solution solution = Solution();
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(5);
	ListNode* l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);
	ListNode* l3 = new ListNode(2);
	l3->next = new ListNode(6);
	vector<ListNode*> lists{l1, l2, l3};
	auto result = solution.mergeKLists(lists);
	while (result)
	{
		std::cout << result->val << std::endl;
		result = result->next;
	}
	return 0;
}