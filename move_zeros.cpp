class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int it = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[it] = nums[i];
                it++;
            }
        }
        while (it < nums.size())
        {
            nums[it] = 0;
            it++;
        }
    }
};