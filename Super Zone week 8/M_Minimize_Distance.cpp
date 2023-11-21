#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define YES cout << "YES" << en
#define NO cout << "NO" << en
#define yes cout << "Yes" << en
#define no cout << "No" << en
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

    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> a, b;
        for (long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            if (x < 0)
            {
                a.push_back(abs(x));
            }
            else
            {
                b.push_back(x);
            }
        }
        sort(a.begin(), a.end(), greater<long long>());
        sort(b.begin(), b.end(), greater<long long>());

        long long ans = 0;
        for (long long i = 0; i < a.size(); i += k)
        {
            ans += 2 * a[i];
        }
        for (long long i = 0; i < b.size(); i += k)
        {
            ans += 2 * b[i];
        }

        long long mn = LLONG_MIN;
        if (a.size())
        {
            mn = a[0];
        }
        if (b.size())
        {
            mn = max(mn, b[0]);
        }
        cout << ans - mn << en;
    }

    return 0;
}
