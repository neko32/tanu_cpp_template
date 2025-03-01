#include "myneko/myneko.h"
#include "proj_copy/proj_copy.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <filesystem>

using namespace std;
using namespace tanu::sample;

#define RUN_MYNEKO_SIMPLE
#define RUN_CSV_SAMPLE
// #define ENABLE_PROJ_COPY


int main(int argc, char** argv) {

#ifdef RUN_MYNEKO_SIMPLE
    MyNeko n {3, "Shimachan"};
    MyNeko m {18, "Torachan"};
    cout << n.name() << "(" << n.name_as_b64() << ")" << endl;
#endif

#ifdef RUN_CSV_SAMPLE
    const string fpath = (filesystem::current_path() / "data" / "csv" / "myneko.csv").string();
    vector<MyNeko> cats = load_from_csv(fpath);
    
    for(MyNeko neko:cats) {
        cout << neko.to_str() << endl;
    }
#endif

#ifdef ENABLE_PROJ_COPY
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
#endif

}