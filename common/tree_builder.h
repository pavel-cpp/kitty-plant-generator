#ifndef TREE_BUILDER_H
#define TREE_BUILDER_H

#include <functional>
#include <treehh/tree.hh>
#include "raw_genom.h"
#include "abstract_slice.h"

using drawable_function = std::function<std::shared_ptr<abstract_drawable_slice>(raw_slice)>;

class drawable_genom_maker {
    public:
    drawable_genom_maker(tree<std::shared_ptr<abstract_drawable_slice>>& tr, drawable_function make_slice) : tree_ {tr}, make_slice_ {make_slice} {}

    void make(tree<std::shared_ptr<abstract_drawable_slice>>::iterator top, raw_genom::const_iterator begin, raw_genom::const_iterator end) {
        if (begin == end) {
            return;
        }
        auto head {top->get()};
        auto new_node {*begin};
        for (uint8_t i {}; i < head->get_raw().amount_of_children; ++i) {
            auto last_node {tree_.insert(top, make_slice_(new_node))};
            make(last_node, std::next(begin), end);
            new_node.angle = head->get_raw().angle + head->get_raw().child_angle_bias + (head->get_raw().angle_delta * i);
        }
    }

    private:
    tree<std::shared_ptr<abstract_drawable_slice>>& tree_;
    drawable_function make_slice_;
};

inline tree<std::shared_ptr<abstract_drawable_slice>> make_drawable_genom_tree(const raw_genom& genom, drawable_function make_slice) {
    tree<std::shared_ptr<abstract_drawable_slice>> genom_tree {};
    genom_tree.set_head(make_slice(genom.front()));
    auto top {genom_tree.begin()};
    drawable_genom_maker {genom_tree, make_slice}.make(top, std::next(genom.begin()), genom.end());
    return genom_tree;
}

#endif //TREE_BUILDER_H
