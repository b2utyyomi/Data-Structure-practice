
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef struct treenode{
    char data;
    treenode *lchild;
    treenode *rchild;
}node;
node *create(node *t){
    char a;
    cin >> a;
    if(a == '0'){
        return 0;
    }
    t = new node;
    t->data = a;
    t->lchild = create(t->lchild);
    t->rchild = create(t->rchild);
    return t;
}
int leaves(node *t){
    int sum = 0, lsum, rsum;
    if(t){
        if(!(t->lchild) && !(t->rchild)){
            sum++;
        }
        lsum = leaves(t->lchild);
        sum += lsum;
        rsum = leaves(t->rchild);
        sum += rsum;
    }
    return sum;
}
void pre(node *t){
    if(t){
        cout << t->data;
        pre(t->lchild);
        pre(t->rchild);
    }
}
void in(node *t){
    if(t){
        in(t->lchild);
        cout << t->data;
        in(t->rchild);
    }
}
void post(node *t){
    if(t){
        post(t->lchild);
        post(t->rchild);
        cout << t->data;
    }
}
int depth(node *t){
    int d = 0, ld = 0, rd = 0;
    if(!t){
        d = 0;
    }
    else{
        ld += depth(t->lchild);
        rd += depth(t->rchild);
        d = 1 + max(ld, rd);
    }
    return d;
}
int IsEmpty(node *t)
{
    if(!t)
        return 1;
    return 0;
}

void destroy_tree(node *t)
{
    if(t){
        if(t->lchild)
            destroy_tree(t->lchild);
        if(t->rchild)
            destroy_tree(t->rchild);
        t = NULL;
        delete t;

    }

}

void level(node *t)
{
    queue<node *>q;
    node *a;
    if(t)
    {
        while(!q.empty())
            q.pop();
        q.push(t);
        while(!q.empty())
        {
            a = q.front();
            q.pop();
            cout << a->data;
            if(a->lchild)
                q.push(a->lchild);
            if(a->rchild)
                q.push(a->rchild);
        }
    }
}
node * parent(node *t, char e)///找某个节点的双亲
{
    queue<node *>q;
    node *a;
    if(t)
    {
        while(!q.empty())
            q.pop();
        q.push(t);
        while(!q.empty())
        {
            a = q.front();
            q.pop();
            if(a->lchild && a->lchild->data==e||a->rchild && a->rchild->data == e)
                return a;
            else
            {
                if(a->lchild)
                    q.push(a->lchild);
                if(a->rchild)
                    q.push(a->rchild);
            }
        }
    }
    return NULL;
}
node * leftchild1(node *t, char e)///遍历所有节点去找值为e的那个节点
{
    queue<node *>q;
    node *a;
    if(t)
    {
        while(!q.empty())
            q.pop();
        q.push(t);
        while(!q.empty())
        {
            a = q.front();
            q.pop();
            if(a->data == e)
                return a->lchild;
            else
            {
                if(a->lchild)
                    q.push(a->lchild);
                if(a->rchild)
                    q.push(a->rchild);
            }
        }
    }
    return NULL;
}
///返回二叉树T中指向元素值为s的结点的指针。
node *point(node *t, char s)
{
    queue<node *>q;
    node *a;
    if(t)
    {
        while(!q.empty())
        q.pop();
        q.push(t);
        while(!q.empty())
        {
            a = q.front();
            q.pop();
            if(a->data == s)
                return a;
            if(a->lchild)
                q.push(a->lchild);
            if(a->rchild)
                q.push(a->rchild);
        }
    }
    return NULL;
}

node *leftchild2(node *t, char e)
{
    node *a;
    if(t)
    {
        a = point(t, e);
        if(a && a->lchild)
            return a->lchild;
    }
    return NULL;
}

node* leftsibling(node *t, char e)
{
    node *a = parent(t, e);
    if(a && a->lchild)
        return a->lchild;
}
void menu()
{
    printf("***********************\n");
    printf("1. create a binary tree\n");
    printf("2. pre_order\n");
    printf("3. in_order\n");
    printf("4. post_order\n");
    printf("5. level_order\n");
    printf("6. leaves number\n");
    printf("7. depth\n");
    printf("8. exit\n");
}
int main(int argc, char const *argv[]) {
    node *tree;
    int temp = 100;
    while(1){
        if(temp == 8)
            break;
         menu();
         int a;
         cin >> a;
         switch(a)
         {
             case 1:/*if(temp == 1){
                        cout << "树已存在， 将创建新树" << endl;
                    }
                    temp = 1;*/
                    tree = create(tree);break;
             case 2:pre(tree);cout << endl;break;
             case 3:in(tree);cout << endl;break;
             case 4:post(tree);cout << endl; break;
             case 5:level(tree);cout << endl; break;
             case 6:{int ss = leaves(tree);
                    cout << "the leaves number is " << ss << endl;
                     break;}
             case 7:{int sss = depth(tree);
                    cout << "the depth is " << sss << endl;
                     break;}
             case 8: temp = 8; break;
             default: cout << "please input again." << endl;
         }

    }

    destroy_tree(tree);///销毁
    if(IsEmpty(tree))///判断树空
        cout << "empty!" << endl;
    return 0;
}
/*
abd00e00cf00g00
pre_order_traverse:
abdecfg
in_order_traverse:
dbeafcg
post_order_traverse:
debfgca
leaves num:
4
depth:
3

Process returned 0 (0x0)   execution time : 13.225 s
Press any key to continue.

*/
