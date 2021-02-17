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
	bool isValidSudoku(vector<vector<char>>& board) {
		set<char> record;
		// check by row
		for (auto row_vec:board)
		{
			record.clear();
			for (auto ch:row_vec)
			{
				if ('0' <= ch && ch <= '9')
					if (record.find(ch) == record.end())
						record.insert(ch);
					else
						return false;
			}
		}
		// check by col
		for (size_t i = 0; i < board.size(); i++)
		{
			record.clear();
			for (size_t j = 0; j < board.size(); j++)
			{
				char ch = board[j][i];
				if ('0' <= ch && ch <= '9')
					if (record.find(ch) == record.end())
						record.insert(ch);
					else
						return false;
			}

		}
		// check by box
		for (size_t i = 0; i < board.size(); i+=3)
		{
			for (size_t j = 0; j < board.size(); j+=3)
			{
				record.clear();
				for (size_t ii = 0; ii < 3; ii++)
				{
					for (size_t jj = 0; jj < 3; jj++)
					{
						char ch = board[i + ii][j + jj];
						if ('0' <= ch && ch <= '9')
							if (record.find(ch) == record.end())
								record.insert(ch);
							else
								return false;
					}
				}
			}
		}
		return true;
	}
	bool isValidSudokuOneScan(vector<vector<char>>& board) {
		vector<set<char>> rowSet(board.size());
		vector<set<char>> colSet(board.size());
		vector<set<char>> boxSet(board.size() * board.size() / 9);
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board.size(); j++)
			{
				char ch = board[i][j];
				if ('0' <= ch && ch <= 'ch')
				{	// check row
					if (rowSet[i].find(ch) == rowSet[i].end())
						rowSet[i].insert(ch);
					else
						return false;
					// check col
					if (colSet[j].find(ch) == colSet[j].end())
						colSet[j].insert(ch);
					else
						return false;
					// check box
					int boxIndex = int(i / 3) * 3 + j / 3;
					if (boxSet[boxIndex].find(ch) == boxSet[boxIndex].end())
						boxSet[boxIndex].insert(ch);
					else
						return false;
				}
			}
		}
		return true;
	}
};

int main()
{
	Solution solution = Solution();
	vector<char> row1{ '5','3','.','.','7','.','.','.','.' };
	vector<char> row2{ '6','.','.','1','9','5','.','.','.' };
	vector<char> row3{ '.','9','8','.','.','.','.','6','.' };
	vector<char> row4{ '8','.','.','.','6','.','.','.','3' };
	vector<char> row5{ '4','.','.','8','.','3','.','.','1' };
	vector<char> row6{ '7','.','.','.','2','.','.','.','6' };
	vector<char> row7{ '.','6','.','.','.','.','2','8','.' };
	vector<char> row8{ '.','.','.','4','1','9','.','.','5' };
	vector<char> row9{ '.','.','.','.','8','.','.','7','9' };
	vector<vector<char>> nums{ row1, row2, row3, row4, row5, row6, row7, row8, row9 };
	auto result = solution.isValidSudokuOneScan(nums);
	std::cout << result << std::endl;
	return 0;
}