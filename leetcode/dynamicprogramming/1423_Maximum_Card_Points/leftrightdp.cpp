#include <iostream>
#include <vector>
#include <bits/stdc++.h>

class Solution {
public:
    #define MAX(a,b) ((a)>(b))?(a):(b)
    
    int maxScore(std::vector<int>& cardPoints, int k) {
        std::vector<int> left(k,0);
        std::vector<int> right(k,0);
        
        int n = cardPoints.size();
        left[0] = cardPoints[0];
        right[0] = cardPoints[n-1];
        
        for(int i=1; i<k; i++) {
            
            left[i] = cardPoints[i] + left[i-1];
            right[i] = cardPoints[n-i-1] + right[i-1];
        }
        int result = MAX(left[k-1], right[k-1]);
        
        for(int i=0 ; i<k-1; i++) {
            int temp = left[i] + right[k-i-2];
                
            result = MAX(result, temp);
        }
        return result;
    }
};

//Driver code
int main()
{
  Solution s;
  std::vector<int> input = {1,2,3,4,5,6,1};
  std::cout<<(s.maxScore(input,3))<<std::endl;
}