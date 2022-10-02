#include "Contestant.h"
#include <iostream>
using namespace std;


        Contestant::Contestant(){
            id = 0;
            point= 0;
        }
        Contestant::Contestant(int idnumber, int score){
            id = idnumber;
            point = score;
        }
        int Contestant::getId(){
            return id;
        }

        int Contestant::getPoint(){
            return point;
        }

        void Contestant::setId(int idnumber){
            id = idnumber;
        }

        void Contestant::setPoint(int score){
            point = score;
        }

        void Contestant::print(){
            cout << "Contestant Id: " << id << " Point: " << point << endl;
        }