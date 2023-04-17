#pragma once
#include <sstream>
#include <ostream>
#include "stack.h"
//this ^^ include stack.h line was missing and made me hate data structures and multi-file programming for a solid 30 minutes
template <typename TYPE>
class LinkedStack : public Stack<TYPE>
{
private:
    struct Node
    {
        TYPE data;
        Node *next;
        Node(TYPE item) : data(item), next(nullptr) {}
    };
    Node *top = nullptr;
    int size;

public:
    LinkedStack() : top(nullptr), size(0) {}
    ~LinkedStack()
    {
        Node *current = top;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }

    void push(TYPE item)
    {
        Node *temp = new Node(item);
        temp->data = item;
        temp->next = top;
        top = temp;
        size++;
    }
    void pop()
    {
        Node *temp;

        temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    TYPE peek()
    {
        if (!isEmpty())
        {
            return top->data;
        }
        else
            return -1;
    }
    int getSize()
    {
        return size;
    }
    void printStack(std::ostream &stream)
    {
        Node *temp = top;
        stream << "| ";
        while (temp != nullptr)
        {
            stream << temp->data << ", ";
            temp = temp->next;
        }
        stream << std::endl;
    }
};
