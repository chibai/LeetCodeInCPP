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

class Solution{
public:
    string toLowerCase(string s) {
        /*
        string result;
        int gap = 'A' - 'a';
        for (auto&ch:s)
            if (ch >= 'A' and ch <='Z')
                result.push_back(char(ch-gap));
            else
                result.push_back(ch);
        return result;
        */
        for (auto &ch:s)
        {
            if (ch >= 'A' && ch <= 'Z')
                ch = char(ch - 'A' + 'a');
        }
        return s;
    }
};

int main()
{
    Solution solution;
    string s = "sdifujAFJ";
    std::cout << solution.toLowerCase(s) << std::endl;
    return 0;
}