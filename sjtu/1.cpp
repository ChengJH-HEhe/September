#include<bits/stdc++.h>
using namespace std;
#define rf(i,a,b) for(int i=a;i>=b;--i)
#define fr(i,a,b) for(int i=a;i<=b;++i)
const int N = 1005;

int n, k, sz, ans;
vector<int> pre, res; 
int cnt[N][N], cnt2[N][N];
int a[N];
bool b[N];
map<vector<int>,int> mp1;
void dfs(int sta, int step, int ct){
    //cout << step << ct << endl;
    if( step == target+1 ){
        mp[sta] = ct;
        return;
    }
    if(ct > k) return;
     //if(ct + sz * (n-1) + sz * ( sz-1 ) / 2 <= k) return;
    int nw1 = 0;
    rf(i,sz-1,0)
        if(!(sta>>i&1)) {
            sta |= 1 << i;
            dfs(sta, step + 1, ct + nw1 + cnt[pre[step]][res[i]] + cnt2[pre[step]][res[i]]);
            sta ^= 1 << i;
        } else ++ nw1;
}

int main(){
    #ifdef OJ
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    int n;
    cin >> n >> k;
    int nw = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i], b[a[i]]=1;
    }
        fr(i,1,n)if( !a[i] ) {
            pre.push_back(i);
            rf(j, n-1, 1){
                cnt[i][j] = cnt[i][j+1];
                fr(l,1,i-1) 
                    if(a[l] == j + 1)
                        ++ cnt[i][j];
            }
            fr(j, 2, n){
                cnt2[i][j] = cnt2[i][j-1];
                fr(l, i+1, n){
                    if(a[l] == j-1)
                        ++ cnt2[i][j];
                }
            }
        } else {
            fr(j,1,i-1)
                if(a[i] < a[j]) ++nw;
        } 
    fr(i,1,n) if(!b[i]) res.push_back(i);
    sz = res.size();
    k -= nw;
    if( k < 0 ) cout << 0 << endl;
    else {
        if(sz<= 14) {
            dfs(0, 0, 0);
            printf("%d\n", ans);
            return 0;
        }
        
    }
    return 0;
}