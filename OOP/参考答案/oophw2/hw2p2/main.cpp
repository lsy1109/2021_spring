#include <iostream>
//#include <stdio.h>
#include <string>
using namespace std;
char c;

string input_word() {
    string arg = "";
    c = getchar();
    while (c == ' ' || c == '"') {
        c = getchar();
    }
    while (c != ' ' && c != '\n' && c != '"') {
        arg += c;
        c = getchar();
    }// while (c != ' ' || c != '\n');
    return arg;
}

int main() {
    while (true) {
        string input[1000];
        int len = 0;
        cout << "$ echo ";
        string arg = input_word();
        bool supp_nl = false, inter_bl = false, supp_bl = false;
        bool has_arg = (arg[0] == '-' && (arg[1] == 'n' || arg[1] == 'e' || arg[1] == 'E'));
        if (has_arg) {
            for (int i = 1; i < arg.size(); i++) {
                if (arg[i] == 'n') supp_nl = true;
                if (arg[i] == 'e') inter_bl = true;
                if (arg[i] == 'E') supp_bl = true;
            }
        }
        else {
            input[len++] = arg;
        }
        while (c != '\n') {
            string inp = input_word();
            if (inp == "") break;
            input[len++] = inp;
        }
        for (int i = 0; i < len - 1; i++) {
            cout << input[i] << " ";
        }
        cout << input[len - 1];
        if (!supp_nl) cout << endl;
        //cout << input[0] << input[1] << endl;
    }
    return 0;
}