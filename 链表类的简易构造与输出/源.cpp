// 链表类的简易构造与输出   .cpp
//

#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

class  ListNode {
    friend  class  LinkList;    //声明LinkList为友元类
public:
    ListNode() { next = NULL; };
    ListNode(int  x) {
        val = x;
        next = NULL;
    }
private:
    int  val;  //数据域
    ListNode* next;  //指针域
};

class  LinkList {
public:
    LinkList(int* arr, int  len);  //构造函数
    ~LinkList();  //析构函数
    void  Output();
private:
    ListNode* head;//头指针，指向第一个结点
};

LinkList::LinkList(int* arr, int  len) {
    head = new ListNode;
    ListNode* b = new ListNode;
    b = head;
    for (int i = 0; i <len; i++) {
        ListNode* a = new ListNode;
        a->val = arr[i];
        a->next = NULL;
        b->next=a;
        b = a;
    }
}

LinkList::~LinkList() {
    cout << "The  LinkList  was  destroyed!" << endl;

}

void  LinkList::Output() {
    ListNode* p = head->next;
    while (p != NULL) {
        cout << p->val << "->";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int    main() {

    int    length;
    cin >> length;
    int* arr = new    int[length];
    for (int i = 0; i < length; i++)
        cin >> arr[i];

    LinkList  linklist(arr, length);
    linklist.Output();
    system("pause");
    return    0;
}
