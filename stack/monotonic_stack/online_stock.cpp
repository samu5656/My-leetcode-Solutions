#include <iostream>
#include<stack>
#include <string>
using namespace std;
/*
    Problem: Online Stock Span
    Difficulty: Medium
    Link: https://leetcode.com/problems/online-stock-span/

    Algorithm:
    Monotonic Decreasing Stack

    Approach:
    - Store each stock price along with its span as a pair.
    - For every new price, remove all previous prices that are
      less than or equal to the current price.
    - Their spans can be combined because the current price
      dominates all of them.
    - Add the combined span to the current span.
    - Store {price, span} in the stack.

    Time Complexity: O(n) Amortized
    Space Complexity: O(n)
*/

class StockSpanner {
private:
    // Stores {price, span}
    stack<pair<int, int>> stk;

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;

        // Merge spans of previous prices that are
        // less than or equal to the current price
        while (!stk.empty() && stk.top().first <= price) {
            span += stk.top().second;
            stk.pop();
        }

        // Store current price and its calculated span
        stk.push({price, span});

        return span;
    }
};

