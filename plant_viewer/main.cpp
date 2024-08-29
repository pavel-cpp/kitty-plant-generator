#include "application.h"
#include "genom.h"
#include "io/loader.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        auto gen {load(argv[1])};
        application app {gen};
        return app.exec();
    }
    return 1;
}
