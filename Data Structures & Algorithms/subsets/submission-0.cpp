class Solution {
public:
    void backtrack(vector<int> &nums, vector<int> &path, vector<vector<int>> &result, int start)
    {
        result.push_back(path);

        for(int i = start; i< nums.size();i++)
        {
            path.push_back(nums[i]);
            backtrack(nums, path, result,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;

        backtrack(nums, path, result,0);

        return result;
    }
};