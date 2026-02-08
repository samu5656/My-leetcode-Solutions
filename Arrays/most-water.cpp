#include <vector>
#include <algorithm>
using namespace std;
//Container with most water - Leetcode-11 -https://leetcode.com/problems/container-with-most-water/description/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxarea = 0;

        while (left < right) {
            int w = right - left;
            int h = min(height[left], height[right]);
            int area = w * h;

            maxarea = max(maxarea, area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxarea;
    }
};
