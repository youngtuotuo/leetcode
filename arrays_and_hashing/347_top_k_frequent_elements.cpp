#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
  // O(n), O(n)
  vector<int> topKFrequent(vector<int> &nums, int k) {

    unordered_map<int, int> count;
    for (int num : nums) {
      count[num]++;
    }
    vector<vector<int>> freq(nums.size());
    for (auto it = count.begin(); it != count.end(); it++) {
      freq[it->second - 1].push_back(it->first);
    }
    vector<int> res;
    for (int i = nums.size() - 1; i > 0; i--) {
      if (res.size() >= k) {
        break;
      }
      if (!freq[i].empty()) {
        res.insert(res.end(), freq[i].begin(), freq[i].end());
      }
    }
    return res;
  }
  // O(n log k), O(n + k)
  vector<int> another(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for (int num: nums) {
      count[num]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto it = count.begin(); it != count.end(); it++) {
      pq.push({it->second, it->first});
      if (pq.size() > k) {
        pq.pop();
      }
    }
    vector<int> res;
    while (!pq.empty()) {
      res.push_back(pq.top().second);
      pq.pop();
    }
    return res;
    
  }
};

int main(int argc, char *argv[]) {
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;
  // for (int n : Solution().topKFrequent(nums, k)) {
  for (int n : Solution().another(nums, k)) {
    cout << n << ' ';
  }
  cout << endl;
  return 0;
}
