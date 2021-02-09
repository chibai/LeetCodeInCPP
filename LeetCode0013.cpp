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
	int romanToInt(string s) {
		vector<int> intRecord = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		vector<string> strRecord = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int RomanNum = 0, sLen = s.size();
		for (size_t i = 0; i < sLen; i++)
		{
			if (s[i] == 'M')
			{
				RomanNum += 1000;
			}
			else if (s[i] == 'D')
			{
				RomanNum += 500;
			}
			else if (s[i] == 'C')
			{
				if (i < sLen - 1 && s[i + 1] == 'M')
				{
					RomanNum += 900;
					i++;
				}
				else if (i < sLen - 1 && s[i + 1] == 'D')
				{
					RomanNum += 400;
					i++;
				}
				else
				{
					RomanNum += 100;
				}
			}
			else if (s[i] == 'L')
			{
				RomanNum += 50;
			}
			else if (s[i] == 'X')
			{
				if (i < sLen - 1 && s[i + 1] == 'C')
				{
					RomanNum += 90;
					i++;
				}
				else if (i < sLen - 1 && s[i + 1] == 'L')
				{
					RomanNum += 40;
					i++;
				}
				else
				{
					RomanNum += 10;
				}
			}
			else if (s[i] == 'V')
			{
				RomanNum += 5;
			}
			else if (s[i] == 'I')
			{
				if (i < sLen - 1 && s[i + 1] == 'X')
				{
					RomanNum += 9;
					i++;
				}
				else if (i < sLen - 1 && s[i + 1] == 'V')
				{
					RomanNum += 4;
					i++;
				}
				else
				{
					RomanNum += 1;
				}
			}
		}
		return RomanNum;
	}
};

int main()
{
	Solution solution = Solution();
	auto result = solution.romanToInt("DCXXI");
	std::cout << result;
	return 0;
}