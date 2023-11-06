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
        double px, py, ax, ay, bx, by, ox = 0, oy = 0;
        cin >> px >> py >> ax >> ay >> bx >> by;

        auto distance = [](int x2, int x1, int y2, int y1)
        {
            return sqrt((x2 - x1) * (x2 - x1) + ((y2 - y1) * (y2 - y1)));
        };

        double _a = distance(ax, 0, ay, 0);
        double _b = distance(bx, 0, by, 0);

        double ab = distance(ax, bx, ay, by);
        double ap = distance(ax, px, ay, py);
        double bp = distance(bx, px, by, py);

        double x1 = max(max(ap, _b), ab / 2);
        double x2 = max(max(bp, _a), ab / 2);

        cout << precision_number(min(min(x1, x2), min(max(_a, ap), max(_b, bp))), 10) << endl;
    }

    return 0;
}
