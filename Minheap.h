#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
#include <algorithm>
#include "Contestant.h"
using namespace std;


class Minheap{

    private:
        Contestant *list;
        int *extend;
        int num = 1;
        int list_size = 0;

    public:
        //Initializtion array with given size
        Minheap(int size){
            list = new Contestant[size];
            list_size = size;

            extend = new int[size];
            for(int i = 1; i<=size; i++){
                extend[i] = -1;
            }
        }
        void heapDownward(int current);
        void heapUpward(int leaf);
        void insertContestant(Contestant people);
        void showContestant();
        void findConetestant(int id);
        void eliminateWeakest();
        void earnPoints(int id, int point);
        void losePoints(int id, int point);
        Contestant &getContestant(int id);
        void showHandles();
        void showLocation(int id);
        void crownWinner();
        bool checkId(int id);
          



};

#endif