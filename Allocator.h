/* 
 * File:   Allocator.h
 * Author: wookie
 *
 * Created on September 26, 2015, 7:02 PM
 */

#ifndef ALLOCATOR_H
#define	ALLOCATOR_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>

struct Block {
    size_t size;
    unsigned int pointer;
    Block* next;
    //unsigned int left_size;
    
};

const int adress_space_size = 2000000;

class Allocator {
public:
    Allocator() {
        this->file.open("log", std::fstream::in);
        adress_space = std::vector<char>(adress_space_size);
        free.insert(std::pair<int, size_t>(0, adress_space_size));
    };
    Allocator(const Allocator& orig){};
    virtual ~Allocator(){
        this->file.close();
    };
    
    void* allocate(size_t required_size);
    void* realloc(void* pointer, size_t size);
    void freealloc(void* pointer);
    
    
    void print();
private:    
    std::ofstream file;
    size_t round_size(size_t);
    
    int VectorPass(int point);
    
    std::vector<char> adress_space;
    //std::vector<Block> busy;
    std::map<int, size_t> free;
    std::map<int, size_t> busy;
    //std::map<int, size_t> busy;
};

#endif	/* ALLOCATOR_H */

