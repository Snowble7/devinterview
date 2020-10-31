#include <iostream>
#include <vector>
#include <bits/stdc++.h>

class Solution {
public:
    #define MAX(a,b) ((a)>(b))?(a):(b)
    
    int maxScore(vector<int>& cardPoints, int k) {
        int n = (int) cardPoints.size();
        int left[k + 1], right[n + 2];
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        for(int i = 1; i <= k; i++)
            left[i] = left[i - 1] + cardPoints[i - 1];
        right[n] = cardPoints[n - 1];
        for(int i = n - 1; i > n - k; i--)
            right[i] = right[i + 1] + cardPoints[i - 1];
        int ans = 0;

        for(int i = 0; i <= k; i++) {
            ans = max(ans, left[i] + right[n - k + 1 + i]);
        }
        return ans;
    }
};        


//Driver code
int main()
{
  Solution s;
  std::vector<int> input = {1,2,3,4,5,6,1};
  std::cout<<(s.maxScore(input,3))<<std::endl;
}