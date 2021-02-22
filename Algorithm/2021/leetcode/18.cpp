#include <bits/stdc++.h>
#define ll long long
using namespace std;
class Solution {
public:
     vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 하나씩 fix시킨 다음 to-pointer
        // 먼저 정렬이 필요함 ㅋㅋ
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int len = nums.size();
        int fi=0, se=1;
        while(fi<len-3){
            se=fi+1;
            while(se < len-2){
                int st=se+1, ed=len-1;
                while(st<ed){
                    ll sum = nums[fi] + nums[se] + nums[st] + nums[ed];
                    if(sum == target){
                        ans.push_back({nums[fi], nums[se], nums[st], nums[ed]});
                        while(st+1 < len && nums[st] == nums[st+1])
                            st++;
                        while(ed-1 >= 0 && nums[ed] == nums[ed-1])
                            ed--;
                        st++;
                    }
                    else if(sum > target)
                        ed--;
                    else
                        st++;
                }
                while(se+1 < len && nums[se] == nums[se+1])
                    se++;
                se++;
            }
            while(fi+1 < len && nums[fi] == nums[fi+1])
                fi++;
            fi++;
        }
        return ans;
    }
};