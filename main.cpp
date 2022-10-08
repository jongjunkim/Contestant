#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cctype>
#include <unistd.h>
#include "Contestant.h"
#include "Minheap.h"
using namespace std;


//read textfile and insert Contestant to Extendedheap
void readfile(string inputfile, ofstream &outputfile, Minheap &list){


    ifstream in(inputfile);
    string str, command, id, score;
    int pos1, pos2, pos3, pos4, idnumber, num_score, size;
    
    int count = 0; //if command are used for other operation other than insertion increment 1 so that we can buildheap after new Contesant is entered 

    //read inputFile and run program based on command
    while(getline(in,str)){
        stringstream ss(str);

        ss >> command;

        if(command == "insertContestant"){
            ss >> id >> score;
            outputfile << command << " " << id << " " << score << endl;
            pos1 = id.find("<");
            pos2 = id.find(">");

            idnumber = stoi(id.substr(pos1+1, pos2-1));

            pos3 = score.find("<");
            pos4 = score.find(">");

            num_score = stoi(score.substr(pos3+1, pos4-1));

            list.insertContestant(Contestant(idnumber,num_score), outputfile);
        }else if(command == "showContestants"){
            outputfile << command << endl;
            list.showContestant(outputfile);
        }else if(command == "findContestant"){
            ss >> id;
            outputfile << command << id << endl;
            idnumber = stoi(id.substr(pos1+1, pos2-1));
            list.findConetestant(idnumber, outputfile);
        }else if(command == "eliminateWeakest"){
            outputfile << command << endl;
            list.eliminateWeakest(outputfile);
        }else if(command  == "earnPoints"){
            ss >> id >> score;
            outputfile << command << " "<< id  << " " << score << endl;
            pos1 = id.find("<");
            pos2 = id.find(">");

            idnumber = stoi(id.substr(pos1+1, pos2-1));

            pos3 = score.find("<");
            pos4 = score.find(">");

            num_score = stoi(score.substr(pos3+1, pos4-1));

            list.earnPoints(idnumber, num_score, outputfile);
        }else if(command == "losePoints"){
            ss >> id >> score;
            outputfile << command << " "<< id  << " " << score << endl;
            pos1 = id.find("<");
            pos2 = id.find(">");

            idnumber = stoi(id.substr(pos1+1, pos2-1));

            pos3 = score.find("<");
            pos4 = score.find(">");

            num_score = stoi(score.substr(pos3+1, pos4-1));

            list.losePoints(idnumber, num_score, outputfile);
        }else if(command == "showHandles"){
            outputfile << command << endl;
            list.showHandles(outputfile);
        }else if(command == "showLocation"){
            ss >> id;
            outputfile << command << id << endl;
            pos1 = id.find("<");
            pos2 = id.find(">");

            idnumber = stoi(id.substr(pos1+1, pos2-1));
            list.showLocation(idnumber, outputfile);
        }else if(command == "crownWinner"){
            outputfile << command << endl;
            list.crownWinner(outputfile);
        }
        else{
            list = Minheap(stoi(command));
            size = stoi(command);
        }
        
    }

}

int main(int argc, char* argv[]){

    int n = 0;
    Minheap extended(n);
    string input;
    string output;
    ofstream output_txt;
    output_txt.open("output.txt");

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

    readfile(input, output_txt, extended);

    


    return 0;
}   