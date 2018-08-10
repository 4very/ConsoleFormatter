
#include <iostream>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <fstream>
//#include "screen/screen.h"
using namespace std;
#define size_t unsigned int;

bool debug = true;
ofstream debug_file;

int main(int argc, char const *argv[]) {

        if (debug) { debug_file.open("\\deubg\\debug.txt"); }

        // try{ assert(0); }
        // catch(int e) { assert(1); }


        screen defualt;
        while (defualt.input != "q") {
                defualt.render();
        }
        cout << "\33[2K\33[A"; // this is here to clear a resudial blank line

}
