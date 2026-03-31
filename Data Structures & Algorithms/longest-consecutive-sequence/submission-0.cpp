class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;

        for(int i = 0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        
        int longestSub = 0;
        for(int num : nums)
        {
           int count = 0;
           int curr = num;
           while(st.find(curr++) != st.end())
           {
               count++;
           }
           longestSub = max(longestSub, count);
        }
      return longestSub;
    }
};
