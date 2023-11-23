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

const long long INF = 1e18;

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

        bool flag = false;

        for (long long i = 3; i <= 20 && !flag; i++)
        {
            long long l = 2, r = pow(n, 1.0 / (i - 1)) + 2;
            while (l <= r)
            {
                long long mid = (l + r) / 2, sum = 0, mv = 1;

                for (int j = 0; j < i; j++)
                {
                    sum += mv;
                    if (sum > n)
                        break;
                    mv *= mid;
                }

                if (sum == n)
                {
                    flag = true;
                    break;
                }
                if (sum > n)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }

        flag ? YES : NO;
    }

    return 0;
}
