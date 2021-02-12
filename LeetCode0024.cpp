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
	ListNode* swapPairs(ListNode* head) {
		if (!(head && head->next))
			return head;
		ListNode* preHead = new ListNode();
		preHead->next = head;
		ListNode* p0 = preHead;
		ListNode* p1 = head;
		ListNode* p2 = head->next;
		ListNode* p3 = p2->next;
		while (p2)
		{
			//swap
			p0->next = p2;
			p2->next = p1;
			p1->next = p3;
			//restore
			if (!p3)
				break;
			p0 = p1;
			p1 = p3;
			if (p3->next)
				p2 = p3->next;
			else
				break;
			p3 = p2->next;
		}
		return preHead->next;
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
	auto result = solution.swapPairs(l1);
	while (result)
	{
		std::cout << result->val << std::endl;
		result = result->next;
	}
	return 0;
}