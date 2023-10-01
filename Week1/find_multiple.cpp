#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define fill_number(x, n) setfill('0') << setw(n) << (x)
template <typename T>
T lcm(T a, T b)
{
    return (a * (b / __gcd(a, b)));
}

// const long long N = 2e7;
// bool is_prime[N + 1];
// vector<long long> primes;
// vector<long long> divisor;

// void sieve()
// {
//     fill(is_prime, is_prime + N + 1, true);
//     is_prime[0] = is_prime[1] = false;

//     for (long long i = 2; i * i <= N; i++)
//     {
//         if (is_prime[i])
//         {
//             for (long long j = i * i; j <= N; j += i)
//             {
//                 is_prime[j] = false;
//             }
//         }
//     }

//     for (long long i = 2; i <= N; i++)
//     {
//         if (is_prime[i])
//         {
//             primes.push_back(i);
//         }
//     }
// }

// void divisors(int n)
// {
//     for (int i = 1; i * i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             if (n / i == i)
//                 divisor.push_back(i);
//             else
//             {
//                 divisor.push_back(i);
//                 divisor.push_back(n / i);
//             }
//         }
//     }
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y, z;
    cin >> x >> y >> z;

    int l = x % z == 0 ? x : x + (z - x % z);

    if (l <= y)
    {
        cout << l << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
