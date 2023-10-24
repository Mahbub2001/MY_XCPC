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
const int N = 2e5 + 5;
vector<long long > graph[N];
vector<long long > cnt(N, 0);
void dfs(long long  u, long long  par)
{
    cnt[u] = 0;
    for (auto v : graph[u])
    {
        if (v == par)
            continue;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
    cnt[u] = max(cnt[u], 1LL);
}
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

        fill(cnt.begin(), cnt.begin() + n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            graph[i].clear();
        }
        for (int i = 1; i < n; i++)
        {
            long long u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(1, 0);
        long long q;
        cin >> q;
        for (int i = 1; i <= q; i++)
        {
            long long u, v;
            cin >> u >> v;
            cout << cnt[u] * cnt[v] << endl;
        }
    }

    return 0;
}
