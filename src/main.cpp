
#include <stdint.h>


import std;

// #include <algorithm>
// #include <chrono>
// #include <expected>
// #include <filesystem>
// #include <format>
// #include <iostream>
// #include <optional>
// #include <print>
// #include <ranges>
// #include <source_location>
// #include <span>
// #include <string>
// #include <thread>
// #include <vector>

import fifvmod;


int main() {
    std::println("Hello world!!");
    std::println("the value from cppm: {}", std::format("{}", one()));
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::println();

    auto stressModern() -> void;
    stressModern();
}










/**
 * here are some AI generated example that use lots of STL, let's compare the compilation speed between include and import
 * 9700X,Release:
 *      include 2.5s
 *      import 1.5s
 *
 * Seems that changing a module will cause the module and importer to be re-compiled, while changing importer only recompile
 * the importer
 *
 */




namespace fs = std::filesystem;

struct FileInfo {
    fs::path path;
    uintmax_t size;
};

template <typename T>
concept Printable = requires(T v) { std::format("{}", v); };

void log(std::string_view msg, const std::source_location loc = std::source_location::current()) {
    std::print("[{}:{}] {}\n", loc.file_name(), loc.line(), msg);
}

std::expected<std::vector<FileInfo>, std::string> scan_directory(const fs::path &dir) {
    if (!fs::exists(dir)) {
        return std::unexpected("Directory does not exist");
    }
    std::vector<FileInfo> files;
    for (auto const &entry : fs::directory_iterator(dir)) {
        if (entry.is_regular_file()) {
            files.push_back({entry.path(), entry.file_size()});
        }
    }

    return files;
}

std::optional<FileInfo> largest_file(std::span<FileInfo> files) {
    if (files.empty()) {
        return std::nullopt;
    }
    auto it = std::ranges::max_element(files, {}, &FileInfo::size);
    return *it;
}

template <Printable T> void print_value(const T &v) {
    std::print("Value: {}\n", v);
}

auto stressModern() -> void {
    log("Program started");
    auto start = std::chrono::steady_clock::now();
    auto result = scan_directory(".");
    if (!result) {
        std::print("Error: {}\n", result.error());
        return;
    }

    auto &files = result.value();
    std::ranges::sort(files, {}, &FileInfo::size);
    auto big = largest_file(files);
    if (big) {
        std::print("Largest file: {} ({} bytes)\n", big->path.string(), big->size);
    }

    // auto names =
    //     files | std::views::transform([](const FileInfo &f) { return f.path.filename().string(); }) | std::views::take(5);
    // std::print("\nFirst 5 files:\n");
    // for (auto const &n : names) {
    //     std::print("  {}\n", n);
    // }


    auto worker = std::async(std::launch::async, [] {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::print("Background work done\n");
    });
    worker.wait();

    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    print_value(elapsed.count());

    log("Program finished");
}