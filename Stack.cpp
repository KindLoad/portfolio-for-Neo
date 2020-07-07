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
            printf("스택이 꽉 차 있습니다.\n");
        }
        else {
            cout << "push(" << push_value << ") 실행\n";
            arr[top++] = push_value;
            size++;
        }   
    }

    ~MyStack(){
        delete[] arr;
    }

    T pop(){
        if(top == 0){
            printf("스택이 비어 있습니다.\n");
            return NULL;
        }
        else {
            size--;
            return arr[--top];
        }
    }

    T top_current(){
        if(top == 0){
            printf("스택이 비어 있습니다.\n");
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

    mystack.push("문자");
    mystack.push("공부");
    mystack.push("독서");
    mystack.push("사회");
    cout << "현재 스택 top의 값 : " << mystack.top_current() << endl;
    cout << "현재 스택의 요소 수 : " << mystack.size_current() << endl;
    cout << "pop() 실행 : " << mystack.pop() << endl;
    cout << "pop() 실행 : " << mystack.pop() << endl;
    mystack.push("방학");
    mystack.push("코딩");
    cout << "현재 스택 top의 값 : " << mystack.top_current() << endl;
    cout << "현재 스택의 요소 수 : " << mystack.size_current() << endl;
    
    return 0;
}
