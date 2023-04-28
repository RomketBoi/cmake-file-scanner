#include <dirent.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <filesystem>

void scanDirectory(const std::string& dir, std::ofstream& outfile) {
    // Open the directory
    DIR* dp = opendir(dir.c_str());

    if (dp == NULL) {
        std::cout << "Could not open directory " << dir << std::endl;
        return;
    }

    // Read the directory contents
    struct dirent* entry;

    while ((entry = readdir(dp)) != NULL) {
        // Construct the full path to the entry
        std::string path = dir + "/" + entry->d_name;

        // Check if the entry is a directory
        struct stat info;

        if (stat(path.c_str(), &info) != 0) {
            std::cout << "Could not read file information for " << path << std::endl;
            continue;
        }

        if (S_ISDIR(info.st_mode)) {
            // Skip . and .. directories
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            // Recursively scan the subdirectory
            scanDirectory(path, outfile);
        } else if (S_ISREG(info.st_mode)) {
            // Check if the file is a .cpp file
            if (strstr(entry->d_name, ".cpp") != NULL) {
                // Append the file name to the output string
                outfile << path << std::endl;
            }
        }
    }

    // Close the directory
    closedir(dp);
}

int main(int argc, char* argv[]) {
    // Check if the user entered a directory path
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " directory_path" << std::endl;
        return 1;
    }

    // Create the output file
    std::ofstream outfile("output.txt");

    if (!outfile.is_open()) {
        std::cout << "Could not create output file" << std::endl;
        return 1;
    }

    // Start scanning the directory tree
    scanDirectory(argv[1], outfile);

    // Close the output file
    outfile.close();

    // Print a success message and the path to the output file
    std::cout << "Scan completed successfully. Output file: " << std::endl;
    std::cout << "    " << std::filesystem::absolute("output.txt") << std::endl;

    return 0;
}
