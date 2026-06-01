#include <vector>
#include <queue>
#include <functional>
using namespace std;

// LeetCode 659: Split Array into Consecutive Subsequences
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> heap;

        for (int num : nums) {
            while (!heap.empty() && heap.top().first < num - 1) {
                if (heap.top().second < 3) return false;
                heap.pop();
            }

            if (!heap.empty() && heap.top().first == num - 1) {
                auto [endval, length] = heap.top();
                heap.pop();
                heap.push({num, length + 1});
            } else {
                heap.push({num, 1});
            }
        }

        while (!heap.empty()) {
            if (heap.top().second < 3) return false;
            heap.pop();
        }

        return true;
    }
};