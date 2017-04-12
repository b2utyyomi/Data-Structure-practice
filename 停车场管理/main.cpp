#include <iostream>
#include<cstdio>
using namespace std;
const int maxn = 3;
const int maxn1 = 1000000;
int cnt1 = 0;
int cnt2 = 0;

struct car
{
    int data;
    struct Time
    {
        int hour_in;
        int hour_out;
    }time;
};


typedef struct node
{
    car data;
    node* next;
    node *head;
    node *tail;
}Queue;


struct Stack
{
    int data[maxn];
    int top;
};


void queue_push(Queue* q, car a)
{
    node *s = new node;
    s->next = NULL;
    s->data = a;

    q->tail->next = s;
    q->tail = s;
}

void queue_pop(Queue *q, car & a)
{
    a = q->head->data;
    q->head = q->head->next;
}

bool Is_empty(Queue *q)
{
    if(q->head == q->tail->next)
        return true;
    return false;
}
/*
void create()
{
    int n;
    int num;
    cin >> n;
    Queue *q;
    q = new node;
    cin >> a[0];
    node *h;
    h = new node;
    q->head = h;
    q->tail = h;
    h->data = a[0];
    for(int i=1; i<n; i++){

        cin >> a[i];
        queue_push(q, a[i]);
    }
    while(!Is_empty(q)){
        queue_pop(q, num);
        cout << num << ' ';
    }
}



void menu()
{
    printf("***********************\n");
    printf("    主菜单             \n");
    printf("***********************\n");
    printf("1.   初始化并建立链队列\n");
    printf("2.             入链队列\n");
    printf("3.             出链队列\n");
    printf("4.           遍历链队列\n");
    printf("5.         结束程序运行\n");
}
*/

void s_init(Stack &s)
{
    s.top = 0;
}

void s_push(int a, Stack &s)
{
    int temp = s.top++;
    s.data[temp] = a;
}

int s_pop(Stack &s)
{
    int temp = --s.top;
    return s.data[temp];
}

bool Is_empty(Stack s)
{
    if(s.top == 0)
        return true;
    return false;
}

/*
void create1()
{
    int n;
    cin >> n;
    Stack s1, s2;
    s_init(s1);
    s_init(s2);
    for(int i=0; i<n; i++){
        cin >> a[i];
        s_push(a[i], s1);
    }
    while(!Is_empty(s1)){
        cout << s1.data[s1.top-1] << endl;
        s_pop(s1);
    }

}*/
/*
int main()
{
    int s = 10000;
    while(1)
    {
        if(s == 5)
            break;
        menu();
        printf("请输入您的选择: ");
        scanf("%d", &s);
        case 1: create();break;
        case 2: q_push();break;
        case 3: q_pop();break;
        case 4: ques();break;
        case 5: s = 5;break;
        default: printf("请重新输入~");
    }
    return 0;
}
*/

/// in and out
void in_and_out(Stack &s1, Stack &s2, int n)
{
    car a;
    car b[1000];
    int nn;
    s_init(s1);
    s_init(s2);
    Queue *q;
    q = new node;
    int cnt = 0;
    int flag = 100;/// flag = 0 离开 flag = 1进入
    for(int i=0; i<n; i++){
                cout << "请输入车牌号" << endl;
                cin >> a.data;
                cout << "请选择进停车场 或者 离开" << endl;
                cin >> flag;
                if(flag == 1){
                    cout << "请输入时间" << endl;
                    cin >> a.time.hour_in;
                    b[cnt++] = a;
                    if(s1.top!=maxn){
                        s_push(a.data, s1);
                        cout << "the car stops at stop." << endl;
                        cout << "the position is " << cnt1++ << endl;
                    }

                    else
                    {
                        if(cnt2 == 0)
                        {
                            node *h = new node;
                            q->head = h;
                            q->tail = h;
                            h->data = a;
                        }
                        else{
                            queue_push(q, a);
                        }
                        cout << "the car stops at biandao." << endl;
                        cout << "the position is " << cnt2 << endl;
                        cnt2++;
                    }
            }
            else{
                cout << "Please input hour_out." << endl;
                int time1;
                cin >> time1;
                while(!Is_empty(s1)){
                    int t;
                    if(s1.data[s1.top-1] == a.data){
                        for(int j=0; j<cnt; j++){
                            if(b[j].data == a.data){
                                t = time1 - b[j].time.hour_in;
                            }
                        }
                        cout << "the time are " << t << " hours." << endl;
                        cout << "it will cost " << t*6 << " yuan";
                        break;
                    }

                    int bb;
                    bb = s_pop(s1);
                    s_push(bb, s2);

                }
                while(!Is_empty(s2)){
                    int bb;
                    bb = s_pop(s2);
                    s_push(bb, s1);
                }
            }
        }
}
/*
void ques()
{

}
*/

int main()
{
    int n;
    cin >> n;
    Stack s1, s2;
    in_and_out(s1, s2, n);
    return 0;
}








