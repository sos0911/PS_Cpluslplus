#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int stidx=0, edidx=height.size()-1;
        int ans=0;
        while(edidx > stidx){
            ans = max(ans, (edidx-stidx)*min(height[stidx], height[edidx]));
            if(height[stidx] > height[edidx])
                edidx--;
            else
                stidx++;
        }
        return ans;
    }
};