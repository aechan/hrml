#pragma once
#include "tag.h"
#include <vector>

class parser {
    private:
        std::vector<tag> tag_graph;
        tag* current_tag;
    public: 
        void parse_next();
};