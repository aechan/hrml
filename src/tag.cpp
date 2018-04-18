#include "tag.h"
#include <sstream>
#include <stdexcept>      // std::out_of_range

using namespace std;

/**
 * Parses the tag from string
 **/ 
tagtype tag::parsestring(string str) {
    stringstream ss(str);
    
    // start parsing attributes
    string attribute_pair;
    while(std::getline(ss, attribute_pair, ' ')) {
        // edge case 0: is this a closer </tag>
        if(attribute_pair[0] == '<' && attribute_pair[1] == '/') {
            closer = true;
            this->tag_type = tagtype::CLOSER;
            return tagtype::CLOSER;
        }
        // we know its not a closer
        this->closer = false;
        // edge case 1: if this is a tag with no attrs e.g. <tag>
        if(attribute_pair[0] == '<' && attribute_pair[attribute_pair.size()-1] == '>') {
            name = attribute_pair.substr(1, attribute_pair.size()-2);
            break;
        }
        // edge case 2: if this is an opener bit e.g. <tag
        if(attribute_pair[0] == '<') {
            // get the rest minus the opener bracket
            name = attribute_pair.substr(1);
            break;
        }
        // edge case 3: if this is a closer bit e.g attributeN="hello">
        // in this case we still can parse the attribute key and value normally
        // we just need to keep in mind the closer tag
        bool iscloserbit = (attribute_pair[attribute_pair.size()-1] == '>');

        // now actually parse the kvp e.g. attr1="xyz"
        stringstream s(attribute_pair);
        string keyorval;
        string key;
        string val;
        // split on the equals
        while(std::getline(s, keyorval, '=')) {
            if(keyorval[0] == '"') {
                val = iscloserbit ? keyorval.substr(1, keyorval.size()-3) : keyorval.substr(1, keyorval.size()-2);
            } else {
                key = keyorval;
            }
        }

        // now we have key and val so simply insert into the map
        attr[key] = val;
    }
    this->tag_type = tagtype::OPENER;
    return tagtype::OPENER;
}

map<string, string> tag::get_attr() {
    return attr;
}

string tag::get_attr_val(string key) {
    try {
        return attr.at(key);
    } catch(const std::out_of_range& oor) {
        return "Not Found!";
    }
}

vector<tag*> tag::get_children() {
    return children;
}

void tag::add_child(tag* child) {
    this->children.push_back(child);
}

bool tag::is_closer() {
    return closer;
}