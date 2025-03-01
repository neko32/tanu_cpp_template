#pragma once
#ifndef __MYNEKO_H__
#define __MYNEKO_H__

#include <string>
#include <vector>

using namespace std;

namespace tanu::sample {

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
        string to_str();
    };

    vector<MyNeko> load_from_csv(const string& csv_fpath);

}

#endif
