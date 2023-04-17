#pragma once
#include <sstream>
#include <ostream>
using std::stringstream;
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
        if (top == nullptr)
        {
            throw std::runtime_error("Stack is empty");
        }
        else
        {
            temp = top;
            top = top->next;
            delete temp;
            size--;
        }
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
        {
            throw std::runtime_error("Stack is empty");
        }
    }
    int getSize()
    {
        return size;
    }
    void printStack(ostream &stream)
    {
        Node *temp = top;
        stream << | ;
        while (temp != nullptr)
        {
            stream << " " << temp->data << ", ";
            temp = temp->next;
        }
        stream << std::endl;
    }
};
