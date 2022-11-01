#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
Given an array of meeting time intervals consisting of start and end times
[[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all
meetings.

https://leetcode.com/problems/meeting-rooms/
O(n log n + n), O(1)
*/

class Solution {
  public:
    bool canAttendMeetings(vector<vector<int>> &intervals) {
        if (intervals.empty()) {
            return true;
        }

        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < intervals.size() - 1; i++) {
            if (intervals[i - 1][1] > intervals[i][0]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    cout << Solution().canAttendMeetings(intervals) << endl;
    return 0;
}
