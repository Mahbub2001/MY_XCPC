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
        long long n, ans = 0;
        string s;
        cin >> n >> s;
        vector<long long> v;
        for (long long i = 0; i < n; i++)
        {
            if (s[i] == 'R')
            {
                ans += n - i - 1;
                v.push_back(2 * i - n + 1);
            }
            else
            {
                ans += i;
                v.push_back(n - 1 - 2 * i);
            }
        }
        sort(v.rbegin(), v.rend());
        long long j = 0;
        for (long long i = 0; i < n; i++)
        {
            if (v[j] > 0)
            {
                ans += v[j];
                j++;
            }
            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}
