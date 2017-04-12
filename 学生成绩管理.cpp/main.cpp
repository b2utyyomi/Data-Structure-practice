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
�Ǽ�
***************/
Node *create(Node *h)
{
    int n;
    printf("������ѧ������: ");
    scanf("%d", &n);
    Node *p, *q;
    h = new Node;
    h->next = NULL;
    q = h;
    for(int i=0; i<n; i++){
        p = new Node;
        printf("�������%d��ѧ����ѧ��: ", i+1);
        scanf("%d", &p->num);
        printf("�������%d��ѧ��������: ", i+1);
        scanf("%s", &p->name);
        printf("�������%d��ѧ���ĵ�һ�ųɼ�: ", i+1);
        scanf("%d", &p->score1);
        printf("�������%d��ѧ���ĵڶ��ųɼ�: ", i+1);
        scanf("%d", &p->score2);
        printf("�������%d��ѧ���ĵ����ųɼ�: ", i+1);
        scanf("%d", &p->score3);
        p->total = p->score1+p->score2+p->score3;
        ///ǰ��
        /*
        p->next = h->next;
        h->next = p;
        */
        ///���
        q->next = p;
        p->next = NULL;
        q = q->next;

    }
    return h;
}

/**************
��ѯ
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
        printf("��%d��ѧ����ѧ��: ", i+1);
        printf("%d\n", p->num);
        printf("��%d��ѧ��������: ", i+1);
        printf("%s\n", p->name);
        printf("��%d��ѧ���ĵ�һ�ųɼ�: ", i+1);
        printf("%d\n", p->score1);
        printf("��%d��ѧ���ĵڶ��ųɼ�: ", i+1);
        printf("%d\n", p->score2);
        printf("��%d��ѧ���ĵ����ųɼ�: ", i+1);
        printf("%d\n", p->score3);
        printf("��%d��ѧ�����ܳɼ�: ", i+1);
        printf("%d\n", p->total);
        s[cnt++] = *p;
        p = p->next;
        i++;
    }
    printf("����鿴������ �밴1, �����밴0~");
    int a;
    scanf("%d", &a);
    if(a == 1){
            sort(s, s+cnt, cmp1);
            for(int i=0; i<cnt; i++){
                printf("��%d��ѧ����ѧ��: ", i+1);
                printf("%d\n", s[i].num);
                printf("��%d��ѧ��������: ", i+1);
                printf("%s\n", s[i].name);
                printf("��%d��ѧ���ĵ�һ�ųɼ�: ", i+1);
                printf("%d\n", s[i].score1);
                printf("��%d��ѧ���ĵڶ��ųɼ�: ", i+1);
                printf("%d\n", s[i].score2);
                printf("��%d��ѧ���ĵ����ųɼ�: ", i+1);
                printf("%d\n", s[i].score3);
                printf("��%d��ѧ�����ܳɼ�: ", i+1);
                printf("%d\n", s[i].total);
        }
    }

}
/***************
����  �ɲ�����
***************/
Node *Insert(Node *h)
{
    int n;
    printf("������Ҫ�����ѧ������: ");
    scanf("%d", &n);
    Node *p = new Node;
    for(int i=0; i<n; i++){
        printf("������ѧ����ѧ��: ");
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
            printf("��ѧ���Ѵ���\n");
            continue;
        }

        printf("������ѧ��������: ");
        scanf("%s", &p->name);
        printf("������ѧ���ĵ�һ�ųɼ�: ");
        scanf("%d", &p->score1);
        printf("������ѧ���ĵڶ��ųɼ�: ");
        scanf("%d", &p->score2);
        printf("������ѧ���ĵ����ųɼ�: ");
        scanf("%d", &p->score3);
        p->total = p->score1+p->score2+p->score3;
        r->next = p;
        p->next = NULL;


    }
    return h;

}
/******************
ɾ��   ��ɾ�����
******************/
Node *Delete(Node *h)
{
    int n;
    printf("������Ҫɾ����ѧ������: ");
    scanf("%d", &n);
    Node *p = new Node;
    for(int i=0; i<n; i++){
        printf("������ѧ����ѧ��: ");
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
            printf("��ѧ��������\n");
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
    printf("\t\t****ѧ���ɼ�����ϵͳ****\n");
    printf("\t\t************************\n");
    printf("\t\t********1.�Ǽ�********\n");
    printf("\t\t******2.����******\n");
    printf("\t\t******3.ɾ��******\n");
    printf("\t\t******4.��ѯ******\n");
    printf("\t\t�����˳��� �밴\"u\"...\n");
    printf("\t\t************************\n");
}
int main()
{

    Node *head;
    int s = 0;
    int cnt = 0;

    while(1){
        ///printf("�Ǽ��밴\"c\", �����밴\"i\", ɾ���밴\"d\", ��ѯ�밴\"q\"\n");
        ///printf("�����˳��� �밴\"u\"...\n");
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
            default: printf("����������\n");

        }
        cnt++;
    }

    return 0;
}
