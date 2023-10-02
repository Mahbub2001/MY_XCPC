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

bool isAnagram(const string &pat, const string &txt)
{
    string s1 = pat;
    string s2 = txt;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
}

int countAnagrams(const string &pat, const string &txt)
{
    int count = 0;
    int pat_len = pat.length();
    int txt_len = txt.length();

    for (int i = 0; i <= pat_len - txt_len; i++)
    {
        if (isAnagram(txt, pat.substr(i, txt_len)))
        {
            count++;
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string pat;
    string txt;
    cin >> pat >> txt;

    int result = countAnagrams(pat, txt);
    cout << result << endl;

    return 0;
}


