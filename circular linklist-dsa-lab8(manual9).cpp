#include<iostream>
using namespace std;

int queueArr[5], n = 5, front = -1, rare = -1, val;

// ? Circular Enqueue
void enqueue() {
    if ((front == 0 && rare == n-1) || (rare == (front - 1))) {
        cout << " queue overflow" << endl;
    }
    else {
        cout << "enter value: " << endl;
        cin >> val;

        if (front == -1) {  // first value
            front = 0;
            rare = 0;
        }
        else if (rare == n - 1 && front != 0) { 
            rare = 0; 
        }
        else { 
            rare++;
        }

        queueArr[rare] = val;
    }
}

// ? Circular Dequeue
void dequeue() {
    if (front == -1) {
        cout << " queue underflow" << endl;
    }
    else {
        cout << " element is deleted " << queueArr[front] << endl;

        if (front == rare) {
            front = -1;
            rare = -1;
        }
        else if (front == n - 1) {
            front = 0;
        }
        else {
            front++;
        }
    }
}

// ? Display Queue
void display() {
    if (front == -1) {
        cout << " queue empty";
    }
    else {
        cout << "\nQueue: ";
        if (rare >= front) {
            for (int i = front; i <= rare; i++)
                cout << queueArr[i] << " ";
        }
        else {
            for (int i = front; i < n; i++)
                cout << queueArr[i] << " ";
            for (int i = 0; i <= rare; i++)
                cout << queueArr[i] << " ";
        }
        cout << endl;
    }
}

int main() {

    // ? Insert elements
    for(int i = 0; i < n; i++) {
        enqueue();
    }

    display();

    // ? Delete only 2 elements
    for(int i = 0; i < 2; i++) {
        dequeue();
    }

    display();

    // ? Insert again to test circular queue
    enqueue();
    enqueue();

    display();

    return 0;
}

