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

// Sum
template <class T, class U>
// T -> node, U->update.
struct Lazy_Segment_Tree
{
    vector<T> st;
    vector<U> lazy;
    ll n;
    T identity_element;
    U identity_update;
    Lazy_Segment_Tree(ll n, T identity_element, U identity_update)
    {
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4 * n, identity_element);
        lazy.assign(4 * n, identity_update);
    }
    T combine(T l, T r)
    {
        // change this function as required.
        T ans = (l + r); // sum of a range
        // T ans = min(l, r); // min of a range
        // T ans = max(l, r); // max of a range
        // T ans = __gcd(l, r); // gcd of a range
        // T ans = l | r; // or of a range
        // T ans = l ^ r; // xor of a range
        // T ans = l & r; // and of a range
        // T ans = l * r; // product of a range
        // T ans = l; // assign a value to a range

        return ans;
    }
    void buildUtil(ll v, ll tl, ll tr, vector<T> &a)
    {
        if (tl == tr)
        {
            st[v] = a[tl];
            return;
        }
        ll tm = (tl + tr) >> 1;
        buildUtil(2 * v + 1, tl, tm, a);
        buildUtil(2 * v + 2, tm + 1, tr, a);
        st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
    }
    // change the following 2 functions, and you're more or less done.
    T apply(T curr, U upd, ll tl, ll tr)
    {
        T ans = (tr - tl + 1) * upd;
        // T ans = curr + (tr - tl + 1) * upd; // increament range by upd
        //  query,take max,update,assign a value T ans = upd;
        //  T ans = upd; // query,take min,update,assign a value
        //  query,take gcd,update,assign a value T ans = upd;
        //  T ans = upd; // query,take or,update,assign a value
        return ans;
    }
    U combineUpdate(U old_upd, U new_upd, ll tl, ll tr)
    {
        U ans = old_upd;
        ans = new_upd;
        // U ans = old_upd + new_upd; // adding a value to a range
        //  U ans = new_upd;// assigning a value to a range
        //  query,take max,update,assign a value U ans = new_upd;
        //  U ans = new_upd; // query,take min,update,assign a value
        //  query,take gcd,update,assign a value U ans = new_upd;
        return ans;
    }
    void push_down(ll v, ll tl, ll tr)
    {
        if (lazy[v] == identity_update)
            return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if (2 * v + 2 < 4 * n)
        {
            ll tm = (tl + tr) >> 1;
            lazy[2 * v + 1] = combineUpdate(lazy[2 * v + 1], lazy[v], tl, tm);
            lazy[2 * v + 2] = combineUpdate(lazy[2 * v + 2], lazy[v], tm + 1, tr);
        }
        lazy[v] = identity_update;
    }
    T queryUtil(ll v, ll tl, ll tr, ll l, ll r)
    {
        push_down(v, tl, tr);
        if (l > r)
            return identity_element;
        if (tr < l or tl > r)
        {
            return identity_element;
        }
        if (l <= tl and r >= tr)
        {
            return st[v];
        }
        ll tm = (tl + tr) >> 1;
        return combine(queryUtil(2 * v + 1, tl, tm, l, r), queryUtil(2 * v + 2, tm + 1, tr, l, r));
    }

    void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd)
    {
        push_down(v, tl, tr);
        if (tr < l or tl > r)
            return;
        if (tl >= l and tr <= r)
        {
            lazy[v] = combineUpdate(lazy[v], upd, tl, tr);
            push_down(v, tl, tr);
        }
        else
        {
            ll tm = (tl + tr) >> 1;
            updateUtil(2 * v + 1, tl, tm, l, r, upd);
            updateUtil(2 * v + 2, tm + 1, tr, l, r, upd);
            st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
        }
    }

    void build(vector<T> a)
    {
        assert(a.size() == n);
        buildUtil(0, 0, n - 1, a);
    }
    T query(ll l, ll r)
    {
        return queryUtil(0, 0, n - 1, l, r);
    }
    void update(ll l, ll r, U upd)
    {
        updateUtil(0, 0, n - 1, l, r, upd);
    }
};

void TEST_CASES(ll testCase)
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Lazy_Segment_Tree<ll, ll> tree(n, 0, -1);
    // for sum = n,0,-1,for kth element= n,0,0,
    // for max = n,LLONG_MIN,-1,for min = n,LLONG_MAX,-1,
    tree.build(a);
    while (q--)
    {

        ll l, r;
        cin >> l >> r;
        // l--;
        cout << tree.query(l, r) << en;
    }
}

int32_t main()
{
    FastIO;

    ll t = 1;
    // cin >> t;
    for (ll test = 1; test <= t; test++)
    {
        TEST_CASES(test);
    }

    return 0;
}
