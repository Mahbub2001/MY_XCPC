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

const long long N = 2e7;
bool is_prime[N + 1];
vector<long long> primes;

void sieve()
{
    fill(is_prime, is_prime + N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (long long i = 2; i * i <= N; i++)
    {
        if (is_prime[i])
        {
            for (long long j = i * i; j <= N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    for (long long i = 2; i <= N; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string pat, txt;
    cin >> pat >> txt;

    unordered_map<char, int> mp;

    for (int i = 0; i < txt.size(); i++)
    {
        mp[txt[i]]++;
    }

    int size_mp = mp.size();
    int count = 0;

    int i = 0, j = 0;
    while (j < pat.size())
    {
        if (mp.find(pat[j]) == mp.end())
        {
            if (size_mp == 0)
            {
                count++;
            }

            if (mp.find(pat[i]) != mp.end())
            {
                mp[pat[i]]++;
                if (mp[pat[i]] == 1)
                {
                    size_mp++;
                }
            }

            i++;
            j++;
        }

        if (j - i + 1 < txt.size())
        {
            j++;
        }

        else
        {
            mp[pat[j]]--;
            if (mp[pat[j]] == 0)
                size_mp--;
        }
    }
    cout << count << endl;

    return 0;
}
