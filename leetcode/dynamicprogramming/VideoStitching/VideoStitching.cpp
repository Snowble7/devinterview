#include <iostream>
#include <vector>
#include <bits/stdc++.h>

class Solution {
public:
    int videoStitching(std::vector<std::vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        std::vector<int> dp(101, 101); // size of clip is 100, T is up to 100
        dp[0] = 0;
        for (int i=0; i<clips.size(); i++) {
            for (int j = clips[i][0] ; j <= clips[i][1]; j++) {
                // iterate each clip's start to end, and get the min value of clip
                dp[j] = std::min(dp[j], dp[clips[i][0]] + 1);
            }
        }
        return dp[T] >= 100 ? -1 : dp[T];
    }
};

//Driver code
int main()
{
  Solution s;
  std::vector<std::vector<int>> input = {{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
  std::cout<<(s.videoStitching(input,10))<<std::endl;
}