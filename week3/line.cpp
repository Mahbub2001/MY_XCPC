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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> first, second;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < n / 2)
            {
                if (s[i] == 'L')
                    first.push_back(n - i - 1);
            }
            else
            {
                if (s[i] == 'R')
                    second.push_back(i);
            }
            if (s[i] == 'L')
                ans += i;
            else
                ans += (n - i - 1);
        }
        sort(first.begin(), first.end(), greater<int>());
        sort(second.begin(), second.end(), greater<int>());

        int l1 = 0, l2 = 0;

        for (int i = 1; i <= n; i++)
        {
            if (l1 == first.size() && l2 == second.size())
            {
                cout << ans << ' ';
            }
            else if (l1 == first.size())
            {
                ans += second[l2];
                ans -= (n - second[l2++] - 1);
                cout << ans << ' ';
            }
            else if (l2 == second.size())
            {
                ans += first[l1];
                ans -= (n - first[l1++] - 1);
                cout << ans << ' ';
            }
            else
            {
                if (first[l1] > second[l2])
                {
                    ans += first[l1];
                    ans -= (n - first[l1++] - 1);
                    cout << ans << ' ';
                }
                else
                {
                    ans += second[l2];
                    ans -= (n - second[l2++] - 1);
                    cout << ans << ' ';
                }
            }
        }
        cout << endl;
    }

    return 0;
}
