#include <ostream>
#include <iostream>
#include <math.h>
#include "stack.h"
using namespace std;
// For this assignment I used the following links as guides
//  https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/
//  https://cppsecrets.com/users/10311151075750485755545564103109971051084699111109/C00-Program-to-Solve-Tower-of-Hanoi-Problem-using-stacks.php
void Move_Disc_Helper(LinkedStack<int> &A, LinkedStack<int> &B, char s, char d)
{
    int top1 = A.pop();
    int top2 = B.pop();
    if (top1 == -1)
    {
        push(A, top2);
        Move_Disc(top2, d, s);
    }
    else if (top2 == -1)

    {
        push(B, top1);
        Move_Disc(top1, s, d);
    }
    else if (top1 > top2)
    {
        push(A, top1);
        push(A, top2);
        Move_Disc(top2, d, s);
    }
    else
    {
        push(B, top2);
        push(B, top1);
        Move_Disc(top1, s, d);
    }
}

void TowerOfHanoi(int number_of_discs, LinkedStack<int> &A, LinkedStack<int> &C, LinkedStack<int> &B)

{
    char s = 'S', d = 'D', a = 'A';

    //  if n is even swap C and B
    if (number_of_discs % 2 == 0)
    {
        char temp = d;
        d = a;
        a = temp;
    }

    int number_of_moves = pow(2, number_of_discs) - 1;
    for (int i = number_of_discs; i >= 1; i--)
    {
        push(A, i);
    }

    // iteration of each i upto number of moves
    for (int i = 1; i <= number_of_moves; i++)
    {
        if (i % 3 == 0)
            Move_Disc_Helper(C, B, a, d);
        else if (i % 3 == 2)
            Move_Disc_Helper(A, C, s, a);
        else if (i % 3 == 1)
            Move_Disc_Helper(A, B, s, d);
    }
}
int main(int argc, char const *argv[])
{
    int disks;
    std::cout << "Please enter a stack amount" << endl;
    std::cin >> disks;
    LinkedStack<int> A = createStack(disks);
    LinkedStack<int> B = createStack(disks);
    LinkedStack<int> C = createStack(disks);
    TowerOfHanoi(disks, A, C, B);

    return 0;
}
