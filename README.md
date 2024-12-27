# 🎉 **Queue - Linked List Implementation in C++**

This repository contains a **Linked List-based Queue** implementation in C++. A queue follows the **FIFO (First In, First Out)** principle, where the first element inserted is the first one to be removed.

---

## 🌟 **Features**

- **enqueue**: Adds an element at the rear of the queue.
- **dequeue**: Removes an element from the front of the queue.
- **getFront**: Returns the element at the front of the queue without removing it.
- **getRear**: Returns the element at the rear of the queue without removing it.
- **getSize**: Returns the current size (length) of the queue.
- **display**: Displays all the items in the queue from front to rear.
- **clearQueue**: Clears all items from the queue.
- **isEmpty**: Checks whether the queue is empty.

---

## 🔍 **Code Structure**

### **Node Structure**

Each `Node` in the queue contains:
- **`item`**: The element stored in the node.
- **`next`**: Pointer to the next node in the queue.

### **linkedQueue Class**

The `linkedQueue` class provides the following methods:
- **`enqueue(t element)`**: Adds an element to the rear of the queue.
- **`dequeue()`**: Removes the element from the front of the queue.
- **`getFront()`**: Returns the front element of the queue.
- **`getRear()`**: Returns the rear element of the queue.
- **`getSize()`**: Returns the current number of elements in the queue.
- **`display()`**: Displays all elements in the queue from front to rear.
- **`clearQueue()`**: Clears the entire queue.
- **`isEmpty()`**: Checks whether the queue is empty.

---

## 📋 **Example Usage**
int main() {
    linkedQueue<int> q1;

    q1.enqueue(100);
    q1.enqueue(200);
    q1.enqueue(300);
    q1.display(); // Output: Items in the queue: [100 200 300]

    q1.dequeue();
    q1.display(); // Output: Items in the queue: [200 300]

    return 0;
}



Here’s the README for your Queue (Linked List Implementation) in C++ with appropriate Markdown formatting for better clarity and readability.

markdown
Copy code
# 🎉 **Queue - Linked List Implementation in C++**

This repository contains a **Linked List-based Queue** implementation in C++. A queue follows the **FIFO (First In, First Out)** principle, where the first element inserted is the first one to be removed.

---

## 🌟 **Features**

- **enqueue**: Adds an element at the rear of the queue.
- **dequeue**: Removes an element from the front of the queue.
- **getFront**: Returns the element at the front of the queue without removing it.
- **getRear**: Returns the element at the rear of the queue without removing it.
- **getSize**: Returns the current size (length) of the queue.
- **display**: Displays all the items in the queue from front to rear.
- **clearQueue**: Clears all items from the queue.
- **isEmpty**: Checks whether the queue is empty.

---

## 🔍 **Code Structure**

### **Node Structure**

Each `Node` in the queue contains:
- **`item`**: The element stored in the node.
- **`next`**: Pointer to the next node in the queue.

### **linkedQueue Class**

The `linkedQueue` class provides the following methods:
- **`enqueue(t element)`**: Adds an element to the rear of the queue.
- **`dequeue()`**: Removes the element from the front of the queue.
- **`getFront()`**: Returns the front element of the queue.
- **`getRear()`**: Returns the rear element of the queue.
- **`getSize()`**: Returns the current number of elements in the queue.
- **`display()`**: Displays all elements in the queue from front to rear.
- **`clearQueue()`**: Clears the entire queue.
- **`isEmpty()`**: Checks whether the queue is empty.

---

## 📋 **Example Usage**

```cpp
#include <iostream>
using namespace std;

template<class t>
class linkedQueue {
private:
    struct Node {
        t item;
        Node *next;
    };
    Node *frontPtr;
    Node *rearPtr;
    int length;

public:
    linkedQueue() {
        frontPtr = rearPtr = NULL;
        length = 0;
    }

    bool isEmpty() {
        return length == 0;
    }

    void enqueue(t element) {
        if (isEmpty()) {
            frontPtr = new Node;
            frontPtr->item = element;
            frontPtr->next = NULL;
            rearPtr = frontPtr;
            length++;
        }
        else {
            Node *newPtr = new Node;
            newPtr->item = element;
            newPtr->next = NULL;
            rearPtr->next = newPtr;
            rearPtr = newPtr;
            length++;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Empty Queue, Cannot Dequeue...!" << endl;
        }
        else {
            Node *tempPtr = frontPtr;
            if (frontPtr == rearPtr) {
                frontPtr = NULL;
                rearPtr = NULL;
                length--;
            }
            else {
                length--;
                frontPtr = frontPtr->next;
                tempPtr->next = NULL;
                delete tempPtr;
            }
        }
    }

    t getFront() {
        return frontPtr->item;
    }

    t getRear() {
        return rearPtr->item;
    }

    int getSize() {
        return length;
    }

    void display() {
        Node *curPtr = frontPtr;
        cout << "Items in the queue: [";

        while (curPtr != NULL) {
            cout << curPtr->item << " ";
            curPtr = curPtr->next;
        }
        cout << "]" << endl;
    }

    void clearQueue() {
        Node *current;
        while (frontPtr != NULL) {
            current = frontPtr;
            frontPtr = frontPtr->next;
            delete current;
        }
        rearPtr = NULL;
        length = 0;
    }
};

int main() {
    linkedQueue<int> q1;

    q1.enqueue(100);
    q1.enqueue(200);
    q1.enqueue(300);
    q1.display(); // Output: Items in the queue: [100 200 300]

    q1.dequeue();
    q1.display(); // Output: Items in the queue: [200 300]

    return 0;
}
🧑‍💻 Example Output
bash
Copy code
Items in the queue: [100 200 300]
Items in the queue: [200 300]
