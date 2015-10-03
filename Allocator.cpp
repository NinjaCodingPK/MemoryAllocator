/* 
 * File:   Allocator.cpp
 * Author: wookie
 * 
 * Created on September 26, 2015, 7:02 PM
 */

#include <map>

#include "Allocator.h"

int Allocator::VectorPass(int point){
//    for(Block i = busy.begin(); i < busy.back(); i++)
//        if(i.pointer = point)
//            return i.size;
    return 0;                
}

size_t Allocator::round_size(size_t size) {
    size_t sizeRounded = size;
    if (size % 4){
        sizeRounded += 4 - size % 4;
    }
    return sizeRounded;
}

void* Allocator::allocate(size_t required_size)
{   
    //int temp_adress;
    Block temp;
    unsigned int point = 0;
    size_t size = 0;
    
    if(!busy.empty())
    {
        /*auto iterator = free.begin();
        temp.pointer = iterator->first;
        
        if(iterator->second < required_size) {
            iterator++;
            for(iterator; iterator != free.end(); iterator++) {
                if(iterator->second >= required_size) {
                    temp.pointer = iterator->first;
                }
            }
        }*/
        
        for(auto iterator = free.begin(); iterator != free.end(); iterator++) {
            if(iterator->second >= required_size) {
                temp.pointer = iterator->first;
                break;
            }
        }       
        
    }
    else {
        //temp_adress = 0;
        temp.pointer = 0;
    }
    temp.size = required_size;
    temp.next = NULL;
        
    //busy.push_back(temp);
    busy.insert(std::pair<int, size_t>(temp.pointer, required_size));
    
    //this->print();
    
    free.insert(std::pair<int, size_t>(temp.pointer + temp.size, free[temp.pointer] - temp.size));
    free.erase(temp.pointer);
    //busy.insert(std::pair<int, size_t>(temp_adress, size);
    
    int ret = temp.pointer;
    return &ret;
}

void Allocator::freealloc(void* pointer) 
{
    //file << busy;
    
    free.insert(std::pair<int, size_t>(*((int*)(&pointer)), busy[*((int*)(&pointer))]));
    busy.erase(*((int*)(&pointer)));
    //this->print();
}

void* Allocator::realloc(void* pointer, size_t size)
{
    //std::cout << this->busy[0];
}

void Allocator::print() 
{      
    for(auto iterator = free.begin(); iterator != free.end(); iterator++) {
        file << iterator->first << ' ' << iterator->second << std::endl;
    }
    
    //std::cout<< '\n' << free[40];
}