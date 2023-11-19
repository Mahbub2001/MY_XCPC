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
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        long long bits[30];
        for (int i = 0; i < 30; i++)
        {
            bits[i] = 0;
        }
        for (int i = 0; i < 30; i++)
        {
            long long num = (1ll << i);
            for (long long j = 0; j < n; j++)
            {
                if ((v[j] & num) != 0)
                {
                    bits[i]++;
                }
            }
        }
        for (long long i = 1; i <= n; i++)
        {
            bool flag = true;
            for (long long j = 0; j < 30; j++)
            {
                if ((bits[j] % i) != 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << i << " ";
            }
        }
        cout << en;
    }

    return 0;
}
