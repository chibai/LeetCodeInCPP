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
		if (x < 0)
			return false;
		
		int digitalCounts = 0, tmp = x, left, right;
		while (tmp != 0)
		{
			tmp = tmp / 10;
			digitalCounts++;
		}
		for (int i = 1; i <= digitalCounts / 2; i++)
		{
			right = x % 10;
			x = x / 10;
			left = x / int(pow(10, digitalCounts - 2 * i)) % 10;
			if (left != right)
				return false;
			
		}
		return true;
	}
};

int main()
{
	Solution solution = Solution();
	auto result = solution.isPalindrome(123454321);
	std::cout << result;
	return 0;
}