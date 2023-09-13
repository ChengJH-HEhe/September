#include<bits/stdc++.h>
using namespace std;
#define rf(i,a,b) for(int i=a;i>=b;--i)
#define fr(i,a,b) for(int i=a;i<=b;++i)
const int N = 40005;
int col[N], sz[N];
vector<int> e[N];
bitset<N> pd;
void dfs(int co, int nw){
    for(auto y: e[nw]){
        if(! col[y]){
            dfs(col[y] = co, y);
        }
    }
}   
int main(){
    #ifdef OJ
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    int n, m, k;
    cin >> n >> m>> k;
    int nw = 0;
    fr(i,1,k){
        int u1,v1;
        cin >> u1 >> v1;
        e[u1].push_back(v1),e[v1].push_back(u1);
    }
    fr(i,1,n)if(!col[i])dfs(col[i]=++col[0],i);
    fr(i,1,n) ++ sz[col[i]];
    pd[0] = 1;
    fr(j,1,col[0]) pd = (pd | (pd << sz[j]) );
    fr(i,0,m){
        if(pd[m-i]) {
            cout << m-i <<endl;
            break;
        } else 
            if (pd[m+i]){
                cout << m+i << endl;
                break;
            } 
    }
    return 0;
}