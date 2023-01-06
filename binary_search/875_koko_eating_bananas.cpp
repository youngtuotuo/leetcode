#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

/* Koko loves to eat bananas. There are n piles of bananas, the ith pile has
piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses
some pile of bananas and eats k bananas from that pile. If the pile has less
than k bananas, she eats all of them instead and will not eat any more bananas
during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas
before the guards return.

Return the minimum integer k such that she can eat all the bananas within h
hours.

https://leetcode.com/problems/koko-eating-bananas/
O(n x log m), n = #piles, m = max # in a pile
O(1)
*/

class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int n(piles.size());

        int low(1), high(0);
        for (int i = 0; i < n; i++) {
            high = max(high, piles[i]);
        }
        int result(high);

        while (low <= high) {
            int k(low + (high - low) / 2);
            long int hours = 0;
            for (int i = 0; i < n; i++) {
                hours += ceil((double)piles[i] / k);
            }
            if (hours <= h) {
                result = min(result, k);
                high = k - 1;
            } else {
                low = k + 1;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    vector<int> piles({3, 6, 7, 11});
    int h(8);
    cout << Solution().minEatingSpeed(piles, h) << endl;
    return 0;
}
