#pragma once
#include<iostream>
//--------------------- двусвязный список -------------------//



class doubleLinkedList {
public:
    struct node {
    int id;
    std::string name;
    node* next;
    node* prev;
    }*head, * tail, * ptr;

    doubleLinkedList() :head{ nullptr }, tail{ nullptr }, ptr{ nullptr } {}
    ~doubleLinkedList();

    void displayList(node*); // îòîáðàæåíèå â êîíñîëè âñåõ óçëîâ
    void displayNode(node*); // îòîáðàæåíèå óçëà
    void addNode(node*); // äîáàâëåíèå óçëà
    void insertNode(node*); // âñòàâêà óçëà
    void deleteNode(node*); // óäàëåíèå óçëà
    void deleteList(node*); // óäàëåíèå ñïèñêà

    node* initNode(std::string, int); // èíèöèàëèçàöèÿ ñòðóêòóðû
    node* searchName(node*, std::string); // ïîèñê ïî èìåíè
    node* searchId(node*, int); //ïîèñê ïî ID

    node* Clone(doubleLinkedList& list);
    friend node* operator+(doubleLinkedList& list1, doubleLinkedList& list2);
};

//--------------------- двусвязный список -------------------//