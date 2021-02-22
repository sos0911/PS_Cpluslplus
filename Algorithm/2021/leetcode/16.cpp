#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // 하나씩 fix시킨 다음 to-pointer
        // 먼저 정렬이 필요함 ㅋㅋ
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int i=0;
        int closestdiff = INF;
        int ans;
        while(i < len-2){
            int st=i+1, ed=len-1;
            while(st<ed){
                int sum = nums[i] + nums[st] + nums[ed];
                if(abs(sum - target) < closestdiff){
                    closestdiff = abs(sum - target);
                    ans = sum;
                    if(!closestdiff)
                        return target;
                }
                if(sum < target)
                    st++;
                else if(sum > target)
                    ed--;
            }
            while(i+1 < len && nums[i] == nums[i+1])
                i++;
            i++;
        }
        return ans;
    }
};