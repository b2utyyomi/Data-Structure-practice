#include <iostream>
#include<cstring>
using namespace std;

const int len = 13;
int hash1[len];
int hash_(int num)
{
    return num%len;
}
void collision(int elem, int num)
{
    if(elem == len){
        elem = 0;
    }
    if(hash1[elem] == 0){
        hash1[elem] = num;
    }
    else{
        collision(elem+1, num);
    }
}
void print()
{
    for(int i=0; i<len; i++){
        cout << "hash1[" << i << "]" << ": ";
        cout << hash1[i] << endl;
    }
}
void find_it(int n)
{
    int i;
    for(i=0; i<len; i++){
        if(hash1[i] == n){
            cout << "find it at " << i << endl;
            break;
        }
    }
    if(i == len)
        cout << "not found" << endl;
}
void delete_it(int n)
{
    int i;
    for(i=0; i<len; i++){
        if(hash1[i] == n){
            hash1[i] = 0;
            cout << "delete successful" << endl;
            break;
        }
    }
    if(i == len)
        cout << "not found" << endl;

}

void insert_it(int n)
{
    int elem = hash_(n);
    collision(elem, n);
}
int main()
{
    int a[11] = {16, 74, 60, 43, 54, 90, 46, 31, 29, 88, 77};
    memset(hash1, 0, sizeof(hash1));
    for(int i=0; i<11; i++){
        int elem = hash_(a[i]);
        collision(elem, a[i]);
    }
    print();
    find_it(29);
    delete_it(77);
    print();
    insert_it(77);
    print();
    return 0;
}


/*
16 74 60 43 54 90 46 31 29 88 77
*/

/*
hash1[0]: 77
hash1[1]: 0
hash1[2]: 54
hash1[3]: 16
hash1[4]: 43
hash1[5]: 31
hash1[6]: 29
hash1[7]: 46
hash1[8]: 60
hash1[9]: 74
hash1[10]: 88
hash1[11]: 0
hash1[12]: 90

Process returned 0 (0x0)   execution time : 2.356 s
Press any key to continue.

*/
