#include "myneko/myneko.h"
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    MyNeko n {3, "Shimachan"};
    MyNeko m {18, "Torachan"};
    cout << n.name() << "(" << n.name_as_b64() << ")" << endl;
}