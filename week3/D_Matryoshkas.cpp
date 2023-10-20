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
        vector<long long>a(n);
        vector<pair<long long, long long>> b;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end(),greater<long long>());

        long long i = 0, j;

        while (i < n)
        {
            j = i;

            while (i < n && a[i] == a[j])
            {
                i++;
            }

            b.push_back({a[j], i - j});
        }

        long long ans = b[0].second;

        for (int i = 1; i < b.size(); i++)
        {
            if (b[i].first + 1 == b[i - 1].first)
            {
                ans = ans + max(b[i].second - b[i - 1].second, 0ll);
            }
            else
            {
                ans = ans + b[i].second;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
