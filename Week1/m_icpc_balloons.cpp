#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int l;
        string s,str;
        cin>>l>>s;
        int sum = 0;
        for(auto val:s){
            if(str.find(val) != string::npos){
                sum+=1;
            }
            else{
                str+=val;
                sum+=2;
            }
        }
        cout<<sum<<endl;
    }
    
    return 0;
}
