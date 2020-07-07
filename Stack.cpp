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
            printf("스택이 꽉 차 있습니다.\n");
        }
        else {
            printf("push(%d) 실행\n", push_value);
            arr[top++] = push_value;
            size++;
        }   
    }

    ~MyStack(){
        delete[] arr;
    }

    int pop(){
        if(top == 0){
            printf("스택이 비어 있습니다.\n");
            return -1;
        }
        else {
            size--;
            return arr[--top];
        }
    }

    int top_current(){
        if(top == 0){
            printf("스택이 비어 있습니다.\n");
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
    cout << "현재 스택 top의 값 : " << mystack.top_current() << endl;
    cout << "현재 스택의 요소 수 : " << mystack.size_current() << endl;
    cout << "pop() 실행 : " << mystack.pop() << endl;
    cout << "pop() 실행 : " << mystack.pop() << endl;
    mystack.push(5);
    mystack.push(6);
    cout << "현재 스택 top의 값 : " << mystack.top_current() << endl;
    cout << "현재 스택의 요소 수 : " << mystack.size_current() << endl;
    
    return 0;
}
