
#include<iostream>
#define MAX 20
using namespace std;

class DoubleQueue {
    private:
        int array[MAX];
        int front1= -1;
		int rear1 = -1;
        int front2 = MAX, rear2 = MAX;

    public:
        void enqueue(int queue, int value) {
            if (rear1 + 1 == rear2) {
                cout << "Queue is overflow" << endl;
                return;
            }
            if (queue == 1) {
                if (rear1 == -1 && front1 == -1) {
                    rear1 = front1 = 0;
                } else {
                    rear1++;
                }
                array[rear1] = value;
                cout << array[rear1] << " added to queue 1" << endl;
            } else if (queue == 2) {
                if (rear2 == MAX && front2 == MAX) {
                    rear2 = front2 = MAX - 1;
                } else {
                    rear2--;
                }
                array[rear2] = value;
                cout << array[rear2] << " added to queue 2" << endl;
            } else {
                cout << "Invalid queue number" << endl;
            }
        }

        void dequeue(int queue) {
            if (queue == 1) {
                if (rear1 == -1 || front1 > rear1) {
                    cout << "Queue 1 is empty" << endl;
                } else {
                    cout << array[front1] << " is deleted from queue 1" << endl;
                    if (front1 == rear1) {
                        front1 = rear1 = -1;
                    } else {
                        front1++;
                    }
                }
            } else if (queue == 2) {
                if (rear2 == MAX || front2 < rear2) {
                    cout << "Queue 2 is empty" << endl;
                } else {
                    cout << array[front2] << " is deleted from queue 2" << endl;
                    if (front2 == rear2) {
                        front2 = rear2 = MAX;
                    } else {
                        front2--;
                    }
                }
            } else {
                cout << "Invalid queue number" << endl;
            }
        }

        void display() {
            cout << "Queue 1: ";
            if (rear1 == -1 || front1>rear1) {
                cout << "Empty.." << endl;
            } else {
                for (int i = front1; i <= rear1; i++) {
                    cout << array[i] << " ";
                }
                cout << endl;
            }

            cout << "Queue 2: ";
            if (front2 == MAX || front2 < rear2) {
                cout << "Empty..." << endl;
            } else {
                for (int i = front2; i >= rear2; i--) {
                    cout << array[i] << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    DoubleQueue dq;
    int ch, value, queue;
    do {
        cout << "\n1. EnQueue";
        cout << "\n2. DeQueue";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Insertion Queue(1 or 2): ";
                cin >> queue;
                cout << "Enter value: ";
                cin >> value;
                dq.enqueue(queue, value);
                break;

            case 2:
                cout << "Deletion Queue(1 or 2): ";
                cin >> queue;
                dq.dequeue(queue);
                break;

            case 3:
                dq.display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (ch != 4);
return 0;
}

