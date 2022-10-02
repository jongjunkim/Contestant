#include "Minheap.h"
#include <iostream>
using namespace std;


    //Insert Contestant to Extended heap and print if there is no room to insert Contestant
   void Minheap::insertContestant(Contestant person){

        if(num != list_size){
            list[num] = Contestant(person.getId(), person.getPoint());
            num++;
        }else{
            cout << "Conestant <" << person.getId() << "> " << "could not be inserted because the extended heap is full" << endl;  
        }
    }


  //Min Heapify if current node(parent node) is larger than its left and right child swap
  //recursvely call to swap with its childeren if parent node is larger
  void Minheap::min_heap(Contestant *array, int current, int size){

    int  parent = 0, left = 0, right = 0, small = 0, left_point = 0, right_point = 0, change = 0;
            
        left = current * 2 ;
        right = current * 2 + 1;
        parent = array[current].getPoint();
        small = parent;
        left_point = array[left].getPoint();
        right_point = array[right].getPoint();
        
        if(left < list_size && left_point < parent){
            small = left_point;
            change = left;
        }
            
        if(right < list_size && right_point < left_point){
            small = right_point;
            change = right;
        }

        if(small < parent){
            swap(array[current], array[change]);
            min_heap(array, change, size);
        }
    }

    //build min heap calling min_heap function. For loops starts from size/2 to begin with leaf node.
    void Minheap::build_minheap(){
        for(int i = (list_size-1)/2; i > 0; i--){
            min_heap(list,i,list_size-1);
        }
    }

    //print the contents of the extended heap 
    void Minheap::showContestant(){
        for(int i = 1; i<list_size; i++){
            cout << "Contestant <" << list[i].getId() << "> " << "in extended heap location <" << i << "> " 
            << "with score <" << list[i].getPoint() << ">" << endl;
        }
    }

