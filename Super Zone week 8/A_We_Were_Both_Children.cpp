#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long n;
        cin >> n;
 
        vector<long long> v1(n);
        map<long long, long long> mp;
 
        for (int i = 0; i < n; i++)
        {
            cin >> v1[i];
            mp[v1[i]]++;
        }
 
        vector<long long> v2(n + 1);
 
        for (auto it : mp)
        {
            for (int i = it.first; i < n + 1; i += it.first)
            {
                v2[i] += it.second;
            }
        }
        cout << *max_element(v2.begin(), v2.end()) << endl;
    }
}