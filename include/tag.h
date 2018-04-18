#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

class tag {
    private:
        // name of tag e.g. <tag1></tag1> would be tag1
        string name;
        // hold the reference to direct child
        tag* child;   
        // map of key value pairs for attributes
        map<string, string> attr;
        // parser function
        void parsestring(string str);
        // is this a closer </tag>
        bool closer;
    public: 
        // ctor
        tag(string str);
        // get all attributes
        map<string, string> get_attr();
        // get a single attribute value
        string get_attr_val(string key);
        // get all children
        tag* get_child();
        // add child
        void set_child(tag* child);
        
        bool is_closer();
};