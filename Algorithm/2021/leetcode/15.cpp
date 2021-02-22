#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 하나씩 fix시킨 다음 to-pointer
        // 먼저 정렬이 필요함 ㅋㅋ
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int len = nums.size();
        int i=0;
        while(i < len-2){
            int st=i+1, ed=len-1;
            while(st<ed){
                int sum = nums[i] + nums[st] + nums[ed];
                if(sum == 0){
                    ans.push_back({nums[i], nums[st], nums[ed]});
                    while(st+1 < len && nums[st] == nums[st+1])
                        st++;
                    while(ed-1 >= 0 && nums[ed] == nums[ed-1])
                        ed--;
                    st++;
                }
                else if(sum > 0)
                    ed--;
                else
                    st++;
            }
            while(i+1 < len && nums[i] == nums[i+1])
                i++;
            i++;
        }
        return ans;
    }
};