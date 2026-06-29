#include<bits/stdc++.h>
using namespace std;

// ======================================================
// Problem Title: Maximum Points You Can Obtain from Cards
// ======================================================

// Problem Description:
// There are several cards arranged in a row, each with an associated point value.
// You have to pick exactly k cards, and on each pick you may choose either the
// leftmost or the rightmost card. Return the maximum score obtainable.
//
// Approach:
// Instead of directly choosing k cards, leave behind a contiguous subarray of
// size (n - k). Since the remaining cards after taking from both ends always
// form a continuous subarray, the answer becomes:
//     Total Sum - Minimum Sum Subarray of Size (n - k)
// A fixed-size sliding window is used to find the minimum window sum efficiently.

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0, windowsum = 0;
        int n = cardPoints.size();
        int windowsize = n - k;

        for (int card : cardPoints)
        {
            sum += card;
        }

        for (int i = 0; i < windowsize; i++)
        {
            windowsum += cardPoints[i];
        }

        int minwindow = windowsum;

        for (int i = windowsize; i < n; i++)
        {
            windowsum += cardPoints[i];
            windowsum -= cardPoints[i - windowsize];
            minwindow = min(minwindow, windowsum);
        }

        return sum - minwindow;
    }
};

// ======================================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
// ======================================================