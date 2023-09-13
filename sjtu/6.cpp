#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i,a,b) for(int i=a;i<=b;++i)
#define rf(i,a,b) for(int i=a;i>=b;--i)
const int N = 2e5 + 5;

int m;
int ch[64*N][2], tot = 1;
int sz[64*N][2];
void ins(ll a, ll b){
    int nw = 1;
    rf(i,63,0){
        int s1 = a >> i & 1, s2 = b >> i & 1;
        if( !ch[nw][s1] ) ch[nw][s1] = ++tot;
        nw = ch[nw][s1];
        ++ sz[nw][s2];
    }
}
void del(ll a, ll b){
    int nw = 1;
    rf(i,63,0){
        int s1 = a >> i & 1, s2 = b >> i & 1;
        nw = ch[nw][s1];
        -- sz[nw][s2];
    }
}
void query(ll x, ll y){
    int s = 0, nw = 1;
    rf(i, 63, 0){
        int f1 = x >> i & 1, f2 = y >> i & 1;
        // f1 ^1 f2^1
        
        s += sz[ch[nw][f1^1]][f2^1];
        nw = ch[nw][f1];
    }
    printf("%d\n",s);
}
int main(){
    cin.tie(0), cout.tie(0);
    #ifdef OJ
    freopen("input.txt","r",stdin);
    #endif
    cin >> m;
    fr(i,1,m) {
        int tp;
        ll x,y;
        cin >> tp >> x >> y;
        if(tp == 1) ins(x^y,x);
        if(tp == 2) del(x^y,x);
        if(tp == 3) query(x^y,x);
    }
    return 0;
}