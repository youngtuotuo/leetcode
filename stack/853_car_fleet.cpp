#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/* There are n cars going to the same destination along a one-lane road. The
destination is target miles away.

You are given two integer array position and speed, both of length n, where
position[i] is the position of the ith car and speed[i] is the speed of the ith
car (in miles per hour).

A car can never pass another car ahead of it, but it can catch up to it and
drive bumper to bumper at the same speed. The faster car will slow down to
match the slower car's speed. The distance between these two cars is ignored
(i.e., they are assumed to have the same position).

A car fleet is some non-empty set of cars driving at the same position and same
speed. Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will
still be considered as one car fleet.

Return the number of car fleets that will arrive at the destination.

https://leetcode.com/problems/car-fleet/

O(nlog n + n), O(n)
*/

class Solution {
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        int n = position.size();

        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.begin(), cars.end());

        double maxTime = 0.0;
        int result = 0;

        for (int i = n - 1; i >= 0; i--) {
            double time = cars[i].second;
            if (time > maxTime) {
                maxTime = time;
                result++;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    cout << Solution().carFleet(target, position, speed);
    return 0;
}
