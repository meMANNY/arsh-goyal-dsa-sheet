class Solution
{
public:
    string reverseWords(string s)
    {

        reverse(s.begin(), s.end());

        int start = 0;
        int end = 0;
        int i = 0;
        int n = s.size();
        while (i < n)
        {

            while (i < n && s[i] == ' ')
                i++;
            while (i < n && s[i] != ' ')
                s[end++] = s[i++];

            if (start < end)
            {
                reverse(s.begin() + start, s.begin() + end);
                s[end++] = ' ';
                start = end;
            }
            i++;
        }
        if (end > 0)
            s.resize(end - 1);

        return s;
    }
};