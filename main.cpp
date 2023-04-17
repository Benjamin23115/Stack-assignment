#include <iostream>
#include "linkedstack.h"

// Function to solve Towers of Hanoi
void towersOfHanoi(int n, LinkedStack<int>& source, LinkedStack<int>& auxiliary, LinkedStack<int>& target)
{
    if (n > 0)
    {
        // Move n-1 discs from source to auxiliary peg
        towersOfHanoi(n - 1, source, target, auxiliary);

        // Move the nth disc from source to target peg
        int disk = source.peek();
        source.pop();
        target.push(disk);
        std::cout << "Move disk " << disk << " from source to target" << std::endl;

        // Move the n-1 discs from auxiliary to target peg
        towersOfHanoi(n - 1, auxiliary, source, target);
    }
}

int main()
{
    int n;
    std::cout << "Input the number of disks" << std::endl;
    std::cin >> n;
    LinkedStack<int> source, auxiliary, target;

    // Initialize the source peg with discs in ascending order from the bottom
    for (int i = 1; i <= n; i++)
    {
        source.push(i);
    }

    std::cout << "Initial state:" << std::endl;
    std::cout << "Source peg: ";
    source.printStack(std::cout);
    std::cout << "Auxiliary peg: ";
    auxiliary.printStack(std::cout);
    std::cout << "Target peg: ";
    target.printStack(std::cout);
    std::cout << "-----------------" << std::endl;

    // Call the function to solve Towers of Hanoi
    towersOfHanoi(n, source, auxiliary, target);

    std::cout << "Final state:" << std::endl;
    std::cout << "Source peg: ";
    source.printStack(std::cout);
    std::cout << "Auxiliary peg: ";
    auxiliary.printStack(std::cout);
    std::cout << "Target peg: ";
    target.printStack(std::cout);

    return 0;
}
