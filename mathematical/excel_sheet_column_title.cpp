class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans = "";
        while (columnNumber > 0)
        {
            columnNumber--;
            int digit = columnNumber % 26;
            columnNumber = columnNumber / 26;
            ans += digit + 'A';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};