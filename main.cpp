#include <iostream>

using namespace std;

const int __LINE_LENGTH = 20;

int** __LINE_ADDRESS = new int* [2];

class WorkLine{
public:
    WorkLine(int length){
        this->length = length;
        line = __LINE_ADDRESS;
        for(int i = 0; i < 2; i++){
            line[i] = new int [length];
        }
    }

    int GetLength(){
        return length;
    }

    int** GetLine(){
        return line;
    }

    ~WorkLine(){
        delete [] line;
    }
private:
    int **line;
    int length;

};

class TuringMashine{
public:
    TuringMashine(){
        position = __LINE_LENGTH/2;
    }
    int GetPosition(){
        return position;
    }
    int Move(int new_position){
        position = new_position;
        return 0;
    }
    int Write(int value){
        __LINE_ADDRESS[0][position] = value;
        return 0;
    }
private:
    int position;
};


void PrintBoard(WorkLine& line, TuringMashine& mashine){
    //system("clear");

    cout << endl << endl << "\t";

    for(int i = 0; i < line.GetLength(); i++){
        cout << (line.GetLine()[0][i] == -1 ? "|" : "| ")  << line.GetLine()[0][i];
    }

    cout << "|" << endl << "\t";

    for(int i = 0; i < line.GetLength(); i++){
        cout << (i != mashine.GetPosition() ? "|_" : "|")
             << (i == mashine.GetPosition() ? "^^" : "_");
    }

    cout << "|" << endl << endl << endl;
}

int main()
{
    WorkLine line(__LINE_LENGTH);
    TuringMashine mashine;

    PrintBoard(line, mashine);

    mashine.Move(5);
    mashine.Write(1);


   PrintBoard(line,mashine);
    return 0;
}
