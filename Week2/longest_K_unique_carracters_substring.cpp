#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        int i = 0, j = 0, len = 0, n = s.size();

        map<int, char> mp;
        while (j < n)
        {
            mp[s[j]]++;
            while (mp[s[j]] > 1)
            {
                mp[s[i]]--;
                i++;
            }
            if (len < j - i + 1)
            {
                len = j - i + 1;
            }
            j++;
        }
        return len;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
