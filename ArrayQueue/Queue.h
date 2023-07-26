#pragma once
#include <iostream>
struct Node {
        int data;

        Node* next;
        Node* prev;
};
class Queue
{
    
    Node** queue;
    int QueueLength;
    int MaxQueueLength;

public:
    Queue(int m) {
        MaxQueueLength = m;
        queue = new Node*[MaxQueueLength];
        QueueLength = 0;
    }
    ~Queue() {
        delete[] queue;
    }

    void Add(Node** node, int data) {
        if (!(IsFull())) {
            Node* newNode = new Node;
            newNode->data = data;

            newNode->next = nullptr;

            Node* temp = *node;
                // если в списке нет узлов
            if (*node == nullptr) {
                newNode->prev = nullptr;
                *node = newNode;
                queue[QueueLength] = newNode;
                QueueLength++;
                return;
            }

            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = newNode;
            newNode->prev = temp;
            queue[QueueLength] = newNode;
            QueueLength++;
        }
    }
    
    // удаление узла из списка
    Node* Extract() {
        if (!(IsEmpty())) {
            Node* temp = queue[0];
            
            for (int ii = 1; ii < QueueLength; ii++) {
                queue[ii - 1] = queue[ii];
                
            }
            QueueLength--;
            return temp;
        }
    }
    // вывод списка в консоль
    void displayList(Node* node) {
        std::cout << "\n_______________\n";
        for (int ii = 0; ii < QueueLength; ii++) {
            std::cout << "(" << queue[ii]->data << ")" << " ";
        }
        std::cout << "\n_______________\n";
    }

    void Clear() {
        QueueLength = 0;
    }
    bool IsEmpty() {
        return QueueLength == 0;
    }
    bool IsFull() {
        return MaxQueueLength == QueueLength;
    }
    int getLenght() {
        return QueueLength;
    }
};

