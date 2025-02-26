#include "myneko/myneko.h"
#include "proj_copy/proj_copy.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;


int main(int argc, char** argv) {
    /*
    MyNeko n {3, "Shimachan"};
    MyNeko m {18, "Torachan"};
    cout << n.name() << "(" << n.name_as_b64() << ")" << endl;
    */
    if(argc < 2 || argc > 3) {
        cerr << "main [dest_path] [optional:src_path]" << endl;
        exit(1);
    }
    string dest = string {argv[1]};
    if(argc == 2) {
        const tanu::util::ProjectCopy cp(dest);
        cout << cp.src_dir() << " to " << cp.dest_dir() << endl;
        cp.perform_copy();
    } else {
        string src = string {argv[2]};
        const tanu::util::ProjectCopy cp(dest, src);
        cout << cp.src_dir() << " to " << cp.dest_dir() << endl;
        cp.perform_copy();
    }

}