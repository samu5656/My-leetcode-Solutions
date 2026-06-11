//Leetcodde-1854 Maximum population year
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int delta[101] = {0};
        for(auto log:logs)
        {
            delta[log[0]-1950]++;
            delta[log[1]-1950]--;
        }
        int maxpop=0;
        int year=0;
        int running_sum=0;
        for(int i=0;i<101;i++){
            running_sum+=delta[i];
            if(running_sum>maxpop)
            {
                maxpop=running_sum;
                year=i+1950;
            }
        }
        return year;
    }
};