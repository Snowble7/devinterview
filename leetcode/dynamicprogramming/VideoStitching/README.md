# Problem

[Video Stitching](https://leetcode.com/problems/video-stitching/)

스포츠 이벤트가 총 T초 동안 지속되는 동안 촬영된 일련의 Video Clip들이 제공됩니다. 
이러한 clip 들은 서로 겹칠 수 있으며 길이가 다양합니다. 

각 Video Clip의 Clips[i] 는 interval 입니다. 
Clip[i][0] 에서 시작해서 Clip[i][1] 에서 종료됩니다. 
이러한 Clip 들을 Segment 로 자유롭게 자를 수 있습니다. 
예를 들자면 [0,7] Clip은 [0,1]+[1,3]+[3,7] 세그먼트로 자를 수 있습니다.

전체 Sport Event[0,T]를 포함하는 segment로 Clip을 자를 수 있도록 필요한 
최소 Clip수를 반환합니다. 불가능 하다면 -1을 Return 합니다. 

Constraints:

1 <= clips.length <= 100

0 <= clips[i][0] <= clips[i][1] <= 100

0 <= T <= 100


```
Example 1:

Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
Output: 3
Explanation: 
We take the clips [0,2], [8,10], [1,9]; a total of 3 clips.
Then, we can reconstruct the sporting event as follows:
We cut [1,9] into segments [1,2] + [2,8] + [8,9].
Now we have segments [0,2] + [2,8] + [8,10] which cover the sporting event [0, 10].
Example 2:

Input: clips = [[0,1],[1,2]], T = 5
Output: -1
Explanation: 
We can't cover [0,5] with only [0,1] and [1,2].
Example 3:

Input: clips = [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]], T = 9
Output: 3
Explanation: 
We can take clips [0,4], [4,7], and [6,9].
```

# Idea

DP[T] := Hold the minimum number of clips required to get the T seconds clip length

```
1. Sort first
2. 각각의 Clip에 대해 DP[clip[i][0]] ~ DP[clip[i][1]] 에 Update

// Clip [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]]
// T 10

// Sort first
Clip  [[0,2],[1,5],[1,9],[4,6],[5,9],[8,10]]
 dp[j] = min(dp[j], dp[clips[i][0]] + 1);
 DP 101 101 101 101 101 101 101 101 101 101 101
// init DP[0] = 0
 DP   0   1   1 101 101 101 101 101 101 101 101 
 DP   0   1   1 101 101 101 101 101 101 101 101 -> 0,2
 DP   0   1   1   2   2   2 101 101 101 101 101 -> 1,5
 DP   0   1   1   2   2   2   2   2   2   2 101 -> 1,9
 DP   0   1   1   2   2   2   2   2   2   2 101 -> 4,6
 DP   0   1   1   2   2   2   2   2   2   2 101 -> 5,9
 DP   0   1   1   2   2   2   2   2   2   2   3 -> 8,10

```

# Implementation

* [c++11](VideoStitching.cpp)
```
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        vector<int> dp(101, 101); // size of clip is 100, T is up to 100
        dp[0] = 0;
        for (int i=0; i<clips.size(); i++) {
            for (int j = clips[i][0] ; j <= clips[i][1]; j++) {
                // iterate each clip's start to end, and get the min value of clip
                dp[j] = min(dp[j], dp[clips[i][0]] + 1);
            }
        }
        return dp[T] >= 100 ? -1 : dp[T];
    }
};

```

# Complexity

```
O(N log N) // N is the number of clips. We sort all clips, and then processing each clip only once.
O(T)
```
