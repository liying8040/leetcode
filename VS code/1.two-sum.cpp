/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int, int> maps;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            maps.insert({nums[i], i});
        }
         for(auto beg = maps.begin(); beg != maps.end(); beg++){
            auto iter = maps.find(target - beg->first);
             if(iter != maps.end() && iter != beg){
                 res.push_back(beg->second);
                 res.push_back(iter->second);
                 return res;
             }
        }
        return res;
    }
};
// @lc code=end

