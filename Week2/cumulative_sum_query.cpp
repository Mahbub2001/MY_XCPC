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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, Q;
    cin >> n;
    long long int arr[n];
    long long int pre[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = arr[i] + pre[i - 1];
    }
    cin >> Q;
    int L, R;
    while (Q--)
    {
        cin >> L >> R;
        if (L == 0)
        {
            cout << pre[R] << endl;
        }
        else
        {
            cout << pre[R] - pre[L - 1] << endl;
        }
    }

    return 0;
}
