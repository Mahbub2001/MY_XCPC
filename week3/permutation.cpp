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

const long long sieve_N = 2e7;
bool is_prime[sieve_N + 1];
vector<long long> primes;

void sieve()
{
    fill(is_prime, is_prime + sieve_N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (long long i = 2; i * i <= sieve_N; i++)
    {
        if (is_prime[i])
        {
            for (long long j = i * i; j <= sieve_N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    for (long long i = 2; i <= sieve_N; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
}
typedef pair<int, int> pii;

pii a[1111];
bool cmp(pii a, pii b)
{
    return a.second < b.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
 int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i].first = i;
        a[i].second = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int x;
            cin >> x;
            a[x].second += j;
        }
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i].first << ' ';
    }
    cout << endl;

    }

   
    return 0;
}
