#include <iostream>
#include <algorithm>
#include "myneko.h"

using namespace std;


int main() {
    MyNeko n {3, "Shimachan"};
    cout << n.name() << "(" << n.name_as_b64() << ")" << endl;
}