#include"doubleLinkedList.h"
#include<iostream>
doubleLinkedList::~doubleLinkedList() {
	node* temp = head;
	while (temp != nullptr)
	{
		temp = temp->next;
		delete head;
		head = temp;
	}
}

doubleLinkedList::node* doubleLinkedList::initNode(std::string name, int id) {
	node* ptr = new node;
	if (ptr == nullptr) return nullptr;

	ptr->name = name;
	ptr->id = id;
	ptr->next = nullptr;
	ptr->prev = nullptr;
	return ptr;
}
doubleLinkedList::node* doubleLinkedList::searchName(node* ptr, std::string name) {
	while (name != ptr->name)
	{
		ptr = ptr->next;
		if (ptr == nullptr) break;
	}
	return ptr;
}
doubleLinkedList::node* doubleLinkedList::searchId(node* ptr, int id) {
	while (id != ptr->id)
	{
		ptr = ptr->next;
		if (ptr == nullptr) break;
	}
	return ptr;
}


void doubleLinkedList::addNode(node* newNode) {
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		tail->next = nullptr;
		head->prev = nullptr;
	}
	else {
		tail->next = newNode;
		newNode->next = nullptr;
		newNode->prev = tail;
		tail = newNode;
	}
}
void doubleLinkedList::insertNode(node* newNode) {
	node* temp;
	if (head == nullptr) {
		addNode(newNode);
		return;
	}

	temp = head;
	while (temp->id < newNode->id) {
		temp = temp->next;
		if (temp == nullptr) break;
	}

	if (temp == head) {
		newNode->next = head;
		newNode->prev = nullptr;
		head->prev = newNode;
		head = newNode;
	}
	else {

		newNode->next = temp;
		temp->prev->next = newNode;
		newNode->prev = temp->prev;
		

		if (tail == temp->prev)
			tail = newNode;
	}
}
void doubleLinkedList::deleteNode(node* ptr) {
	node* temp;
	temp = ptr;


	if (temp == head) {
		head = head->next;
		head->prev = nullptr;
		if (tail == temp) {
			tail = tail->next;
			tail->prev = nullptr;
		}
			
	}
	else {
		temp = temp->next;
		if (tail == temp) {
			tail = temp->prev;
			tail->next = nullptr;
		}
	}
	delete temp;
}

//void doubleLinkedList::deleteList(node* ptr) {
//	node* temp;
//
//	if (head == nullptr) return; // åñëè ñïèñîê ïóñò, ïðåêðàùàåì âûïîëíåíèå ìåòîäà
//
//	if (ptr == head) {
//		head = nullptr;
//		tail = nullptr;
//	}
//	else {
//		temp = head;
//		while (temp->next != ptr) {
//			temp = temp->next;
//		}
//		tail = temp;
//	}
//
//	while (ptr != nullptr)
//	{
//		temp = ptr->next;
//		delete ptr;
//		ptr = temp;
//	}
//}

void doubleLinkedList::displayList(node* p) {
	if (!p) std::cout << "Nothing to display\n";
	while (p) {
		std::cout << p->id << " " << p->name << std::endl;
		p = p->next;
	}
}

doubleLinkedList::node* operator+(doubleLinkedList& list1, doubleLinkedList& list2) {
	list1.tail->prev->next = list2.head;
	list1.tail = list2.head;
	list1.tail->next = list2.head->next;
	list2.head->prev = list1.tail;
	list2.head = list2.head->next;

	

	while (list1.tail->next != nullptr) {
		list1.tail = list2.head;
		list1.tail->next = list2.head->next;
		list2.head->prev = list1.tail;
		list2.head = list2.head->next;
	}

	return list1.head;
}

doubleLinkedList::node* doubleLinkedList::Clone(doubleLinkedList& list) {
	head = list.head;
	tail = list.head;

	while (tail->next != nullptr) {
		tail = list.head;
		tail->next = list.head->next;
		tail->prev = list.head->prev;
		list.head = list.head->next;
	}
	return head;
}