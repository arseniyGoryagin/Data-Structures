#include <cstdarg>

template<typename T>
struct Node {

  T data;
  Node *next;
};


template <typename T>
class LinkedList {

  Node<T> *first = nullptr;

  Node<T> *makeNode(T value) {
    Node<T> *newNode = new Node<T>();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
  }

public:

  Node<T> *getFirst() { return first; }

  void insert(int value) {
    Node<T>*temp = makeNode(value);
    temp->next = first;
    first = temp;
  }

  // no size checking
  void insertAt(T value, int position) {

    Node<T> *newNode = makeNode(value);

    if (position == 0) {
      newNode->next = first;
      first = newNode;
    }

    Node<T>*iterNode = first;
    for (int i = 0; i < position - 1; i++) {
      iterNode = iterNode->next;
    }

    Node<T> *tempNode = iterNode->next;

    iterNode->next = newNode;
    newNode->next = tempNode;
  }

  Node<T> *getLastNode() {
    Node<T> *temp = first;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    return temp;
  }

  void insertAtEnd(T value) {

    Node<T> *newNode = makeNode(value);

    if (first == nullptr) {
      first = newNode;
      return;
    }

   Node<T> *lastNode = getLastNode();
    lastNode->next = newNode;
  }

  void deleteAt(T position){


        if (position == 0) {
            Node<T> * temp = first;
            first = first->next;
            delete temp;
            return;
        }


        Node<T>* iterNode = first;

        for(int i = 0; i != position -1; i++){
            iterNode = iterNode->next;
        }


        Node<T>* toDeteleNode = iterNode->next;

        iterNode->next = toDeteleNode->next;

        delete toDeteleNode;
        
    }

    void reverse(){

        Node<T>* prev, * current, * nextNode;

        current = first;
        prev = nullptr;
       
        while(current != nullptr){

            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;

        }

        first = prev;
    }

};
