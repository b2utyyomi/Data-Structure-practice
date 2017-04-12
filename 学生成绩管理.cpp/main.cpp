#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXLEN = 100;
typedef struct Node
{
    int num;
    char name[MAXLEN];
    int score1;
    int score2;
    int score3;
    int total;
    struct Node *next;
}Node;

Node stu[500];
int cmp1(Node a, Node b)
{
    return a.total-b.total;
}
/**************
登记
***************/
Node *create(Node *h)
{
    int n;
    printf("请输入学生人数: ");
    scanf("%d", &n);
    Node *p, *q;
    h = new Node;
    h->next = NULL;
    q = h;
    for(int i=0; i<n; i++){
        p = new Node;
        printf("请输入第%d个学生的学号: ", i+1);
        scanf("%d", &p->num);
        printf("请输入第%d个学生的姓名: ", i+1);
        scanf("%s", &p->name);
        printf("请输入第%d个学生的第一门成绩: ", i+1);
        scanf("%d", &p->score1);
        printf("请输入第%d个学生的第二门成绩: ", i+1);
        scanf("%d", &p->score2);
        printf("请输入第%d个学生的第三门成绩: ", i+1);
        scanf("%d", &p->score3);
        p->total = p->score1+p->score2+p->score3;
        ///前插
        /*
        p->next = h->next;
        h->next = p;
        */
        ///后插
        q->next = p;
        p->next = NULL;
        q = q->next;

    }
    return h;
}

/**************
查询
***************/
void ques(Node *h)
{
    Node s[10000];
    memset(s, 0, sizeof(s));
    int cnt = 0;
    Node *p;
    p = h->next;
    int i = 0;
    while(p){
        printf("第%d个学生的学号: ", i+1);
        printf("%d\n", p->num);
        printf("第%d个学生的姓名: ", i+1);
        printf("%s\n", p->name);
        printf("第%d个学生的第一门成绩: ", i+1);
        printf("%d\n", p->score1);
        printf("第%d个学生的第二门成绩: ", i+1);
        printf("%d\n", p->score2);
        printf("第%d个学生的第三门成绩: ", i+1);
        printf("%d\n", p->score3);
        printf("第%d个学生的总成绩: ", i+1);
        printf("%d\n", p->total);
        s[cnt++] = *p;
        p = p->next;
        i++;
    }
    printf("如需查看排名， 请按1, 否则请按0~");
    int a;
    scanf("%d", &a);
    if(a == 1){
            sort(s, s+cnt, cmp1);
            for(int i=0; i<cnt; i++){
                printf("第%d个学生的学号: ", i+1);
                printf("%d\n", s[i].num);
                printf("第%d个学生的姓名: ", i+1);
                printf("%s\n", s[i].name);
                printf("第%d个学生的第一门成绩: ", i+1);
                printf("%d\n", s[i].score1);
                printf("第%d个学生的第二门成绩: ", i+1);
                printf("%d\n", s[i].score2);
                printf("第%d个学生的第三门成绩: ", i+1);
                printf("%d\n", s[i].score3);
                printf("第%d个学生的总成绩: ", i+1);
                printf("%d\n", s[i].total);
        }
    }

}
/***************
插入  可插入多个
***************/
Node *Insert(Node *h)
{
    int n;
    printf("请输入要插入的学生人数: ");
    scanf("%d", &n);
    Node *p = new Node;
    for(int i=0; i<n; i++){
        printf("请输入学生的学号: ");
        scanf("%d", &p->num);
        Node *q;
        Node *r;
        r = h;
        q = h->next;
        while(q){
            if(q->num==p->num)
                break;
            r = r->next;
            q = q->next;
        }
        if(q){
            printf("该学生已存在\n");
            continue;
        }

        printf("请输入学生的姓名: ");
        scanf("%s", &p->name);
        printf("请输入学生的第一门成绩: ");
        scanf("%d", &p->score1);
        printf("请输入学生的第二门成绩: ");
        scanf("%d", &p->score2);
        printf("请输入学生的第三门成绩: ");
        scanf("%d", &p->score3);
        p->total = p->score1+p->score2+p->score3;
        r->next = p;
        p->next = NULL;


    }
    return h;

}
/******************
删除   可删除多个
******************/
Node *Delete(Node *h)
{
    int n;
    printf("请输入要删除的学生人数: ");
    scanf("%d", &n);
    Node *p = new Node;
    for(int i=0; i<n; i++){
        printf("请输入学生的学号: ");
        scanf("%d", &p->num);
        Node *q;
        Node *r;
        r = h;
        q = h->next;
        while(q){
            if(q->num==p->num)
                break;
            r = r->next;
            q = q->next;
        }
        if(q == NULL){
            printf("该学生不存在\n");
            continue;
        }
        r->next = q->next;
        delete q;

    }
    return h;

}
void menu()
{
    printf("\t\t************************\n");
    printf("\t\t****学生成绩管理系统****\n");
    printf("\t\t************************\n");
    printf("\t\t********1.登记********\n");
    printf("\t\t******2.插入******\n");
    printf("\t\t******3.删除******\n");
    printf("\t\t******4.查询******\n");
    printf("\t\t如需退出， 请按\"u\"...\n");
    printf("\t\t************************\n");
}
int main()
{

    Node *head;
    int s = 0;
    int cnt = 0;

    while(1){
        ///printf("登记请按\"c\", 插入请按\"i\", 删除请按\"d\", 查询请按\"q\"\n");
        ///printf("如需退出， 请按\"u\"...\n");
        menu();

        int b;
        scanf("%d", &b);
        if(s == 10000)
            break;
        switch(b)
        {
            case 1: head = create(head);break;
            case 2: head = Insert(head);break;
            case 3: head = Delete(head);break;
            case 4: ques(head);break;
            case 5: s = 10000;break;
            default: printf("请重新输入\n");

        }
        cnt++;
    }

    return 0;
}
