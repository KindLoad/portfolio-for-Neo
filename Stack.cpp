#include <iostream>
#define MAXSIZE 10

using namespace std;

template <typename T> class MyStack{
    T *arr;
    int top, size;

    public:
    MyStack(){
        arr = new T[MAXSIZE];
        top = 0;
        size = 0;
    }

    void push(T push_value){
        if(top == MAXSIZE){
            printf("������ �� �� �ֽ��ϴ�.\n");
        }
        else {
            cout << "push(" << push_value << ") ����\n";
            arr[top++] = push_value;
            size++;
        }   
    }

    ~MyStack(){
        delete[] arr;
    }

    T pop(){
        if(top == 0){
            printf("������ ��� �ֽ��ϴ�.\n");
            return NULL;
        }
        else {
            size--;
            return arr[--top];
        }
    }

    T top_current(){
        if(top == 0){
            printf("������ ��� �ֽ��ϴ�.\n");
            return NULL;
        }
        else return arr[top-1];
    }

    int size_current(){
        return size;
    }

};

int main(int argc, char const *argv[])
{
    MyStack<string> mystack;

    mystack.push("����");
    mystack.push("����");
    mystack.push("����");
    mystack.push("��ȸ");
    cout << "���� ���� top�� �� : " << mystack.top_current() << endl;
    cout << "���� ������ ��� �� : " << mystack.size_current() << endl;
    cout << "pop() ���� : " << mystack.pop() << endl;
    cout << "pop() ���� : " << mystack.pop() << endl;
    mystack.push("����");
    mystack.push("�ڵ�");
    cout << "���� ���� top�� �� : " << mystack.top_current() << endl;
    cout << "���� ������ ��� �� : " << mystack.size_current() << endl;
    
    return 0;
}
