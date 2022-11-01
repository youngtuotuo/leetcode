#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int l = 0, r = height.size() - 1;
        int area = 0;
        while (l < r) {
            area = max(area, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return area;
    }
};

int main(int argc, char *argv[]) {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << Solution().maxArea(height) << endl;
    return 0;
}
