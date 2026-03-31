class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int>result;
       vector<int> prefixProduct;
       vector<int> suffixProduct;
       int prefix = 1;
       int suffix = 1;
       prefixProduct.push_back(prefix);
       for(int i = 1 ; i < nums.size(); i++)
       {
          prefix *= nums[i-1];
          prefixProduct.push_back(prefix);
          //[1,1,2,8]
       }
       suffixProduct.push_back(suffix);
       for(int i = nums.size()-2; i>=0;i--)
       {
           suffix *= nums[i + 1];
           suffixProduct.push_back(suffix);
           // 1,6,24,48
       }
       reverse(suffixProduct.begin(), suffixProduct.end());
          //48,24,6,1
       for(int i = 0; i<nums.size();i++)
       {
           result.push_back(prefixProduct[i] * suffixProduct[i]);
       }

      return result;
    }
};
