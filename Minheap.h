#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
#include <algorithm>
#include <fstream>
#include "Contestant.h"
using namespace std;


class Minheap{

    private:
        Contestant *list;
        int *extend;
        int num = 1;
        int list_size = 0;
        //ofstream output;

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
        void insertContestant(Contestant people, ofstream &result);
        void showContestant(ofstream &result);
        void findConetestant(int id, ofstream &result);
        void eliminateWeakest(ofstream &result);
        void earnPoints(int id, int point, ofstream &result);
        void losePoints(int id, int point, ofstream &result);
        Contestant &getContestant(int id);
        void showHandles(ofstream &result);
        void showLocation(int id, ofstream &result);
        void crownWinner(ofstream &result);
        void elimnateall();
        bool checkId(int id);
          



};

#endif