#include "application.h"
#include "raw_genom.h"
#include "tree_builder.h"
#include "io/loader.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        auto gen {load(argv[1])};
        application app {gen};
        return app.exec();
    }
    return 1;
}
