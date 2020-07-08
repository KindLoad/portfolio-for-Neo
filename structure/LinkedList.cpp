#include <iostream>
#include <string>

using namespace std;

class MyNode{
    friend class MyLinkedList;
    private:
    int value;
    MyNode* next_addr;

    public:
        MyNode(){
            this->value = -1;
            next_addr = NULL;
        }
        MyNode(int value){
            this->value = value;
            next_addr = NULL;
        }
};

class MyLinkedList{
    private:
        MyNode* head;
    public:
        MyLinkedList(){
            head = NULL;
        }

        void Add(int add_value){
            MyNode* newNode = new MyNode(add_value);
            if(head == NULL){
                head = newNode;
            } else {
                MyNode *NowNode = head;
                for(MyNode *ptr=head;ptr!=NULL;ptr=ptr->next_addr) NowNode=ptr;
                NowNode->next_addr = newNode;
            }
        }

        void Remove(int remove_value){
            if(head == NULL){
                cout << "현재 리스트는 비어있습니다." << endl;
            }
            else
            {
                MyNode *NowNode = head;
                MyNode *BeforeNode = NULL;
                for(MyNode *ptr = head ; ptr != NULL ; ptr = ptr->next_addr){
                    BeforeNode = NowNode;
                    NowNode = ptr;
                    if(NowNode->value == remove_value){
                        if(NowNode == head && BeforeNode == head){
                            head = NowNode->next_addr;
                        }
                        else BeforeNode->next_addr=NowNode->next_addr;
                        delete NowNode;
                        return;
                    }
                }
                cout << "값을 찾을 수 없습니다." <<endl;
            }
            return;
        }

        void printList(){
            if(head==NULL){
                cout << "현재 리스트는 비어있습니다." <<endl;
                return;
            }
            for(MyNode *ptr = head ; ptr != NULL ; ptr = ptr->next_addr){
                cout << ptr->value << " ";
            }
            cout << endl;
        }
};

int main(int argc, char const *argv[])
{
    MyLinkedList ml = MyLinkedList();

    ml.Add(1);
    ml.Add(5);
    ml.Add(2);
    ml.Add(4);
    ml.printList();
    ml.Remove(2);
    ml.Add(15);
    ml.Add(19);
    ml.printList();
    
    return 0;
}
