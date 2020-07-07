#include <iostream>
#define MAXSIZE 10

using namespace std;

class MyStack{
    int *arr;
    int top, size;

    public:
    MyStack(){
        arr = new int[MAXSIZE];
        top = 0;
        size = 0;
    }

    void push(int push_value){
        if(top == MAXSIZE){
            printf("������ �� �� �ֽ��ϴ�.\n");
        }
        else {
            printf("push(%d) ����\n", push_value);
            arr[top++] = push_value;
            size++;
        }   
    }

    ~MyStack(){
        delete[] arr;
    }

    int pop(){
        if(top == 0){
            printf("������ ��� �ֽ��ϴ�.\n");
            return -1;
        }
        else {
            size--;
            return arr[--top];
        }
    }

    int top_current(){
        if(top == 0){
            printf("������ ��� �ֽ��ϴ�.\n");
            return -1;
        }
        else return arr[top-1];
    }

    int size_current(){
        return size;
    }

};

int main(int argc, char const *argv[])
{
    MyStack mystack;

    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    mystack.push(4);
    cout << "���� ���� top�� �� : " << mystack.top_current() << endl;
    cout << "���� ������ ��� �� : " << mystack.size_current() << endl;
    cout << "pop() ���� : " << mystack.pop() << endl;
    cout << "pop() ���� : " << mystack.pop() << endl;
    mystack.push(5);
    mystack.push(6);
    cout << "���� ���� top�� �� : " << mystack.top_current() << endl;
    cout << "���� ������ ��� �� : " << mystack.size_current() << endl;
    
    return 0;
}
