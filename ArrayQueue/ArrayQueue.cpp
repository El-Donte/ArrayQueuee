#include <iostream>
#include"Queue.h"
#include"doubleLinkedList.h"
int main()
{//--------------задание 1---------
    /*Queue queue(7);
    Node* head = nullptr;

    queue.Add(&head, 5);
    queue.Add(&head, 1);
    queue.Add(&head, 8);
    queue.Add(&head, 7);
    
    queue.Extract();
    std::cout << queue.getLenght();
    queue.displayList(head);
    std::cout << std::endl;

    queue.Extract();
    std::cout << queue.getLenght();
    queue.displayList(head);
    std::cout << std::endl;

    queue.Extract();
    std::cout << queue.getLenght();
    queue.displayList(head);
    std::cout << std::endl;*/
//-------------задание 2------------
    doubleLinkedList myList;
    doubleLinkedList myList2;
    doubleLinkedList::node* ptr;

    ptr = myList.initNode("string 1", 1);
    myList.addNode(ptr);
    ptr = myList.initNode("string 6", 6);
    myList.addNode(ptr);
    ptr = myList.initNode("string 4", 4);
    myList.addNode(ptr);
    ptr = myList.initNode("string 2", 2);
    myList.addNode(ptr);

    /*ptr = myList2.initNode("string 123", 10);
    myList2.addNode(ptr);
    ptr = myList2.initNode("string 235", 8);
    myList2.addNode(ptr);
    ptr = myList2.initNode("string 654", 5);
    myList2.addNode(ptr);
    ptr = myList2.initNode("string 423", 3);
    myList2.addNode(ptr);
    myList + myList2;*/

    myList.displayList(myList.head);
    std::cout << std::endl;


    myList2.Clone(myList);

    myList2.displayList(myList2.head);
    std::cout << std::endl;

}
