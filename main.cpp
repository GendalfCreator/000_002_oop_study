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
        memory = 0;
    }
    int GetPosition(){
        return position;
    }
    int GetMemory(){
        return memory;
    }
    void SetMemory(int value){
        memory = value;
    }
    int Move(int new_position){
        position = new_position;
        return 0;
    }
    int Set(){
        if(__LINE_ADDRESS[0][position] == 1 && memory == 1){
            __LINE_ADDRESS[0][position] = 0;
            Move(position - 1);
            Set();
        }
        else if(__LINE_ADDRESS[0][position] == 0){
            __LINE_ADDRESS[0][position] = memory;
        }
        else if(__LINE_ADDRESS[0][position] == 1 && memory == 0){
            return 0;
        }
        return 0;
    }

    void Execution(string program, int value){
        if(program == "mov"){
            Move(value);
        }
        else if(program == "set"){
            SetMemory(value);
            Set();
        }
        else if(program == "get"){
            Move(value);
            SetMemory(__LINE_ADDRESS[0][position]);
        }
    }
private:
    int position;
    int memory;
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

    cout << "|" << endl << "\t";

    for(int i = 0; i < line.GetLength(); i++){
        if(i != mashine.GetPosition()){
            cout << "   ";
        }
        else if(i == mashine.GetPosition()){
            cout << "[ ";
            cout << mashine.GetMemory();
            cout << "]";
        }
    }
    cout << endl;

    cout << "\tПервый операнд = ";
    for(int i = 0; i < 4; i++){
        cout << __LINE_ADDRESS[0][i];
    }
    cout << endl;

    cout << "\tВторой операнд = ";
    for(int i = 4; i < 8; i++){
        cout << __LINE_ADDRESS[0][i];
    }
    cout << endl;

    cout << "\tТретий операнд = ";
    for(int i = 8; i < 12; i++){
        cout << __LINE_ADDRESS[0][i];
    }
    cout << endl;


    cout << endl << endl << endl;
}

int main()
{
    WorkLine line(__LINE_LENGTH);
    TuringMashine mashine;

    PrintBoard(line, mashine);

    //Внесение на ленту первой переменной (0011)
    mashine.Execution("mov", 3);
    mashine.Execution("set", 1);
    mashine.Execution("mov", 2);
    mashine.Execution("set", 1);
    mashine.Execution("mov", 1);
    mashine.Execution("set", 0);
    mashine.Execution("mov", 0);
    mashine.Execution("set", 0);
    PrintBoard(line, mashine);

    //Внесение на ленту второй переменной (0011)
    mashine.Execution("mov", 7);
    mashine.Execution("set", 1);
    mashine.Execution("mov", 6);
    mashine.Execution("set", 1);
    mashine.Execution("mov", 5);
    mashine.Execution("set", 0);
    mashine.Execution("mov", 4);
    mashine.Execution("set", 0);
    PrintBoard(line, mashine);

    //Копирование первой переменной в третью (результирующую)
    mashine.Execution("get", 3);
    mashine.Execution("mov", 11);
    mashine.Execution("set", mashine.GetMemory());
    mashine.Execution("get", 2);
    mashine.Execution("mov", 10);
    mashine.Execution("set", mashine.GetMemory());
    mashine.Execution("get", 1);
    mashine.Execution("mov", 9);
    mashine.Execution("set", mashine.GetMemory());
    mashine.Execution("get", 0);
    mashine.Execution("mov", 8);
    mashine.Execution("set", mashine.GetMemory());
    PrintBoard(line, mashine);

    //Сложение первого бита третьей переменной и первого бита второй переменной
    mashine.Execution("get",7);
    mashine.Execution("mov",11);
    mashine.Execution("set", mashine.GetMemory());
    PrintBoard(line, mashine);

    //Сложение второго бита третьей переменной и второго бита второй переменной
    mashine.Execution("get",6);
    mashine.Execution("mov",10);
    mashine.Execution("set", mashine.GetMemory());
    PrintBoard(line, mashine);

    //Сложение третьего бита третьей переменной и третьего бита второй переменной
    mashine.Execution("get",5);
    mashine.Execution("mov",9);
    mashine.Execution("set", mashine.GetMemory());
    PrintBoard(line, mashine);

    //Сложение четвёртого бита третьей переменной и четвёртого бита второй переменной
    mashine.Execution("get",4);
    mashine.Execution("mov",8);
    mashine.Execution("set", mashine.GetMemory());
    PrintBoard(line, mashine);



    return 0;
}
