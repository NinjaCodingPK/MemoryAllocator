/* 
 * File:   main.cpp
 * Author: wookie
 *
 * Created on September 25, 2015, 6:10 PM
 */

#include <cstdlib>
#include "Allocator.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Allocator alloc = Allocator();
    void *a = alloc.allocate(40);
    void *b = alloc.allocate(40);
    //alloc.freealloc(a);
    
    long c = a;
    
    std::cout << a << ' ' << c;
    
    alloc.print();
    
    return 0;
}

