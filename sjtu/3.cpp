#include<bits/stdc++.h>
using namespace std;
#define rf(i,a,b) for(int i=a;i>=b;--i)
#define fr(i,a,b) for(int i=a;i<=b;++i)
const int N = 5e5 + 5;
int n,b[N],pre[N],c[N];
int pos[N];
inline void read(int &x){
	char c=getchar();int fh=0;bool f=false;
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))fh=(fh<<1)+(fh<<3)+(c^48),c=getchar();
    x = f?-fh:fh;
}
struct node{
    int l, r, id;
    bool operator < (const node & b){
        return r < b.r;
    }
}a[N];
int tr[N], ans[N];
int lowbit(int x){
    return x&-x;
}
void add(int pos,int val){
    for(;pos<=n;pos+=lowbit(pos))
        tr[pos] += val;
}
int sum(int pos){
    int an = 0;
    for(;pos;pos -= lowbit(pos))
        an += tr[pos];
    return an;
}

int main(){
    #ifdef OJ
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int m;
    cin >> n >> m;
    fr(i,1,n) read(b[i]), c[i] = b[i];
    sort(c + 1,c + n + 1);
    int len = unique(c + 1, c + n + 1) - c - 1;
    for(int i = 1; i <= n; ++i)
        b[i] = lower_bound(c + 1,c + len + 1,b[i]) - c;
    fr(i,1,n) pre[i] = pos[b[i]], pos[b[i]] = i;
    fr(i,1,m)
        read(a[i].l),read(a[i].r),
        a[i].id = i;
    sort(a+1,a+m+1,[](node &a, node &b){return a.r<b.r;});
    fr(i, 1, m){
        fr(j, a[i-1].r+1, a[i].r){
            int nw = pre[j], nw1 = pre[nw], nw2 = pre[nw1];
            if(!nw)continue;
            if(!nw1) add(nw,1);
            else if(!nw2) add(nw1,-2),add(nw,1);
            else add(nw2,1), add(nw1,-2),add(nw,1);
        }
        ans[a[i].id] = sum(a[i].r) - sum(a[i].l-1);
    }
    fr(i,1,m) printf("%d\n",ans[i]);
    return 0;
}