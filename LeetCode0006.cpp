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
	string convert(string s, int numRows) {
		if (numRows == 1 || s.length() < 3)
			return s;
		vector<string> records(numRows);
		int strIndex = 0, groupIndex = 0;
		bool goDown = true;
		for (size_t strIndex = 0; strIndex < s.length(); strIndex++)
		{
			records[groupIndex] += s.substr(strIndex, 1);
			if (goDown)
			{
				if (groupIndex == numRows - 1)
				{
					groupIndex--;
					goDown = !goDown;
				}
				else
				{
					groupIndex++;
				}
			}
			else
			{
				if (groupIndex == 0)
				{
					groupIndex++;
					goDown = !goDown;
				}
				else
				{
					groupIndex--;
				}
			}
		}
		string result;
		for (size_t groupIndex = 0; groupIndex < numRows; groupIndex++)
			result += records[groupIndex];
		return result;
	}
};

int main()
{
	Solution solution = Solution();
	string s = "PAYPALISHIRING";
	auto result = solution.convert(s, 4);
	for (auto &ch:result)
	{
		std::cout << ch;
	}
	return 0;
}