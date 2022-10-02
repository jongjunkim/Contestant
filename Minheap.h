#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
#include <algorithm>
#include "Contestant.h"
using namespace std;


class Minheap{

    private:
        Contestant *list;
        int num = 1;
        int list_size = 0;

    public:
        //Initializtion array with given size
        Minheap(int size){
            list = new Contestant[size];
            list_size = size;
        }
        void min_heap(Contestant *array, int current, int size);
        void build_minheap();
        void insertContestant(Contestant people);
        void showContestant();
          



};

#endif