#include <iostream>
#define MAXSIZE 10

using namespace std;

template <typename T> class MyQueue{
    private:
    T *arr;
    int front = 0, rear = 0;

    public:
    MyQueue(){
        arr = new T[MAXSIZE];
        front = -1;
        rear = -1;
    }

    void Enqueue(T enqueue_value){
        if(rear == MAXSIZE-1){
            cout << "큐가 가득 찼습니다." << endl;
            return ;
        }
        cout << "EnQueue (" << enqueue_value << ")" << endl; 
        arr[++rear] = enqueue_value;
    }

    T DeQueue(){
        if(front == rear){
            cout << "큐가 비어있습니다" << endl;
            return NULL;
        }
        return arr[++front];
    }

    int front_loc(){
        return front;
    }   

    int rear_loc(){
        return rear;
    }

    int size_current(){
        return rear - front;
    }
};

int main(int argc, char const *argv[])
{
     MyQueue<string> myqueue;

    myqueue.Enqueue("문자");
    myqueue.Enqueue("공부");
    myqueue.Enqueue("독서");
    myqueue.Enqueue("사회");
    cout << "현재 front :" << myqueue.front_loc() << ", 현재 rear :" << myqueue.rear_loc() << endl;
    cout << "현재 큐의 요소 수 : " << myqueue.size_current() << endl;
    cout << "Dequeue() 실행 : " << myqueue.DeQueue() << endl;
    cout << "Dequeue() 실행 : " << myqueue.DeQueue() << endl;
    myqueue.Enqueue("방학");
    myqueue.Enqueue("코딩");
    cout << "현재 front :" << myqueue.front_loc() << ", 현재 rear :" << myqueue.rear_loc() << endl;
    cout << "현재 큐의 요소 수 : " << myqueue.size_current() << endl;
}
