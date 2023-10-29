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
        long long n, h, m;
        cin >> n >> h >> m;
        long long minute = h * 60 + m;
        vector<long long> v;
        for (long long i = 0; i < n; i++)
        {
            long long x, y;
            cin >> x >> y;
            v.push_back(x * 60 + y);
        }
        sort(v.begin(), v.end());
        long long ans = 0;
        if (lower_bound(v.begin(), v.end(), minute) == v.end())
        {
            cout << (60 * 24 - minute + v[0]) / 60 << " " << (60 * 24 - minute + v[0]) % 60 << endl;
        }
        else
        {
            cout << (*lower_bound(v.begin(), v.end(), minute) - minute) / 60 << " " << (*lower_bound(v.begin(), v.end(), minute) - minute) % 60 << endl;
        }
    }

    return 0;
}
