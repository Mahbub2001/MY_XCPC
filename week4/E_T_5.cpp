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

    vector<long long> palindrome;
    for (long long i = 0; i < 50005; i++)
    {
        string str = to_string(i);
        string rev = str;
        reverse(rev.begin(), rev.end());
        if (rev == str)
        {
            palindrome.push_back(i);
        }
    }

    while (t--)
    {
        long long n, ans = 0;
        cin >> n;
        vector<long long> arr(n);
        unordered_map<long long, long long> mp;

        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (long long val : arr)
        {
            mp[val]++;
            for (long long val2 : palindrome)
            {
                ans += mp[val ^ val2];
            }
        }

        cout << ans << endl;
    }

    return 0;
}
