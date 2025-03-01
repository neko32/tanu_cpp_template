#include "myneko/myneko.h"

#include "tobiaslocker/base64.hpp"
#include "fastcsv/csv.h"

#include <vector>
#include <sstream>

using namespace std;

namespace tanu::sample {

    string MyNeko::name_as_b64() {
        return base64::to_base64(m_name);
    }

    string MyNeko::to_str() {
        stringstream ss;    
        ss << "{";
        ss << "age:" << this->m_age << ",";
        ss << "name:" << this->m_name;
        ss << "}";
        return ss.str();
    }

    vector<MyNeko> load_from_csv(const string& csv_fname) {
        static const int NUM_COL = 2;
        io::CSVReader<NUM_COL> csv_reader(csv_fname);
        csv_reader.read_header(io::ignore_extra_column, "age", "name");
        vector<MyNeko> v;
        string name;
        int age;
        while(csv_reader.read_row(age, name)) {
            v.push_back(MyNeko {age, name});
        }
        return v;
    }

}

