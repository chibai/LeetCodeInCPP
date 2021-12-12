#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <bitset>
using namespace std;

class TopVotedCandidate {
private:
    vector<int> timeline;
    vector<int> topResult;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> voteRecords;
        timeline.push_back(times[0]);
        topResult.push_back(persons[0]);
        voteRecords[persons[0]] = 1;
        int lastResult = topResult[0];
        for (size_t i = 1; i < times.size(); i++)
        {
            int currentVote = persons[i];
            if (voteRecords.find(currentVote) == voteRecords.end())
                voteRecords[currentVote] = 1;
            else   
                voteRecords[currentVote]++;
            if ((currentVote != lastResult) && (voteRecords[currentVote] >= voteRecords[lastResult]))
            {
                lastResult = currentVote;
                topResult.push_back(currentVote);
                timeline.push_back(times[i]);
            }
        }
        
        /*
        int maxCandidate = *max_element(persons.begin(), persons.end());
        vector<int> candidates = vector<int>(maxCandidate + 1);
        timeline.push_back(times[0]);
        topResult.push_back(persons[0]);
        int lastResult = persons[0];
        candidates[lastResult] += 1;
        for (size_t i = 1; i < times.size(); i++)
        {
            int current_vote = persons[i];
            candidates[current_vote] += 1;
            if (candidates[current_vote] >= candidates[lastResult])
            {
                lastResult = current_vote;
                topResult.push_back(current_vote);
                timeline.push_back(times[i]);
            }
        }
        */
    }
    
    int q(int t) {
        if (t == timeline[0])
            return topResult[0];
        else if (t >= timeline[timeline.size() - 1])
            return topResult[timeline.size() - 1];
        int l = 0, r = timeline.size();
        int m;
        while (l < r)
        {
            m = (l + r) / 2;
            if (t < timeline[m])
                r = m;
            else if (t > timeline[m])
                l = m + 1;
            else
                break;
        }
        m = (l + r) / 2;
        if (t == timeline[m])
            return topResult[m];
        else
            return topResult[m - 1];
        
    }
};

int main()
{
    vector<int> persons = vector<int>{0,1,1,0,0,1,0};
    vector<int> times = vector<int>{0,5,10,15,20,25,30};
    TopVotedCandidate tvc = TopVotedCandidate(persons, times);
    vector<int> timeVector = vector<int>{3,12,25,15,24,8};
    for (auto &t:timeVector)
        std::cout << tvc.q(t) << std::endl;
}