class Solution {
public:
    int findMin(vector<int> &nums) {
        int result = nums[0];
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] > nums[i + 1])
            {
                result = nums[i+1];
            }
        }
        return result;
    }
};
