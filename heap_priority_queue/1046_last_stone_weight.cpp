#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/* You are given an array of integers stones where stones[i] is the weight of
the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two
stones and smash them together. Suppose the heaviest two stones have weights x
and y with x <= y. The result of this smash is:

    If x == y, both stones are destroyed, and If x != y, the stone of weight x
    is destroyed, and the stone of weight y has new weight y - x. At the end of
    the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left,
return 0.
https://leetcode.com/problems/last-stone-weight/
O(nlog n), O(n)
*/

class Solution {
  public:
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int> pq;
        for (int s : stones) {
            pq.push(s);
        }
        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (y > x) {
                pq.push(y - x);
            }
        }
        if (pq.empty()) {
            return 0;
        }
        return pq.top();
    }
};

int main(int argc, char *argv[]) {
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << Solution().lastStoneWeight(stones) << endl;
    return 0;
}
