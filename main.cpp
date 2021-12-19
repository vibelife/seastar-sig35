#include <seastar/core/app-template.hh>
#include <seastar/core/reactor.hh>
#include <vector>
#include <iostream>

namespace ss = seastar;

void slow() {
    size_t foo = 0;
    for (int a = 0; a < 100000000; ++a) {
        foo += 1;
    }
}

ss::future<> go() {
    std::vector<int> ints {1,2,3,4};

    return ss::parallel_for_each(ints, [&](auto const& i) {
        return ss::futurize_invoke(slow).then([] {
            std::cout << "Done\n" << std::flush;
        });
    });
}

int main(int argc, char** argv) {
    ss::app_template app;
    app.run(argc, argv, go);
}
