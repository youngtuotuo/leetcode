#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
Design a class to find the kth largest element in a stream. Note that it is the
kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the
stream of integers nums. int add(int val) Appends the integer val to the stream
and returns the element representing the kth largest element in the stream.

https://leetcode.com/problems/kth-largest-element-in-a-stream/
O(n log n + m log k), n = length of nums, m = add calls
O(n)
*/

class KthLargest {
  public:
    KthLargest(int k, vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        while (pq.size() > k) {
            pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }

  private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
};

int main(int argc, char *argv[]) {
    int k = 3;
    vector<int> nums = {4, 5, 8, 2};
    KthLargest *kl = new KthLargest(k, nums);
    cout << kl->add(3) << endl;
    cout << kl->add(5) << endl;
    cout << kl->add(10) << endl;
    cout << kl->add(9) << endl;
    cout << kl->add(4) << endl;
    return 0;
}
