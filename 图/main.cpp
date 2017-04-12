#include <iostream>
#include<cstring>
#include<queue>
using namespace std;

const int maxn = 1000;
int cnt = 0;
struct arcnode
{
    int adjvex;
    int weight;
    arcnode *nextarc;
};
typedef struct vnode
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
bool vis[maxn];
int deg[maxn];
int LocateVex(Graph G, int u)
{
    for(int i=0; i<G.vexnum; i++){
        if(G.vertices[i].data == u)
            return i;
    }
    return 0;
}

void create_graph(Graph &G)
{
    cin >> G.vexnum >> G.arcnum;
    for(int i=0; i<G.vexnum; i++){
        G.vertices[i].data = i+1;
        G.vertices[i].firstarc = NULL;
    }
    arcnode *p;
    int u, v;
    for(int i=0; i<G.arcnum; i++){

        cin >> u >> v;
        p = new arcnode;

        int k = LocateVex(G, u);
        int kk = LocateVex(G, v);
        p->adjvex = kk;
        p->weight = 1;
        p->nextarc = G.vertices[k].firstarc;
        G.vertices[k].firstarc = p;
        deg[kk]++;
    }

}
///WooHyun OPPA   &&  TaekWoon OPPA

void dfs(Graph G, int u)
{
    int k = LocateVex(G, u);
    if(!vis[k])
    {
        cout << G.vertices[k].data << ' ';
        vis[k] = true;
        arcnode *p;
        for(p = G.vertices[k].firstarc; p; p = p->nextarc){
            dfs(G, G.vertices[p->adjvex].data);
        }
    }
}

void bfs(Graph G, int u)
{
    int head = 0;
    int tail = 0;
    int q[maxn];
    memset(q, 0, sizeof(q));
    int k = LocateVex(G, u);
    q[tail++] = k;
    while(head != tail){
        int kk = q[head++];
        cout << G.vertices[kk].data << ' ';
        arcnode *p;
        for(p = G.vertices[kk].firstarc; p; p=p->nextarc){
            q[tail++] = p->adjvex;
        }
    }
}
void toposort(Graph G)
{

    priority_queue<int, vector<int>, greater<int> > q;
    while(!q.empty())
        q.pop();

    for(int i=0; i<G.vexnum; i++){
        if(deg[i] == 0){
            deg[i]--;
            q.push(i);
        }
    }
    while(!q.empty()){
        int a = q.top();///标号
        cnt++;
        cout << G.vertices[a].data << " ";
        q.pop();

        for(arcnode *p = G.vertices[a].firstarc; p; p=p->nextarc){
            deg[p->adjvex]--;
            if(deg[p->adjvex] == 0){
                q.push(p->adjvex);
                deg[p->adjvex]--;
            }
        }
    }
}
/*
void toposort(Graph G)
{
    priority_queue<int, vector<int>, greater<int> >q;
    while(!q.empty())
        q.pop();

    for(int i=1; i<=G.vexnum; i++){
        if(deg[i] == 0){
            ///q[tail++] = i;
           q.push(i);
           deg[i]--;
        }
    }
    while(!q.empty()){
       /// int k = q[head++] ;
       int u = q.top();
        q.pop();
        cnt++;
        cout << u << ' ';
        int k = LocateVex(G, u);
        for(arcnode *p=G.vertices[k].firstarc; p; p=p->nextarc){
            if(p->weight == 1){
                int v = G.vertices[p->adjvex].data;
                deg[v]--;
                if(deg[v] == 0){
                   /// q[tail++] = p->adjvex;
                   q.push(v);
                    deg[v]--;
                }
            }
        }

    }
}
*/
void menu()
{
    cout << "***********************" << endl;
    cout << "1.create a graph " << endl;
    cout << "2.dfs" <<endl;
    cout << "3.bfs" <<endl;
    cout << "4.toposort" <<endl;
}
int main()
{
    menu();

    Graph G;
    memset(vis, false, sizeof(vis));
    memset(deg, 0, sizeof(deg));
    create_graph(G);
    ///dfs(G, G.vertices[0].data);
    ///cout << endl;
    ///bfs(G, G.vertices[0].data);
    toposort(G);
    if(cnt != G.vexnum){
        cout << "сп╩╥" << endl;
    }
    return 0;
}


/*
4 5
2 1
1 4
2 4
1 3
4 3
*/





