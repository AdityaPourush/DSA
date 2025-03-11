#include <iostream>

using namespace std;

template <class T>
class CircularQueue{
private:
    T *arr;   // dynamic allocating memory for the array
    int front;  // front pointer
    int rear;  // rear pointer
    int size;  // total size of array i.e total elements the array can contain
    int capacity;  // current capacity i.e current size of the array

public:
    // Custructor to initialize a circular queue
    CircularQueue(int size){
        this->size = size;
        arr = new T[size];
        front = -1;
        rear = -1;
        capacity = 0;
    }

    // destructor to de-allocate memmory
    ~CircularQueue(){
        delete[] arr;
    }

    // function to check if the queue is full
    bool isFull(){
        return capacity == size;
    }

    // function to check if the queue is empty
    bool isEmpty(){
        return capacity == 0;
    }

    // Enque an element: push element into the queue
    void enqueue(T val){
        if(isFull()){
            cout << "Queue is Full, cannot enqueu more element." << val << endl;
            return;
        }
        if(isEmpty()){
            front = 0;
        }
        rear = (rear+1)%size;
        arr[rear] = val;
        capacity++;
        cout << "Enqueued " << val << endl;
    }

    // Dequeue an element: pop the front element
    void dequeue(){
        if(isEmpty()){
            cout << "Queue is already empty, what you want." << endl;
            return;
        }
        T val = arr[front];
        if(front == rear){
            front = rear = -1;
        }else {
            front = (front+1)%size;
        }
        capacity--;
        cout << "dequeued " << val << endl;
    }

    T peek(){
        if(isEmpty()){
            cout << "The Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    void display(){
        if(isEmpty()){
            cout << "The Queue is empty." << endl;
            return;
        }
        cout << "Queue Elements: " << endl;
        int i = front;
        while(true){
            cout << arr[i] << " ";
            if(i == rear) break;
            i = (i+1)%size;
        }
        cout << endl;
    }
};

int main(){
    CircularQueue<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    q.display();

    q.dequeue();
    q.dequeue();

    q.peek();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}