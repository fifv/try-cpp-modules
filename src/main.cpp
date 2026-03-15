import std;
// #include <print>
// #include <chrono>
// #include <thread>

import fifvmod;

int main() {
    std::println("Hello world!!");
    std::println("the value from cppm: {}", std::format("{}", one()));
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
}