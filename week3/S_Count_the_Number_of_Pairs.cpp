#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define fill_number(x, n) setfill('0') << setw(n) << (x)
#define precision_number(x, n) fixed << setprecision(n) << (x)
template <typename T>
T lcm(T a, T b)
{
    return (a * (b / __gcd(a, b)));
}

// const long long sieve_N = 2e7;
// bool is_prime[sieve_N + 1];
// vector<long long> primes;

// void sieve()
// {
//     fill(is_prime, is_prime + sieve_N + 1, true);
//     is_prime[0] = is_prime[1] = false;

//     for (long long i = 2; i * i <= sieve_N; i++)
//     {
//         if (is_prime[i])
//         {
//             for (long long j = i * i; j <= sieve_N; j += i)
//             {
//                 is_prime[j] = false;
//             }
//         }
//     }

//     for (long long i = 2; i <= sieve_N; i++)
//     {
//         if (is_prime[i])
//         {
//             primes.push_back(i);
//         }
//     }
// }
bool cmp(pair<char, int> a, pair<char, int> b)
{
    return tolower(a.first) < tolower(b.first);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<char, int>> v;
        unordered_map<char, int> mp;

        for (int i = 0; i < n; i++)
        {
            char x;
            cin >> x;
            mp[x]++;
        }
        for (const auto &val : mp)
        {
            v.push_back(make_pair(val.first, val.second));
        }
        sort(v.begin(), v.end(), cmp);

        // for (auto val : v)
        // {
        //     cout << val.first << " " << val.second << endl;
        // }

        int count = 0;

        for (int i = 0; i < v.size(); i++)
        {
            if (i + 1 < v.size())
            {
                // cout << "inside" << endl;
                if (tolower(v[i].first) == tolower(v[i + 1].first))
                {
                    int mn = min(v[i].second, v[i + 1].second);
                    int mx = max(v[i].second, v[i + 1].second);
                    count += mn;
                    if (k != 0 && (mx != mn))
                    {

                        int diff = mx - mn;
                        // cout<<diff<<endl;
                        if (diff / 2 >= 1)
                        {
                            if (diff / 2 >= k)
                            {
                                count = count + k;
                                k = 0;
                            }
                            else
                            {
                                count += diff / 2;
                                k = k - diff / 2;
                            }
                        }
                    }
                    i++;
                }
                else
                {
                    if (v[i].second >= 2 && k != 0)
                    {
                        if (v[i].second / 2 >= k)
                        {
                            count = count + k;
                            k = 0;
                        }
                        else
                        {
                            count += v[i].second / 2;
                            k = k - v[i].second / 2;
                        }
                    }
                }
            }
            else if (v[i].second >= 2 && k != 0)
            {
                if (v[i].second / 2 >= k)
                {
                    count = count + k;
                    k = 0;
                }
                else
                {
                    count += v[i].second / 2;
                    k = k - v[i].second / 2;
                }
            }
        }

        cout << count << endl;
        // cout<<endl;
    }

    return 0;
}
