#include "tobiaslocker/base64.hpp"

using namespace std;

class MyNeko {
private:
    int m_age;
    string m_name;
public:
    MyNeko(int age, string name):m_age(age), m_name(name){}
    int age() const { return m_age;};
    const string name() const {return m_name;}
    const string hello() const { return "meow!";}
    string name_as_b64();
};

inline string MyNeko::name_as_b64() {
    return base64::to_base64(m_name);
}
