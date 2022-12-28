from typing import List


"""
Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have to
wait after the ith day to get a warmer temperature. If there is no future day
for which this is possible, keep answer[i] == 0 instead.

https://leetcode.com/problems/daily-temperatures/
O(n), O(n)
"""


class Solution:
    def dailyTemeratures(self, temperatures: List[int]) -> List[int]:
        stk = []
        result = [0 for _ in range(len(temperatures))]
        for currDay, currTemp in enumerate(temperatures):
            while len(stk) != 0 and stk[-1][1] < currTemp:
                prevDay = stk.pop()[0]
                result[prevDay] = currDay - prevDay
            stk.append((currDay, currTemp))
        return result


if __name__ == "__main__":
    temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
    print(Solution().dailyTemeratures(temperatures))
