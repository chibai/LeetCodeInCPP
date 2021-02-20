#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <bitset>
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
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		else if (num1 == "1")
			return num2;
		else if (num2 == "1")
			return num1;
		int size1 = num1.size(), size2 = num2.size();
		vector<int> result(size1 + size2, 0);
		for (int i = 0; i < size1; i++)
		{
			int n1 = num1[size1 - 1 - i] - '0';
			for (int j = 0; j < size2; j++)
			{
				int n2 = num2[size2 - 1 - j] - '0';
				result[i + j] += n1 * n2;
			}
		}
		// process result
		string resultStr = "";
		for (int i = 0; i < result.size() - 1; i++)
		{
			if (result[i] > 9)
			{
				result[i + 1] += result[i] / 10;
				result[i] = result[i] % 10;
			}
			resultStr.push_back(result[i] + '0');
		}
		if (result[result.size() - 1] != 0)
			resultStr.push_back(result[result.size() - 1] + '0');
		std::reverse(resultStr.begin(), resultStr.end());
		return resultStr;
	}
	
};

int main()
{
	Solution solution = Solution();
	auto result = solution.multiply("123", "456");
	std::cout << result << std::endl;
	return 0;
}