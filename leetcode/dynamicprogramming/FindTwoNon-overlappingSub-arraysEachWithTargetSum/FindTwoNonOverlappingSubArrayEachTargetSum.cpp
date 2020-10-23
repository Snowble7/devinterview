#include <iostream>
#include <vector>
#include <bits/stdc++.h>

class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        int ans = INT_MAX;
        std::vector<int> dp(n, INT_MAX); //dp[i] := min length of a valid subarray ends or before i.
        for(int current = 0, sum = 0, start=0, min_len = INT_MAX; current < n; current++){
            sum += arr[current];
            while(sum > target) 
                sum -= arr[start++]; //shrink from left, 'start'
            if(sum == target){                
                int cur_len = current - start + 1;
                
                if( start > 0 && dp[start-1] != INT_MAX)
                    ans = std::min(ans, cur_len + dp[start-1]);
                min_len = std::min(min_len, cur_len);
            }
            dp[current]=min_len;
        }        
        return ans < INT_MAX ? ans : -1;
    }
};

//Driver code
int main()
{
  Solution s;
  std::vector<int> input = {3,1,1,1,5,1,2,1};
  std::cout<<(s.minSumOfLengths(input,3))<<std::endl;
}
