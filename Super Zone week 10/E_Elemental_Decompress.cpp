/**
 *   Author : Mahbub_Ahmed
 *   Created: 2023-12-04 23:59:25
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

void TEST_CASES(ll testCase)
{
    ll n;
    cin >> n;
    vector<ll> v(n + 1), perm1(n + 1), perm2(n + 1), pos[n + 1];
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        pos[v[i]].push_back(i);
        if (pos[v[i]].size() > 2)
        {
            flag = false;
        }
    }
    if (!flag)
    {
        NO;
        return;
    }
    queue<int> q;
    for (int i = n; i >= 1; i--)
    {
        if (pos[i].empty())
        {
            if (q.empty())
            {
                flag = false;
                break;
            }
            perm1[pos[q.front()].front()] = i;
            perm2[pos[q.front()].back()] = i;
            q.pop();
        }
        else
        {
            perm2[pos[i].front()] = i;
            perm1[pos[i].back()] = i;
            if (pos[i].size() > 1)
            {
                q.push(i);
            }
        }
    }
    if (flag)
    {
        YES;
        for (int i = 1; i <= n; i++)
        {
            cout << perm2[i] << " ";
        }
        cout << en;
        for (int i = 1; i <= n; i++)
        {
            cout << perm1[i] << " ";
        }
        cout << en;
        return;
    }
    NO;
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
