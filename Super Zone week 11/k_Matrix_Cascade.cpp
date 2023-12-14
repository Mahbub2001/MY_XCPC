/**
 *   Author : Mahbub_Ahmed
 *   Created: 2023-12-14 10:54:32
 **/
#include <bits/stdc++.h>
using namespace std;

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define en '\n'
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

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << en;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

// Sum
struct FenwickTree
{
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n, 0);
    }
    FenwickTree(vector<int> a) : FenwickTree(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
    int sum(int r)
    {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

// minimum
struct FenwickTreeMin
{
    vector<int> bit;
    int n;
    const int INF = (int)1e9;

    FenwickTreeMin(int n)
    {
        this->n = n;
        bit.assign(n, INF);
    }

    FenwickTreeMin(vector<int> a) : FenwickTreeMin(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int getmin(int r)
    {
        int ret = INF;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = min(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = min(bit[idx], val);
    }
};

// const ll sieve_N = 2e7;
// bool is_prime[sieve_N + 1];
// vector<ll> primes;

// void sieve()
// {
//     fill(is_prime, is_prime + sieve_N + 1, true);
//     is_prime[0] = is_prime[1] = false;

//     for (ll i = 2; i * i <= sieve_N; i++)
//     {
//         if (is_prime[i])
//         {
//             for (ll j = i * i; j <= sieve_N; j += i)
//             {
//                 is_prime[j] = false;
//             }
//         }
//     }

//     for (ll i = 2; i <= sieve_N; i++)
//     {
//         if (is_prime[i])
//         {
//             primes.push_back(i);
//         }
//     }
// }

const int N = 3e3 + 5;
ll l[N][N];
ll r[N][N];
ll d[N][N];
void TEST_CASES(ll testCase)
{
    int n, ans = 0;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; i++)
        cin >> strings[i];

    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= n + 1; j++)
            l[i][j] = r[i][j] = d[i][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        string s = strings[i - 1];
        for (int j = 0; j < s.size(); j++)
        {
            d[i + 1][j] ^= d[i][j] ^ r[i][j] ^ l[i][j];
            l[i + 1][j - 1] ^= l[i][j];
            r[i + 1][j + 1] ^= r[i][j];

            int x = (s[j] - '0') ^ l[i][j] ^ r[i][j] ^ d[i][j];
            if (x)
            {
                d[i + 1][j] ^= 1;
                r[i + 1][j + 1] ^= 1;
                l[i + 1][j - 1] ^= 1;
                ++ans;
            }
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    ll t = 1;
    cin >> t;
    for (ll test = 1; test <= t; test++)
    {
        TEST_CASES(test);
    }

    return 0;
}
