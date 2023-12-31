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

    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        long long mx = LLONG_MIN;
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        long long l = 1, r = mx;
        bool flag = false;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            double ans = 1;
            for (long long i = 0; i < n; i++)
            {
                ans *= (a[i] * 1.0 / mid * 1.0);
            }
            if (fabs(ans - 1) < 1e-12)
            {
                YES;
                flag = true;
                break;
            }
            else if (ans > 1)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (!flag)
            NO;
    }

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define YES cout << "YES" << endl
// #define NO cout << "NO" << endl
// #define yes cout << "Yes" << endl
// #define no cout << "No" << endl
// #define fill_number(x, n) setfill('0') << setw(n) << (x)
// #define precision_number(x, n) fixed << setprecision(n) << (x)
// template <typename T>
// T lcm(T a, T b)
// {
//     return (a * (b / __gcd(a, b)));
// }

// // const long long sieve_N = 2e7;
// // bool is_prime[sieve_N + 1];
// // vector<long long> primes;

// // void sieve()
// // {
// //     fill(is_prime, is_prime + sieve_N + 1, true);
// //     is_prime[0] = is_prime[1] = false;

// //     for (long long i = 2; i * i <= sieve_N; i++)
// //     {
// //         if (is_prime[i])
// //         {
// //             for (long long j = i * i; j <= sieve_N; j += i)
// //             {
// //                 is_prime[j] = false;
// //             }
// //         }
// //     }

// //     for (long long i = 2; i <= sieve_N; i++)
// //     {
// //         if (is_prime[i])
// //         {
// //             primes.push_back(i);
// //         }
// //     }
// // }

// void getPrime(long long p,unordered_map<long long,long long>&mp){
//     while(p%2==0){
//         mp[2]++;
//         p/=2;
//     }
//     for (long long  i = 3; i*i <= p; i++)
//     {
//        while(p%i==0){
//         mp[i]++;
//         p/=i;
//        }
//     }
//     if(p>1){
//         mp[p]++;
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int t;
//     cin>>t;
//     while(t--){
//         unordered_map<long long,long long>mp;
//         long long n;
//         cin>>n;
//         for (int i = 0; i < n; i++)
//         {
//             long long x;
//             cin>>x;
//             getPrime(x,mp);
//         }
//         bool flag = true;
//         for(auto val:mp){
//             if(val.second%n!=0){
//                 flag = false;
//                 break;
//             }
//         }
//         if(flag)YES;
//         else NO;
//     }
    
//     return 0;
// }
