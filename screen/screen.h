#include <string>
#include <iostream>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <cassert>
#include <fstream>
using namespace std;
#ifndef SCREEN_H
#define SCREEN_H

extern bool debug;
extern ofstream debug_file;

class screen {
public:
bool load(string input_file); // to load screen settings from a file
bool render();
bool set_border(vector<char> chars);
string input;

private:
vector<char> border = {'+', '+', '+', '+', '|', '-', '+', '+', '+', '+', '>'};


};

#endif


bool screen::set_border(vector<char> chars){

        if(chars.size() != 11) {
                debug_file << "screen.h - set_border - ERROR in setting border - input vector len not 11";
                return false;
        }
        border = chars;
        return true;

}

bool screen::render(){
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        int window_width = w.ws_col; int window_height = w.ws_row;

        cout << border[1];
        for (int i = 0; i < window_width-2; i++) { cout << border[5]; }
        cout << border[0];

        for (int j = 0; j < window_height-4; j++) {
                cout << border[4];
                for (int i = 0; i < window_width-2; i++) { cout << " "; }
                cout << border[4];
        }
        cout << border[6];

        for (int i = 0; i < window_width-2; i++) { cout << border[5]; }
        cout << border[7]; cout << border[4];

        for (int i = 0; i < window_width-2; i++) { cout << " "; }
        cout << border[4]; cout << border[2];

        for (int i = 0; i < window_width-2; i++) { cout << border[5]; }
        cout << border[2];

        cout << "\33[1A"; cout << "\33[" << window_width - 2 << "D"; // up one line and then over all - 2

        cout << "> ";
        cin >> input;
        for (int i = 0; i < window_height-1; i++) { cout << "\33[2K\33[A"; } // cursor starts on bottom line and goes up top of o screen size

        for (int i = 0; i < window_height - w.ws_row; i++) {
                cout << "\33M\33[A\33[2K";
        }
        return true;
}