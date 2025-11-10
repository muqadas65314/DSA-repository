#include <iostream>
using namespace std;

int main() {
    // Struct definition
    struct Dlist {
        int data;
        Dlist* next;
        Dlist* prev;
    };

    Dlist* head = NULL;
    Dlist* tail = NULL;

    // ------------------ CREATE CIRCULAR LIST ------------------
    int values[] = {10, 20, 30, 45, 50}; // predefined data for clarity
    int n = sizeof(values)/sizeof(values[0]);

    for(int i = 0; i < n; i++) {
        Dlist* newNode = new Dlist;
        newNode->data = values[i];
        newNode->next = newNode->prev = NULL;

        if(head == NULL) {
            head = tail = newNode;
            head->next = head->prev = head;  // circular
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }

    // ------------------ DISPLAY LIST (2 cycles to show circularity) ------------------
    cout << "Marks in circular list (2 cycles): ";
    if(head != NULL) {
        Dlist* temp = head;
        int count = 0;
        do {
            cout << temp->data << " ";
            temp = temp->next;
            count++;
        } while(temp != head || count < n*2); // print two full cycles
    }
    cout << endl;

    // ------------------ ADD AT BEGINNING ------------------
    cout << "\nAdding at beginning (value=100):\n";
    Dlist* newNode = new Dlist;
    newNode->data = 100;
    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
    head = newNode;

    // Display after addition
    cout << "Marks in circular list (2 cycles): ";
    Dlist* temp = head;
    int count = 0;
    do {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    } while(temp != head || count < (n+1)*2);
    cout << endl;

    // ------------------ ADD AFTER 45 ------------------
    cout << "\nAdding after 45 (value=200):\n";
    temp = head;
    bool found = false;
    do {
        if(temp->data == 45) {
            found = true;
            Dlist* newNode2 = new Dlist;
            newNode2->data = 200;
            newNode2->next = temp->next;
            newNode2->prev = temp;
            temp->next->prev = newNode2;
            temp->next = newNode2;
            if(temp == tail) tail = newNode2;
            break;
        }
        temp = temp->next;
    } while(temp != head);
    if(!found) cout << "Value 45 not found!" << endl;

    // Display after addition
    cout << "Marks in circular list (2 cycles): ";
    temp = head;
    count = 0;
    do {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    } while(temp != head || count < (n+2)*2);
    cout << endl;

    // ------------------ DELETE AT BEGINNING ------------------
    cout << "\nDeleting at beginning:\n";
    if(head == tail) { // only one node
        delete head;
        head = tail = NULL;
    } else {
        Dlist* delNode = head;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        delete delNode;
    }

    // Display after deletion
    cout << "Marks in circular list (2 cycles): ";
    if(head != NULL) {
        temp = head;
        count = 0;
        int size = n+2-1; // updated size after deletion
        do {
            cout << temp->data << " ";
            temp = temp->next;
            count++;
        } while(temp != head || count < size*2);
    }
    cout << endl;

    // ------------------ DELETE AFTER 45 ------------------
    cout << "\nDeleting after 45:\n";
    temp = head;
    found = false;
    if(head != NULL) {
        do {
            if(temp->data == 45) {
                found = true;
                Dlist* delNode2 = temp->next;
                if(delNode2 == tail) tail = temp;
                temp->next = delNode2->next;
                delNode2->next->prev = temp;
                delete delNode2;
                break;
            }
            temp = temp->next;
        } while(temp != head);
    }
    if(!found) cout << "No node exists after 45!" << endl;

    // Display final list
    cout << "Marks in circular list (2 cycles): ";
    if(head != NULL) {
        temp = head;
        count = 0;
        int size = n+2-2; // updated size after deletions
        do {
            cout << temp->data << " ";
            temp = temp->next;
            count++;
        } while(temp != head || count < size*2);
    }
    cout << endl;

    return 0;
}


