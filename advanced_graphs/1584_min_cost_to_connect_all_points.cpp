#include <climits>
#include <iostream>
#include <limits.h>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/* You are given an array points representing integer coordinates of some points
on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan
distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute
value of val.

Return the minimum cost to make all points connected. All points are connected
if there is exactly one simple path between any two points.
https://leetcode.com/problems/min-cost-to-connect-all-points/

O(n^2), O(n) */

class Solution {
  public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        int n = points.size();
        int edgesUsed = 0;

        // track visited nodes
        vector<bool> inMST(n);
        // initialize minimal distance
        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;

        // final answer
        int result = 0;

        while (edgesUsed < n) {
            int currMinEdge = INT_MAX;
            int currNode = -1;

            // greedily pick lowest cost node not in MST
            for (int i = 0; i < n; i++) {
                if (!inMST[i] && currMinEdge > minDist[i]) {
                    currMinEdge = minDist[i];
                    currNode = i;
                }
            }

            result += currMinEdge;
            edgesUsed++;
            inMST[currNode] = true;

            // update adj nodes of curr node
            for (int i = 0; i < n; i++) {
                int cost = abs(points[currNode][0] - points[i][0]) +
                           abs(points[currNode][1] - points[i][1]);

                if (!inMST[i] && minDist[i] > cost) {
                    minDist[i] = cost;
                }
            }
        }
        return result;
    }
};

int main(int argc, char *argv[])

{
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    cout << Solution().minCostConnectPoints(points) << endl;
    return 0;
}
