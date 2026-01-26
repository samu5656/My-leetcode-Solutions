//leetcode171-https://leetcode.com/problems/excel-sheet-column-number/submissions/1897126109/?envType=problem-list-v2&envId=string
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;

        for (char ch : columnTitle) {
            result = result * 26 + (ch - 'A' + 1);
        }

        return result;
    }
};

int main() {
    Solution obj;

    string columnTitle;
    cout << "Enter column title: ";
    cin >> columnTitle;

    cout << "Excel Column Number: "
         << obj.titleToNumber(columnTitle) << endl;

    return 0;
}
