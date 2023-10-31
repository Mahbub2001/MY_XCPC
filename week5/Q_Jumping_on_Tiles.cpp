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
        string s;
        cin >> s;
        long long n = s.size();
        vector<long long> v[26],v1;
        for (long long i = 0; i < n; i++)
        {
            v[s[i] - 'a'].push_back(i);
        }
        if (s[0] <= s[n - 1])
        {
            for (char i = s[0]; i <= s[n - 1]; i++)
            {
                for (auto x : v[i - 'a'])
                {
                    v1.push_back(x);
                }
            }
        }
        else
        {
            for (char i = s[0]; i >= s[n - 1]; i--)
            {
                for (auto x : v[i - 'a'])
                {
                    v1.push_back(x);
                }
            }
        }

        cout << abs(s[n - 1] - s[0]) << " " << v1.size() << endl;

        for (auto val : v1)
        {
            cout << val + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
