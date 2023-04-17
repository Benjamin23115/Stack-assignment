#pragma once
#include <sstream>
#include <ostream>
using std::stringstream;
// At the beginning I was using basic stack functions push pop peek etc (For 1 stack),
// but ultimately I changed them to work in conjunction with multiple stacks due to the assignment
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
    int top;
    int *arr;

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
        if (top == NULL)
        {
            exit(1);
        }
        else
        {
            temp = top;
            top = top->link;
            free(temp);
        }
    }
    bool isEmpty()
    {
        return top == NULL;
    }
    TYPE peek()
    {
        if (!isEmpty())
        {
            return top->data;
            else exit(1);
        }
    }
    int getSize()
    {
        return size;
    }
    void printStack(ostream &stream)
    {
        Node *temp;
        if (top == NULL)
        {
            exit(1);
        }
        else
        {
            temp = top;
            stream << | ;
            while (temp != NULL)
            {
                stream << " " << temp->data << ", ";
            }
            stream << std::endl;
        }
        free(temp);
    }
    int createStack(int size)
    {
        Node *temp = new LinkedStack;
        temp->size = size;
        temp->top = -1;
        stack->arr = new int[size];
        return temp;
    }
};
