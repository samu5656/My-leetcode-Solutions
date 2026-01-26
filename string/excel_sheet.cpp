//Leetcode_168 - https://leetcode.com/problems/excel-sheet-column-title/?envType=problem-list-v2&envId=string

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;

        while (columnNumber > 0) {
            columnNumber--;                       
            char t = 'A' + (columnNumber % 26);  
            res = t + res;                       
            columnNumber /= 26;
        }

        return res;
    }
};

int main() {
    Solution obj;

    int columnNumber;
    cout << "Enter column number: ";
    cin >> columnNumber;

    cout << "Excel Column Title: "
         << obj.convertToTitle(columnNumber) << endl;

    return 0;
}
