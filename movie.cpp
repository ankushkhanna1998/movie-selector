#include <csignal>
#include <exception>
#include <filesystem>
#include <iostream>
#include <random>
#include <regex>
#include <vector>

void signal_handler(int signal_code) {
    std::cerr << std::endl << "Keyboard Interrupt!" << std::endl;
    exit(128 + signal_code);
}

int main() {
    std::signal(SIGINT, signal_handler);

    std::vector<std::string> candidate_items;

    try {
        const std::vector<std::string> search_paths = {
            /*
             * Put all valid search paths here (comma separated)
             *
             * For example:
             *
             * "/home/ankush/Downloads/", "/home/ankush/Documents/", ...
             */
        };

        /*
         * Valid `regex` pattern to match for `candidate_items`
         *
         * For example, to match all `.mp4` and `.mkv` video files
         * in the given search paths, we can do something like:
         *
         * const std::regex pattern_to_match("(.*)(\\.mp4|\\.mkv|\\.MP4|\\.MKV)((\\ *\t*)*)");
         */

        const std::regex pattern_to_match("(.*)");

        namespace fs = std::filesystem;

        for (const std::string &search_path : search_paths) {
            for (const fs::directory_entry &entry : fs::recursive_directory_iterator(search_path)) {
                if (entry.is_regular_file() && std::regex_match(entry.path().filename().string(), pattern_to_match)) {
                    candidate_items.push_back(entry.path().filename().string());
                }
            }
        }

    } catch (const std::exception &e) {
        std::cerr << "Oops! " << e.what() << std::endl << std::endl;
        std::cerr << "Possible issues:" << std::endl;
        std::cerr << "    Unmounted Device, and/or" << std::endl;
        std::cerr << "    Invalid/Incorrect/Non-Existing/Restricted Search Path, and/or" << std::endl;
        std::cerr << "    Invalid/Incorrect Regular Expression Matching Pattern, ..., etc." << std::endl << std::endl;
        exit(128 + 126);
    }

    if (candidate_items.empty()) {
        std::cerr << "Nothing Found!" << std::endl;
        exit(1);
    }

    std::cout << candidate_items.at(std::random_device()() % candidate_items.size()) << std::endl;

    return 0;
}
