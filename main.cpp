#include <getopt.h>
#include <iostream>
#include <stdlib.h>
#include <string>

void handleoptionWithoutArguments(std::string optionName) {
    std::cout << "Option:" << optionName << std::endl;
}

void handleoptionWithArguments(std::string optionName, char* args) {
    std::cout << "Option:" << optionName << ", arguments: ";
    std::string arguments = args;
        if (arguments.find(",") == std::string::npos) {
            std::cout << arguments << std::endl;
        } 
        else {
            int last_pos = 0;
            size_t pos = 0;
            while ((pos = arguments.find(",")) != std::string::npos) {
                std::string token = arguments.substr(0, pos);
                std::cout << token << " ";
                arguments.erase(0, pos + 1);
            }
            std::cout << arguments << std::endl;
        }
}

int main(int argc, char **argv) {
    while (true) {
        int option_index = 0;
        static option long_options[] = {
            {"help", no_argument, 0, 'h'},
            {"version", no_argument, 0, 'v'},
            {"list", required_argument, 0, 'l'},
            {0, 0, 0, 0}
        };

        int option = getopt_long(argc, argv, "hvl:", long_options, nullptr);
        if (option == -1) {
            break;
        }
        switch (option) {
        case 'h':
            handleoptionWithoutArguments("Help");
            break;
        case 'v':
            handleoptionWithoutArguments("Version");
            break;
        case 'l':
            handleoptionWithArguments("List", optarg);
            break;
        default:
            break;
        }
    }

    return 0;
}
