#include <iostream>
#include <thread>
#include <random>
#include <algorithm>

struct ThreadData {
    std::string messages[3];
    int num_messages;
};

void print_messages(ThreadData* data) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(100, 500);

    std::shuffle(data->messages, data->messages + data->num_messages, gen);

    for (int i = 0; i < data->num_messages; ++i) {
        std::cout << data->messages[i] << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(distr(gen)));
    }
}

int main() {
    ThreadData data = {{"DIN", "DON", "DAN"}, 3};

    while (true) {
        print_messages(&data);
    }
    return 0;
}