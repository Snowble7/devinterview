#include <stdio.h>

int maxScore(int* cardPoints, int cardPointsSize, int k){
    int max = 0;
    int cur = 0;
    int right;
    int left;

    for(right = 0; right < k; right++) {
            cur += cardPoints[right];
    }

    max = cur;
    right = k - 1;
    left = cardPointsSize - 1;

    while(right > -1) {
            cur -= cardPoints[right--];
            cur += cardPoints[left--];

            if (cur > max) {
                    max = cur;
            }
    }


    return max;
}
//Driver code 
int main(void) {
  int input[7] = {1,2,3,4,5,6,1};

  printf("Result %d\n", maxScore(input, 7, 3));
  return 0;
}