"""
Given an array of meeting time intervals consisting of start and end times
[[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

https://leetcode.com/problems/meeting-rooms/
O(n long n + n), O(1)
"""

class Solution:
    def canAttendMeetings(self, intervals):
        intervals.sort(key=lambda x: x[0])

        for i in range(1, len(intervals)):
            i1 = intervals[i - 1]
            i2 = intervals[i]
            if i1[1] > i2[0]:
                return False

        return True


if __name__ == "__main__":
    intervals = [(0,30),(5,10),(15,20)]
    print(Solution().canAttendMeetings(intervals))
