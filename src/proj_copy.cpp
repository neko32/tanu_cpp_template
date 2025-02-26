#include <iostream>
#include <filesystem>
#include <vector>
#include <sstream>

#include "proj_copy/proj_copy.h"

using namespace std;

namespace tanu::util {

    void ProjectCopy::perform_copy() const {
        cout << "copying project template to " << this->m_dest_dir << "..." << endl;
        vector<string> v;
        filesystem::path cur_path = filesystem::path {this->m_src_dir};
        traverse(cur_path, v);
        cout << "done." << endl;
    }

    bool ProjectCopy::should_skip(string path) const {
        if(path == ".gitkeep") {
            return false;
        } else if(path[0] == '.') {
            return true;
        } else {
            return false;
        }
    }

    void ProjectCopy::traverse(filesystem::path& path, vector<string>& path_to_add) const {
        vector<filesystem::path> next;
        stringstream ss;

        for(string p:path_to_add) {
            ss << p << '/';
        }
        string infix_path = ss.str();
        if(infix_path.length() > 0) {
            infix_path.pop_back();
        }

        for(const auto& iter:filesystem::directory_iterator {path}) {
            if(filesystem::is_directory(iter)) {

                if(should_skip(iter.path().filename().string())) continue;
                    
                filesystem::path dest_path {filesystem::path(this->m_dest_dir)};
                if(path_to_add.size() == 0) {
                    dest_path = dest_path / iter.path().filename();
                } else {
                    dest_path = dest_path / infix_path / iter.path().filename();
                } 
                if(!filesystem::exists(dest_path)) {
                    cout << "creating directory " << dest_path.string() << "..." << endl;
                    filesystem::create_directory(dest_path);
                }
                next.push_back(iter.path());
            } else {
                if(!should_skip(iter.path().filename().string())) {

                    filesystem::path dest_path {filesystem::path(this->m_dest_dir)};
                    if(path_to_add.size() == 0) {
                        dest_path = dest_path / iter.path().filename();
                    } else {
                        dest_path = dest_path / infix_path / iter.path().filename();
                    } 
                    if(!filesystem::exists(dest_path)) {
                        cout << "creating file " << dest_path.string() << "..." << endl;
                        filesystem::copy_file(iter.path(), dest_path);
                    }
                }
            }
            for(auto next_d:next) {
                //cout << "moving into " << next_d.filename() << "..." << endl;
                path_to_add.push_back(next_d.filename().string());
                traverse(next_d, path_to_add);
                path_to_add.pop_back();
                //cout << "stepped out from " << next_d.filename() << "." << endl;
            }
        }
    }
}