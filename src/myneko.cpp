#include "myneko/myneko.h"

#include "tobiaslocker/base64.hpp"

using namespace std;

string MyNeko::name_as_b64() {
    return base64::to_base64(m_name);
}

