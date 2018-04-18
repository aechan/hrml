#pragma once
#include <string>
#include <vector>
#include <map>
#include "tagtype.h"

class tag {
    private:
        // name of tag e.g. <tag1></tag1> would be tag1
        std::string name;
        // hold the reference to direct child
        std::vector<tag*> children;   
        // map of key value pairs for attributes
        std::map<std::string, std::string> attr;
        // parser function
        tagtype parsestring(std::string str);
        // is this a closer </tag>
        bool closer;

        tagtype tag_type;
    public: 
        // get all attributes
        std::map<std::string, std::string> get_attr();
        // get a single attribute value
        std::string get_attr_val(std::string key);
        // get all children
        std::vector<tag*> get_children();
        // add child
        void add_child(tag* child);
        
        bool is_closer();

        tagtype get_type();
};