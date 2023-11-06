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

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        long long n, m, mx = LLONG_MIN;
        cin >> n >> m;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mx = max(mx, v[i]);
        }
        long long l = mx, r = 1e9 + 5;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2, sum = 0, count = 1;
            for (int i = 0; i < n; i++)
            {
                if (sum + v[i] > mid)
                {
                    sum = v[i];
                    count++;
                }
                else
                {
                    sum += v[i];
                }
                if (count <= m)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
    }

    return 0;
}
