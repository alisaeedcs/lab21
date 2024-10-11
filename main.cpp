#include <iostream>

using namespace std;

const int SIZE = 15;
const int MIN_AGE = 1, MAX_AGE = 20, MIN_LS = 5, MAX_LS = 20;

class Goat {
private:
    int age;
    string name;
    string color;
    string names[SIZE]; 
    string colors[SIZE]; 
public:
    Goat() {
        age = (rand() % MAX_AGE) + MIN_AGE;
        string names[SIZE] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hannah", "Ivy", "Jack", "Karen", "Liam", "Mona", "Nina", "Oscar"};
        string colors[SIZE] = {"Red", "Blue", "Green", "Yellow", "Orange", "Purple", "Pink", "Brown", "Black", "White", "Gray", "Cyan", "Magenta", "Teal", "Maroon"};
        name = names[(rand() % SIZE)];
        color = colors[(rand() % SIZE)];
        
    };
    Goat(int a, string n, string c) { 
        age = a; 
        name = n; 
        color = c; 
        string names[SIZE] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hannah", "Ivy", "Jack", "Karen", "Liam", "Mona", "Nina", "Oscar"};
        string colors[SIZE] = {"Red", "Blue", "Green", "Yellow", "Orange", "Purple", "Pink", "Brown", "Black", "White", "Gray", "Cyan", "Magenta", "Teal", "Maroon"};
      
    }

    //getter methods
    int getAge() const { return age; }
    string getName() const { return name; }
    string getColor() const { return color; }
};

class DoublyLinkedList {
private:
    struct Node {
        Goat goat;
        Node* prev;
        Node* next;
        Node(Goat& g, Node* p = nullptr, Node* n = nullptr) {
            goat = g; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(Goat& g) {
        Node* newNode = new Node(g);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat& g) {
        Node* newNode = new Node(g);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty" << endl;
            return;
        }
        while (current) {
            cout << "\t" << current->goat.getName() << " (" << current->goat.getColor() << ", " << current->goat.getAge() << ")" << endl;
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) {
            cout << "List is empty" << endl;
            return;
        };
        while (current) {
            cout << "\t" << current->goat.getName() << " (" << current->goat.getColor() << ", " << current->goat.getAge() << ")" << endl;
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    srand(time(0));

    DoublyLinkedList list;
    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS; // Random size between 5 and 20

    // Adding random goats to the list
    for (int i = 0; i < size; ++i) {
        Goat goat;
        list.push_back(goat);
    }
    cout << "Forward: " << endl;
    list.print();

    cout << "\nBackward:" << endl;
    list.print_reverse();

    return 0;
}