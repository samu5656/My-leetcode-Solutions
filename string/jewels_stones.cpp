//leetcode-jewels and stones-771-https://leetcode.com/problems/jewels-and-stones/?envType=problem-list-v2&envId=string
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;

        for (int i = 0; i < jewels.size(); i++) {
            for (int j = 0; j < stones.size(); j++) {
                if (jewels[i] == stones[j]) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution obj;

    string jewels, stones;
    cout << "Enter jewels string: ";
    cin >> jewels;

    cout << "Enter stones string: ";
    cin >> stones;

    cout << "Number of jewels in stones: "
         << obj.numJewelsInStones(jewels, stones) << endl;

    return 0;
}
