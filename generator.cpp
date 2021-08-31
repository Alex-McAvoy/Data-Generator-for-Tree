#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <algorithm>
#include<ctime>
using namespace std;
#define N 50

struct Edge {
    int x, y;
    int dis;
} edge[N];
int n,edgeTot;
int tot, x[N], y[N], dis[N];
int id[N], father[N];
int Find(int x) { return father[x] == x ? x : Find(father[x]); }
int main() {
    srand(time(0));
    n = rand() % 10 + 1;
    
    printf("%d\n", n);
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            x[++tot] = i;
            y[tot] = j;
            dis[tot] = rand() % 100 + 1;
        }
    }
    for (int i = 1; i <= tot; ++i){
        id[i] = i;
        father[i] = i;
    }
 
    random_shuffle(id + 1, id + tot + 1);
 
    for (int i = 1; i <= tot; ++i) {
        int pos = id[i];
        int fx = Find(x[pos]);
        int fy = Find(y[pos]);
        if (fx == fy)
            continue;
        father[fy] = fx;
 
        edge[++edgeTot].x = x[pos];
        edge[edgeTot].y = y[pos];
        edge[edgeTot].dis = dis[pos];
        if (edgeTot == n - 1)
            break;
    }
 
    for ( int i = 1; i <= edgeTot; i++)
        printf("%d %d %d\n", edge[i].x, edge[i].y, edge[i].dis);
        
    system("pause");
    return 0;
}