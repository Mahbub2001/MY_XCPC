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
        int l, r, x, a, b;
        cin >> l >> r >> x >> a >> b;
        if (b > r || b < l)
        {
            cout << -1 << endl;
        }
        else
        {
            if (a == b)
            {
                cout << 0 << endl;
            }
            else if (abs(a - b) >= x)
            {
                cout << 1 << endl;
            }
            else if ((abs(a - l) >= x && abs(l - b) >= x) || (abs(a - r) >= x && abs(r - b) >= x))
            {
                cout << 2 << endl;
            }
            else if ((abs(a - l) >= x && abs(l - r) >= x && abs(r - b) >= x) || (abs(a - r) >= x && abs(l - r) >= x && abs(l - b) >= x))
            {
                cout << 3 << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}