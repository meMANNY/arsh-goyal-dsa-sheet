class Solution
{
public:
    int sum(int a, int b)
    {
        if (a == 1 && b == 1)
            return 10;
        return a + b;
    }
    string addBinary(string a, string b)
    {

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans;

        int n = a.size(), m = b.size();
        int i = 0, j = 0, carry = 0;

        while (i < n && j < m)
        {

            int summ = sum(a[i] - '0', b[j] - '0');
            summ = sum(summ, carry);

            carry = summ / 10;
            ans += (summ % 10) + '0';
            i++;
            j++;
        }
        while (i < n)
        {

            int summ = sum(a[i] - '0', carry);

            carry = summ / 10;
            ans += (summ % 10) + '0';
            i++;
        }
        while (j < m)
        {

            int summ = sum(b[j] - '0', carry);

            carry = summ / 10;
            ans += (summ % 10) + '0';
            j++;
        }

        if (carry == 1)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};