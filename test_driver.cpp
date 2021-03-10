//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file test_driver.cpp */
#include "BagInterface.h"
#include "ArrayBag.h"
#include "ArrayLinkedBag.h"
#include "LinkedBag.h"
#include <algorithm>
#include <iostream>
#include <string>

void displayBag(BagInterface<std::string>* bagPtr)
{
    std::cout << "The bag contains " << bagPtr->getCurrentSize()
        << " items:" << std::endl;
    std::vector<std::string> bagItems = bagPtr->toVector();
    std::sort(bagItems.begin(), bagItems.end());
    int numberOfEntries = bagItems.size();
    for (int i = 0; i < numberOfEntries; i++)
    {
        std::cout << bagItems[i] << " ";
    } // end for
    std::cout << std::endl << std::endl;
} // end displayBag

void bagTester(BagInterface<std::string>* bagPtr)
{
    std::cout << "isEmpty: returns " << bagPtr->isEmpty() 
        << "; should be 1 (true)" << std::endl;
    displayBag(bagPtr);

    std::string items[] = {"one", "two", "three", "four", "five", "one"};
    std::cout << "Add 6 items to the bag: " << std::endl;
    for (int i = 0; i < 6; i++)
    {
        bagPtr->add(items[i]);
    }  // end for

    displayBag(bagPtr);

    std::cout << "isEmpty: returns " << bagPtr->isEmpty() 
        << "; should be 0 (false)" << std::endl;

    std::cout << "getCurrentSize: returns " << bagPtr->getCurrentSize() 
        << "; should be 6" << std::endl;

    std::cout << "Try to add another entry: add(\"extra\") returns " 
        << bagPtr->add("extra") << std::endl;      

    std::cout << "contains(\"three\"): returns " << bagPtr->contains("three")
        << "; should be 1 (true)" << std::endl;
    std::cout << "contains(\"ten\"): returns " << bagPtr->contains("ten")
        << "; should be 0 (false)" << std::endl;
    std::cout << "getFrequencyOf(\"one\"): returns "
        << bagPtr->getFrequencyOf("one") << " should be 2" << std::endl;
    std::cout << "remove(\"one\"): returns " << bagPtr->remove("one")
        << "; should be 1 (true)" << std::endl;
    std::cout << "getFrequencyOf(\"one\"): returns "
        << bagPtr->getFrequencyOf("one") << " should be 1" << std::endl;
    std::cout << "remove(\"one\"): returns " << bagPtr->remove("one")
        << "; should be 1 (true)" << std::endl;
    std::cout << "remove(\"one\"): returns " << bagPtr->remove("one")
        << "; should be 0 (false)" << std::endl;
    std::cout << std::endl;

    displayBag(bagPtr);

    std::cout << "After clearing the bag, ";
    bagPtr->clear();

    std::cout << "isEmpty: returns " << bagPtr->isEmpty()
        << "; should be 1 (true)" << std::endl;
} // end bagTester

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " ARRAY | LINKED | ARRAY_LINKED" << std::endl;
        return -1;
    }
    BagInterface<std::string>* bagPtr = NULL;
    std::string choice(argv[1]);
    if (choice == "ARRAY") {
        bagPtr = new ArrayBag<std::string>();
    }
    else if (choice == "LINKED") {
        bagPtr = new LinkedBag<std::string>();
    }
    else if (choice == "ARRAY_LINKED") {
      bagPtr = new ArrayLinkedBag<std::string>();
    }
    else {
        std::cout << "Invalid option" << std::endl;
        return 0;
    }

    std::cout << "The initial bag is empty." << std::endl;
    bagTester(bagPtr);
    delete bagPtr;
    bagPtr = NULL;
    std::cout << "All done!" << std::endl;

    return 0;
}
