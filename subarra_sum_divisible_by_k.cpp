class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {

        unordered_map<int, int> p;
        int sum = 0, cnt = 0;
        p[sum] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int rem = sum % k;

            if (rem < 0)
            {
                rem += k;
            }
            if (p.find(rem) != p.end())
            {
                cnt += p[rem];
                p[rem] += 1;
            }
            else
            {
                p[rem] = 1;
            }
        }
        return cnt;
    }
};