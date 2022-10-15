#include "Minheap.h"
#include <iostream>
using namespace std;


    //find contestant with given ID
   void Minheap::findConetestant(int id, ofstream &result){

        int number = extend[id];
        if(number > 0){
            result << "Contestant <" << id << "> is in the extended heap with score <" 
            << list[number].getPoint() << ">." << endl;
    
        }else{
            result << "Contestant <" << id << "> is not in the extended heap" << endl;
        }
        

   }


    //Insert Contestant to Extended heap and print if there is no room to insert Contestant
   void Minheap::insertContestant(Contestant person, ofstream &result){

        if(num != list_size ){
            list[num] = Contestant(person.getId(), person.getPoint());
            result << "Conestant <" << person.getId() << "> inserted with initial score <" << person.getPoint() << ">" << endl;
            extend[extend_num] = num;
            num++;
            extend_num++;
            heapUpward(num-1);
        }else{
            result << "Conestant <" << person.getId() << "> " << "could not be inserted because the extended heap is full" << endl;  
        }
    }


    //As inserting a new contestant, compare with it parent and if the new contestant is smaller, then swap. 
    void Minheap::heapUpward(int leaf){
        
        int parent = leaf/2;

        if(list[parent].getPoint() > list[leaf].getPoint()){

            extend[list[leaf].getId()] = parent;
            extend[list[parent].getId()] = leaf;
            swap(list[parent], list[leaf]);
            heapUpward(parent);
        }

    }


  //Min Heapify if current node(parent node) is larger than its left and right child swap
  //recursvely call to swap with its childeren if parent node is larger
  void Minheap::heapDownward(int current){

    
    int  parent, left, right, small, left_point, right_point, change;
            
        left = current * 2 ;
        right = current * 2 + 1;
        parent = list[current].getPoint();
        small = parent;
        left_point = list[left].getPoint();
        right_point = list[right].getPoint();
        
        if(left < num && left_point < parent){
            small = left_point;
            change = left;
        }
            
        if(right < num && right_point < left_point){
            small = right_point;
            change = right;
        }

        if(small != parent && list[change].getId() > 0){
            extend[list[change].getId()] = current;
            extend[list[current].getId()] = change;
            swap(list[current], list[change]);
            heapDownward(change);
        }
    }

    //To revmoe the root node, swap it with the last element of the array and remove
    void Minheap::eliminateWeakest(ofstream &result){

        if(num > 1){
            result << "Contestant <" << list[1].getId() << "> with current lowest score <" 
            << list[1].getPoint() << "> eliminated" <<endl;
            
            extend[list[1].getId()] = -1;
            swap(list[1], list[num-1]);
            list[num-1] = Contestant(0,0);
            num--;
            heapDownward(1);
        }


    }


    //Another find function to get Contestant with given Id and return with address
    Contestant& Minheap::getContestant(int id){

        int number = extend[id];
        if(number > 0){
            return list[number];
        }

        return list[0];
    }


    //Add point if Contestant is found, if not print Contestant is not in extended heap
    //since point is added, heapify down
    void Minheap::earnPoints(int id, int point, ofstream &result){
        
        int whatId = getContestant(id).getId();
        if(whatId != 0){
            int score = getContestant(id).getPoint();
            getContestant(id).setPoint(score + point);
            heapDownward(extend[id]);
            result << "Contestant <" << id << ">'s score increased by <" << point << "> points to <" << score+point << ">" << endl;
        }else{
            result << "Contestant <" << id << "> is not in the extended heap" << endl;
        }
    }

    //deduct point if Contest is found, if not print Contestant is not in extended heap
    //since point is decreased, heapify up
    void Minheap::losePoints(int id, int point, ofstream &result){
        
        int whatId = getContestant(id).getId();
        if(whatId != 0){
            int score = getContestant(id).getPoint();
            getContestant(id).setPoint(score - point);
            heapUpward(extend[id]);
            result << "Contestant <" << id << ">'s score decreased by <" << point << "> points to <" << score-point << ">" << endl;
        }else{
            result << "Contestant <" << id << "> is not in the extended heap" << endl;
        }
    }

    //print the contents of the extended heap 
    void Minheap::showContestant(ofstream &result){
        for(int i = 1; i<list_size; i++){
            if(list[i].getId() > 0){
                result << "Contestant <" << list[i].getId() << "> " << "in extended heap location <" << extend[list[i].getId()] << "> " 
                << "with score <" << list[i].getPoint() << ">" << endl;
            }
        }
    }

    //print the contents of the handle array inorder
    void Minheap::showHandles(ofstream &result){
        for(int i = 1; i<= list_size; i++){
            if(extend[i] > 0){
                result << "Contestant <" << i << "> stored in extended heap location <" << extend[i] << ">" << endl;
            }else{
                result << "There is no Contestnat <" << i << "> in the extended heap: handle[<" << i << ">] = " << extend[i] <<endl;
            }
        }
    }

    //show the location of the contestant with id <k> in the heap, as follows
    void Minheap::showLocation(int id, ofstream &result){

        if(extend[list[id].getId()] > 0){
            result << "Contestant <" << id << "> stored in extended heap location <" << extend[id] << ">" << endl;      
        }else{
            result << "There is no Contestnat <" << id << "> in the extended heap: handle[<" << id << ">] = " << extend[id] <<endl; 
        }

    }

    //Remove all contestants from the extended heap, in order, until only one remains
    //print the winner, which is the last remaning node
    void Minheap::crownWinner(ofstream &result){
        
        while(num > 2){
            elimnateall();
        }

        result << "Contestant <" << list[1].getId() << "> wins with score <" << list[1].getPoint() << ">!" <<endl;

    }

    //remove all the elements in the heap except the Contestant with largest point
    void Minheap::elimnateall(){

        if(num > 1){
            
            extend[list[1].getId()] = -1;
            swap(list[1], list[num-1]);
            list[num-1] = Contestant(0,0);
            num--;
            heapDownward(1);
        }
     }
    