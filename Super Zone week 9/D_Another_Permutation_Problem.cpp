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
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        long long ans = 0;
        for (long long i = n; i >= 1; i--)
        {
            long long l = i, curr = 0, mx = LLONG_MIN, r = l - 1;
            bool flag = false;
            for (long long j = n; j >= 1; j--)
            {
                curr = curr + j * l;
                mx = max(mx, j * l);
                if (flag )
                    l--;
                else
                    l++;
                if (l > n)
                {
                    flag = 1;
                    l = r;
                }
            }
            curr -= mx;
            ans = max(ans, curr);
        }

        cout << ans << en;
    }
    return 0;
}
