class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int start_i = 0, start_j = 0, end_i = matrix.size() - 1, end_j = matrix[0].size() - 1;
        vector<int> res;
        while (start_i <= end_i && start_j <= end_j)
        {
            for (int j = start_j; j <= end_j; j++)
            {
                res.push_back(matrix[start_i][j]);
            }
            start_i++;
            for (int i = start_i; i <= end_i; i++)
            {
                res.push_back(matrix[i][end_j]);
            }
            end_j--;
            for (int j = end_j; start_i <= end_i && j >= start_j; j--)
            {
                res.push_back(matrix[end_i][j]);
            }
            end_i--;
            for (int i = end_i; start_j <= end_j && i >= start_i; i--)
            {
                res.push_back(matrix[i][start_j]);
            }
            start_j++;
        }
        return res;
    }
};