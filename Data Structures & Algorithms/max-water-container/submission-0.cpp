class Solution {
public:
    int maxArea(vector<int>& heights) {
         // we want the maximum area. so we would like to get the maxm heights for the same width

         int maxArea = 0;
         int left = 0;
         int right = heights.size()-1;

         while(left < right)
         {
            maxArea = max(maxArea, ((right -left) * min(heights[left], heights[right])));

            if(heights[left] < heights[right])
            {
                left++;
            }
            else
            {
                right--;
            }
         }
        return maxArea;
    }
};