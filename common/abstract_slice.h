#ifndef ABSTRACT_GENOM_H
#define ABSTRACT_GENOM_H

#include "raw_genom.h"

class abstract_slice {
    public:
        abstract_slice(raw_slice raw) : raw_ {raw} {}
        [[nodiscard]] raw_slice get_raw() const { return raw_; }
    private:
        raw_slice raw_;
};

#endif //ABSTRACT_GENOM_H
