#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
bool supp_nl = false, inter_bl = false, supp_bl = false;

string assess(string s) {
    if (!inter_bl) return s;
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '\\') {
            ans += s[i];
            continue;
        }
        if (s[i + 1] == 'a') ans += '\a';
        else if (s[i + 1] == 'b') ans += '\b';
        else if (s[i + 1] == 'c') {
            supp_nl = true;
            return ans;
        }
        else if (s[i + 1] == 'e' || s[i + 1] == 'E') ans += '\x1B';
        else if (s[i + 1] == 'f') ans += '\f';
        else if (s[i + 1] == 'n') ans += '\n';
        else if (s[i + 1] == 'r') ans += '\r';
        else if (s[i + 1] == 't') ans += '\t';
        else if (s[i + 1] == 'v') ans += '\v';
        else {
            ans += '\\';
            ans += s[i + 1];
        }
        ++i;
    }
    return ans;
}

int main(int argc,char **argv) {
    string arg = argv[1];
    bool has_arg = (arg[0] == '-' && (arg[1] == 'n' || arg[1] == 'e' || arg[1] == 'E'));
    int start = 1;
    if (has_arg) {
        for (int i = 1; i < arg.size(); i++) {
            if (arg[i] == 'n') supp_nl = true;
            if (arg[i] == 'e') inter_bl = true;
            if (arg[i] == 'E') supp_bl = true;
        }
        start = 2;
    }
    for (int i = start; i < argc - 1; i++) {
        cout << assess(argv[i]) << " ";
    }
    cout << assess(argv[argc - 1]);
    if (!supp_nl) cout << endl;
    return 0;
}