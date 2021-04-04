#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include "skip_list.h"
#include "linked_list.h"

int main() {
    srand((unsigned)time(nullptr));

    SkipList lst(3, 0.5);

    lst.insertElement(3);
    lst.insertElement(6);
    lst.insertElement(7);
    lst.insertElement(9);
    lst.insertElement(12);
    lst.insertElement(19);
    lst.insertElement(17);
    lst.insertElement(26);
    lst.insertElement(21);
    lst.insertElement(25);
    lst.displayList();

    //Search for node 19
    lst.searchElement(19);

    //Delete node 19
    lst.deleteElement(19);
    lst.displayList();



    SkipList s_list(5, 0.5);

    for(int i = 1; i <= 50000; i++){
        s_list.insertElement(i);
    }

    auto start = std::chrono::high_resolution_clock::now();
    //Search for all values in list one at a time
    for(int i =  1; i <=50000; i++){
        s_list.searchElement(i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    double search_time_list = diff.count(); //Time to search with skip list
    std::cout << "Skip List time to search: " << search_time_list << " seconds" << std::endl;

    List ll;

    for(int i = 1; i <= 50000; i++){
        ll.insert(i);
    }

    start = std::chrono::high_resolution_clock::now();
    //Search for all values in list one at a time
    for(int i =  1; i <=50000; i++){
        ll.find(i);
    }
    end = std::chrono::high_resolution_clock::now();
    diff = end-start;
    search_time_list = diff.count(); //Time to search with linked list
    std::cout << "Linked List time to search: " << search_time_list << " seconds" << std::endl;

    return 0;
}
