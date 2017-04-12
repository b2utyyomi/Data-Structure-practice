#include <iostream>
#include <cstring>

using namespace std;
const int inf = 0x3f3f3f;
const int maxn = 1000;
bool vis[maxn];
int d[maxn];
typedef struct arcnode
{
    int adjvex;
    int weight;
    arcnode *nextarc;
};
typedef struct vode
{
    int data;
    arcnode *firstarc;
}Adjvex[20];

struct Graph
{
    int vexnum;
    int arcnum;
    Adjvex vertices;
};

int LocateVex(Graph G, int u)
{
    for(int i=0; i<G.vexnum; i++){
        if(G.vertices[i].data == u)
            return i;
    }
    return 0;
}

void create_Graph(Graph & G)
{
    cin >> G.vexnum >> G.arcnum;
    arcnode *p, *q;
    int u, v, w;
    for(int i=0; i<G.vexnum; i++){
        G.vertices[i].data = i+1;
        G.vertices[i].firstarc = NULL;
    }
    for(int i=0; i<G.arcnum; i++){
        cin >> u >> v >> w;
        p = new arcnode;
        q = new arcnode;
        if(q == NULL || p == NULL)
            return;

        int k = LocateVex(G, u);
        int kk = LocateVex(G, v);
        p->adjvex = kk;
        p->weight = w;
        p->nextarc = G.vertices[k].firstarc;
        G.vertices[k].firstarc = p;

        q->adjvex = k;
        q->weight = w;
        q->nextarc = G.vertices[kk].firstarc;
        G.vertices[kk].firstarc = q;
    }
}

void dijkstra(Graph G, int u, int vv)
{
    int k = LocateVex(G, u);
    for(arcnode *p = G.vertices[k].firstarc; p; p=p->nextarc){
        if(p->weight < inf){
            int v = G.vertices[p->adjvex].data;
            d[v] = p->weight;
        }
    }
    cout << d[5] << endl;///1
    for(int i=0; i<G.vexnum-1; i++){
        int min = inf;
        int robix;
        for(int j=0; j<G.vexnum; j++){
            int v = G.vertices[j].data;
            if(!vis[v] && min > d[v]){
                min = d[v];
                robix = v;
            }
        }
        vis[robix] = true;
        for(int j=0; j<G.vexnum; j++){
            int v = G.vertices[j].data;
            int k = LocateVex(G, robix);
            for(arcnode *p = G.vertices[k].firstarc;p; p=p->nextarc){
                if(p->adjvex == j && !vis[v] && d[v]>d[robix]+p->weight){///最初忘了加限制条件p->adjvex == j
                    d[v] = d[robix]+p->weight;
                }
            }
        }
    }
    cout << "the distance is : ";
    cout << u << " to" << vv << ": ";
    cout << d[vv] << endl;

}
int main()
{
    Graph G;
    create_Graph(G);
    int s, vv;

    memset(vis, false, sizeof(vis));
    memset(d, inf, sizeof(d));
    cin >> s >> vv;
    d[s] = 0;
    vis[s] = true;
    dijkstra(G, s, vv);


    return 0;
}

/**
5 7
1 2 1
2 3 1
1 5 1
4 5 1
3 4 1
2 5 5
2 4 5

**/
