#ifndef CONTESTANT_H
#define CONTESTANT_H
#include <string>
#include <iostream>
using namespace std;


class Contestant{

    private:
        int id;
        int point;

    public:
        Contestant();
        Contestant(int idnumber, int score);
        int getId();
        int getPoint();
        void setId(int idnumber);
        void setPoint(int score);
        void print();
};



#endif