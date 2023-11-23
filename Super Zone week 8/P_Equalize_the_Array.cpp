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
        unordered_map<long long, long long> v1;
        for (long long i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        long long count = v[0], cur = 1;
        for (long long i = 1; i < n; i++)
        {
            if (count != v[i])
            {
                v1[cur]++;
                count = v[i];
                cur = 1;
            }
            else
            {
                cur++;
            }
        }
        if (cur != 0)
        {
            v1[cur]++;
        }
        vector<pair<long long, long long>> vp(v1.begin(), v1.end());
        sort(vp.rbegin(), vp.rend());

        long long sum = 0, ans = LLONG_MAX;
        for (const auto &val : vp)
        {
            sum += val.second;
            ans = min(ans, n - (sum * val.first));
        }
        cout << ans << en;
    }

    return 0;
}
