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
	string intToRoman(int num) {
		vector<int> intRecord = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		vector<string> strRecord = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		string RomanStr = "";
		for (size_t i = 0; i < 13; i++)
		{
			while (num >= intRecord[i])
			{
				num -= intRecord[i];
				RomanStr += strRecord[i];
			}
		}
		return RomanStr;
	}
};

int main()
{
	Solution solution = Solution();
	auto result = solution.intToRoman(3);
	for (auto &s:result)
	{
		std::cout << s;
	}
	return 0;
}