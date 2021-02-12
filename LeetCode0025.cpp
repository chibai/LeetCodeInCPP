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
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!(head && head->next))
			return head;
		if (k < 2)
			return head;
		int groupSize = k;
		ListNode* preHead = new ListNode();
		preHead->next = head;
		ListNode* groupTail = preHead;
		while (groupSize > 0)
		{
			if (groupTail->next)
				groupTail = groupTail->next;
			else
				return head;
			groupSize--;
		}
		ListNode* preGroupHead = preHead;
		ListNode* groupHead = head;
		ListNode* postGroupTail = groupTail->next;
		while (1)
		{
			reverseSeg(preGroupHead, groupHead, postGroupTail);
			//swap head and tail
			auto tmp = groupTail;
			groupTail = groupHead;
			groupHead = tmp;
			//scan to next group
			groupSize = k;
			while (groupSize > 0)
			{
				if (groupTail->next)
					groupTail = groupTail->next;
				else
					return preHead->next;
				preGroupHead = preGroupHead->next;
				groupSize--;
			}
			groupHead = preGroupHead->next;
			postGroupTail = groupTail->next;
		}
		return nullptr;
	}
	
	void reverseSeg(ListNode* preGroupHead, ListNode* groupHead, ListNode* postGroupTail)
	{
		ListNode* p1 = groupHead;
		ListNode* p2 = groupHead->next;
		while (p2 != postGroupTail)
		{
			ListNode* tmp = p2;
			p2 = p2->next;
			tmp->next = p1;
			p1 = tmp;
		}
		preGroupHead->next = p1;
		groupHead->next = postGroupTail;
	}
};

int main()
{
	Solution solution = Solution();
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	l1->next->next->next = new ListNode(4);
	l1->next->next->next->next = new ListNode(5);
	l1->next->next->next->next->next = new ListNode(6);
	auto result = solution.reverseKGroup(l1, 4);
	while (result)
	{
		std::cout << result->val << std::endl;
		result = result->next;
	}
	return 0;
}