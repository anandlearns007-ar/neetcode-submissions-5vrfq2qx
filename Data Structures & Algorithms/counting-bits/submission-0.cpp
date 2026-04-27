class Solution {
public:
    int countBit(int n)
    {
        int count = 0;
        while(n!=0)
        {
            if(n & 1)
            {
                count++;
            }
            n = n>>1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> result;
        result.push_back(0);
        for(int i = 1; i<=n;i++)
        {
            int count = countBit(i);
            result.push_back(count);
        }

        return result;
    }
};
