class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_map<int, int> mpp1, mpp2;
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    mpp1[i] = 1;
                    mpp2[j] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (mpp1[i] == 1)
            {
                for (int j = 0; j < m; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < m; j++)
        {
            if (mpp2[j] == 1)
            {
                for (int i = 0; i < n; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};