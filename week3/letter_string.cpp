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

long long dp[100][100];
char ch[100010][3];

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
        long long ans = 0;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> ch[i][1] >> ch[i][2];
            for (int j = 0; j < 12; j++)
            {
                if (ch[i][1] - 'a' != j)
                {

                    ans += dp[j][ch[i][2] - 'a'];
                }
            }
            for (int j = 0; j < 12; j++)
            {
                if (ch[i][2] - 'a' != j)
                {
                    ans += dp[ch[i][1] - 'a'][j];
                }
            }
            dp[ch[i][1] - 'a'][ch[i][2] - 'a']++;
        }
        cout << ans << endl;
    }

    return 0;
}
