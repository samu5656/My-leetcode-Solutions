/*
    Problem: Maximum Sum of Distinct Subarrays With Length K
    Approach: Sliding Window + Hash Map

    Time Complexity: O(n)
    Space Complexity: O(k)

    Algorithm:
    1. Create the first window of size k:
       - Store the frequency of each element using a hash map.
       - Calculate the sum of the first window.
    2. If all elements in the first window are distinct
       (i.e., frequency map size equals k), store the sum as the maximum.
    3. Slide the window one element at a time:
       - Add the incoming element to the frequency map and window sum.
       - Remove the outgoing element from the frequency map and window sum.
       - Erase the outgoing element from the map if its frequency becomes zero.
       - If the current window contains k distinct elements,
         update the maximum sum.
    4. Return the maximum sum found.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        long long sum = 0;
        unordered_map<int, int> freq;

        // Build the first window
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
            sum += nums[i];
        }

        // Check if the first window has all distinct elements
        if ((int)freq.size() == k) {
            maxSum = sum;
        }

        // Slide the window
        for (int i = k; i < nums.size(); i++) {
            // Add the incoming element
            freq[nums[i]]++;
            sum += nums[i];

            // Remove the outgoing element
            int out = nums[i - k];
            freq[out]--;

            // Erase the element if its frequency becomes zero
            if (freq[out] == 0) {
                freq.erase(out);
            }

            sum -= out;

            // Update maximum sum if all elements are distinct
            if ((int)freq.size() == k) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};