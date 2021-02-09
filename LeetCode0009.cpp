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
	bool isPalindrome(int x) {
		if (x < 0 || (x % 10 == 0 && x != 0))
			return false;

		int reverseNumber = 0;
		while (x > reverseNumber)
		{
			reverseNumber = 10 * reverseNumber + x % 10;
			x = x / 10;
		}
		return (x == reverseNumber) || (x == reverseNumber / 10);
	}
};

int main()
{
	Solution solution = Solution();
	auto result = solution.isPalindrome(123454321);
	std::cout << result;
	return 0;
}