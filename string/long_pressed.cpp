#include <bits/stdc++.h>
using namespace std;

// LeetCode 925 — Long Pressed Name
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int index = 0; 
        
        for (int i = 0; i < typed.size(); i++) {
            if (index < name.size() && name[index] == typed[i]) {
                index++;
            } 
            else if (i > 0 && typed[i] == typed[i - 1]) {
                continue; 
            } 
            else {
                return false;
            }
        }
        
        return index == name.size();
    }
};
