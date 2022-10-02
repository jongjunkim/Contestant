#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include "Contestant.h"
#include "Minheap.h"
using namespace std;


//read textfile and insert Contestant to Extendedheap
void readfile(string inputfile, Minheap &list){


    ifstream in(inputfile);
    string str, command, id, score;
    int pos1, pos2, pos3, pos4, idnumber, num_score, size;


    //read inputFile and run program based on command
    while(getline(in,str)){
        stringstream ss(str);

        ss >> command;

        if(command == "insertContestant"){
            ss >> id >> score;
            pos1 = id.find("<");
            pos2 = id.find(">");

            idnumber = stoi(id.substr(pos1+1, pos2-1));

            pos3 = score.find("<");
            pos4 = score.find(">");

            num_score = stoi(score.substr(pos3+1, pos4-1));

            list.insertContestant(Contestant(idnumber,num_score));
        }else{
            list = Minheap(stoi(command));
            size = stoi(command);
        }
        
    }

    list.build_minheap();
}

int main(int argc, char* argv[]){

    int n = 0;
    Minheap extended(n);
    string input;
    string output;

    int o;
    const char *optstring = "m:p:";
    
    while((o = getopt(argc,argv,optstring)) != -1){
        switch(o){
            case 'm':
                input = argv[2];
                break;
            
            case 'p' :
                output = argv[4];
                break;
            
            case '?':
                printf("error optopt: %c\n", optopt);
                printf("error opterr: %c\n", opterr);
                break;
        }
    }

    readfile(input, extended);
    extended.showContestant();

    


    return 0;
}   