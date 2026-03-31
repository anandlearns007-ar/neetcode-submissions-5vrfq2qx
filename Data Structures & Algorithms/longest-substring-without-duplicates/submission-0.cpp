class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength = 0;
        int left = 0;
        unordered_map<char, int> mp;
        for(int right = 0;right < s.length(); right++) {
            char curr = s[right];
            mp[curr]++;

            while(mp[curr] > 1)
            {
                char del = s[left];
                mp[del]--;
                left++;
            }
            maxlength = max(maxlength, right - left + 1);
        }

        return maxlength;
    }
};