/*
 * compile this using the following command: g++ main.cpp <path to streams.h> <path to stream.a> -o calc
 */
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include "../../streamlib/streams.h" //https://github.com/phyrrus9/streamlib change the path correctly
using namespace std;
int opcode(char);
int main(int argc, const char * argv[])
{
    if (!check_version_compadible()) //program compiled wrong
    {
        if (streamlib_version < GLOBAL_STREAMLIB_VERSION)
            printf("Error! Wrong header version: %i should be %i\n", streamlib_version, GLOBAL_STREAMLIB_VERSION);
        else
            printf("Error! Wrong streamlib version: %i should be %i\n", GLOBAL_STREAMLIB_VERSION, streamlib_version);
        exit(-1);
    }
    char * input_unparse = new char[100];
    cout << ">";
    cin.getline(input_unparse, 99, '\n');
    char * first = new char[strlen(input_unparse) + 5];
    strcpy(first, input_unparse);
    delete input_unparse;
    ostringstream s1, s2;
    int op, optype;
    for (int i = 0; !opcode(first[i]); i++)
    {
        s1 << first[i];
        op = i+1;
    }
    optype = opcode(first[op]);
    for (int i = op + 1; i < strlen(first); i++)
        s2 << first[i];
    float f1 = atof(s1.str().c_str()), f2 = atof(s2.str().c_str()), fresult;
    switch (optype)
    {
        case 1: //adding
            fresult = f1 + f2;
            break;
        case 2: //subtracting
            fresult = f1 - f2;
            break;
        case 3: //divide
            fresult = f1 / f2;
            break;
        case 4: //multiply
            fresult = f1 * f2;
            break;
        default:
            exit(-1);
    }
    //printf("%s %c %s\n", s1.str().c_str(), first[op], s2.str().c_str());
    cout << fresult << endl;
}
int opcode(char c)
{
    if (c == '+')
        return 1;
    if (c == '-')
        return 2;
    if (c == '/')
        return 3;
    if (c == '*')
        return 4;
    return 0;
}
