class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {

        int maxSum = 0;
        for (int i = 0; i < k; i++)
        {
            maxSum += cardPoints[i];
        }

        int i = k - 1, j = cardPoints.size() - 1;

        int score = maxSum;
        while (i >= 0 && j >= 0)
        {
            score -= cardPoints[i];
            score += cardPoints[j];

            maxSum = max(maxSum, score);
            i--;
            j--;
        }

        return maxSum;
    }
};