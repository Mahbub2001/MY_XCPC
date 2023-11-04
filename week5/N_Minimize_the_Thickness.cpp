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
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> v(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<long long> pre(n + 1);
        for (long long i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] + v[i - 1];
        }

        long long res = n, r = n;

        for (long long i = 1; i <= n; i++)
        {
            long long sum = pre[i];
            long long l = i, r = i;
            bool flag = true;
            while (l < n)
            {
                long long id = lower_bound(pre.begin(), pre.end(), pre[l] + sum) - pre.begin();
                if (id != n + 1)
                {
                    if (pre[id] != pre[l] + sum)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        r = max(r, id - l);
                        l = id;
                    }
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                res = min(res, r);
            }
        }
        cout << res << en;
    }

    return 0;
}
