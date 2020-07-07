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
            cout << "ť�� ���� á���ϴ�." << endl;
            return ;
        }
        cout << "EnQueue (" << enqueue_value << ")" << endl; 
        arr[++rear] = enqueue_value;
    }

    T DeQueue(){
        if(front == rear){
            cout << "ť�� ����ֽ��ϴ�" << endl;
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

    myqueue.Enqueue("����");
    myqueue.Enqueue("����");
    myqueue.Enqueue("����");
    myqueue.Enqueue("��ȸ");
    cout << "���� front :" << myqueue.front_loc() << ", ���� rear :" << myqueue.rear_loc() << endl;
    cout << "���� ť�� ��� �� : " << myqueue.size_current() << endl;
    cout << "Dequeue() ���� : " << myqueue.DeQueue() << endl;
    cout << "Dequeue() ���� : " << myqueue.DeQueue() << endl;
    myqueue.Enqueue("����");
    myqueue.Enqueue("�ڵ�");
    cout << "���� front :" << myqueue.front_loc() << ", ���� rear :" << myqueue.rear_loc() << endl;
    cout << "���� ť�� ��� �� : " << myqueue.size_current() << endl;
}
