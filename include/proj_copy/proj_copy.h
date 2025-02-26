#pragma once
#ifndef __PROJ_COPY_H__
#define __PROJ_COPY_H__

#include <string>
#include <filesystem>
#include <vector>

using namespace std;

namespace tanu::util {

    class ProjectCopy {
    private:
        string m_dest_dir;
        string m_src_dir;
        void traverse(filesystem::path& path, vector<string>& path_to_add) const;
        bool should_skip(string path) const;
    public:
        ProjectCopy(string& dest_dir):m_dest_dir(dest_dir) {
            filesystem::path cur_path = filesystem::current_path();
            if(cur_path.filename().string() == "output") {
                cur_path = cur_path.parent_path();
            }
            m_src_dir = cur_path.string();
        }
        ProjectCopy(string& dest_dir, string& src_dir):m_dest_dir(dest_dir),m_src_dir(src_dir) {}
        void perform_copy() const;
        const string dest_dir() const {return m_dest_dir;}
        const string src_dir() const {return m_src_dir;}
    };

}

#endif