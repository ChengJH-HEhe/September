#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i=a;i<=b;++i)
#define rf(i,a,b) for(int i=a;i>=b;--i)
int x[505],d[505], val[505][505];
int f[505][505];
int n,m;
int main(){
    cin.tie(0), cout.tie(0);
    #ifdef OJ
    freopen("input.txt","r",stdin);
    #endif
    cin >> n >> m;
    x[1] = 0; x[0] = -1e9, x[n+1] = 1e9;
    fr(i,1,n-1) cin >> d[i], x[i+1] = x[i] + d[i];
    
    fr(i,0,n)
        fr(j,i+1,n+1){
            fr(k,i+1,j-1)
                val[i][j] += min(x[k]-x[i],x[j]-x[k]);
        }  
    memset(f,0x3f,sizeof(f));
    f[0][0] = 0;
    fr(cn,1,m)
        fr(i,1,n)
            fr(j,0,i-1)
                f[cn][i] = min(f[cn][i], f[cn-1][j] + val[j][i]);
    int ans = 1e9;
    fr(i,1,n) ans = min (ans,f[m][i] + val[i][n+1]);// cout << f[m][i] << " " << val[i][n+1] <<endl;
    cout << ans <<endl;
    return 0;
}
// 27 28 