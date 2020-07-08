#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

#define HEAP_SIZE 30

class PriorityQueue{ // value를 우선순위로 지정하기 위해서 template T를 사용하지 않음
    private:
    int heap[HEAP_SIZE];
    int heap_count = 0; // heap의 원소의 갯수

    public:
    PriorityQueue(){
        heap_count = 0;
    }

    void swap(int * a, int * b) { //swap 함수
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }

    int size() { //크기 확인
        return heap_count;
    }

    void push(int value) {

        heap[++heap_count] = value; // 끝에 데이터 추가

        int child = heap_count;
        int parent = child / 2;
        //자식과 부모 노드의 초기화

        while (child > 1 && heap[parent] < heap[child]) { // 자식이 1보다 크고 부모의 값이 자식의 값보다 작을 때
            swap(&heap[parent], &heap[child]); // 스왑진행
            child = parent; // child 초기화
            parent = child / 2; // parent 초기화
        }
        printf("PUSH() <= %d\n", value);
    }

    int pop() {

        int temp = heap[1]; //출력될 값을 미리 저장

        swap(&heap[1], &heap[heap_count]); //힙의 가장 끝의 숫자와 가장 첫번째 숫자를 교환
        heap_count--; //숫자 크기를 하나 줄임으로써 마지막으로 간 숫자에 접근 불가

        int parent = 1; 
        int child = parent * 2;
        if (child + 1 <= heap_count) {  //child + 1이 만약 존재 한다면
            child = (heap[child] > heap[child + 1]) ? child : child + 1;
        }   //child 중에 더 큰 숫자를 골라서 child로 결정
        

        while (child <= heap_count && heap[parent] < heap[child]) { //정렬 반복
            swap(&heap[parent], &heap[child]);

            parent = child;
            child = child * 2;
            if (child + 1 <= heap_count) {
                child = (heap[child] > heap[child + 1]) ? child : child + 1;
            }
        }

        printf("POP() => %d\n", temp);
        return temp;
    }
};

int main(void) {

    srand((unsigned int)time(NULL));
	PriorityQueue pq = PriorityQueue();
    

    for(int i = 5 ; 0 < i; i--){
        pq.push(rand()%10);
    }

    printf("Now Size() : %d\n", pq.size());


    for(int i = 0 ; i < 10; i++){
        pq.pop();
    }

	return 0;
}