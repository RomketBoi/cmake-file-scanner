# CMake File Scanner
This program scans a directory and its subdirectories for C++ source files and generates a list of file paths that can be used to generate a CMakeLists.txt file. This can be useful for projects that have a large number of source files and do not want to use the `glob()` function to generate the list of files. This can also be used for any other time where a list of C++ source files is needed.

## Usage
To use the program, run the executable with the path to the directory to scan as the only argument:

`$ ./cmake-file-scanner.exe /path/to/directory`

This will generate a file called output.txt in the current directory that contains a list of file paths that can be used to generate a CMakeLists.txt file.

### Adding to Path
To make the program easier to use, you can add it to your system's PATH variable. This will allow you to run the program from any directory without having to specify the full path to the executable.

To add the program to your `PATH`, follow these steps:

1. Copy the executable to a directory in your system's `PATH`. You can check your system's `PATH` variable by running `echo $PATH` in the terminal.

2. Rename the executable to something shorter if desired. For example, you could rename it to `cmake-scan.exe`.

3. After completing these steps, you should be able to run the program from any directory by typing `cmake-file-scanner.exe /path/to/directory`.

### Handling Spaces in Directory Names
If the directory to scan contains spaces in its name, you will need to enclose the path in quotes when running the program:

`$ ./cmake-file-scanner.exe "/path/to/directory with spaces"`

## Error Messages
Here are the possible error messages that can occur when running the program:

`"Could not open directory [directory_path]"`: This error message occurs when the program fails to open the specified directory. This could happen if the directory does not exist or if the program does not have permission to access it.

`"Could not read file information for [file_path]"`: This error message occurs when the program fails to read the information for a file in the directory. This could happen if the file does not exist or if the program does not have permission to read it.

`"Could not create output file"`: This error message occurs when the program fails to create the output file. This could happen if the program does not have permission to create a file in the specified location or if there is not enough disk space to create the file.

`"Usage: [program_name] [directory_path]"`: This error message occurs when the user does not provide the correct number of arguments when running the program. The program expects one argument, which should be the path to the directory to scan.

## Disadvantages of `glob()`:

Using the `glob()` function to generate a list of source files can be convenient, but it has some disadvantages. One disadvantage is that it can be slow when scanning a large number of files. Another disadvantage is that it may not include all of the files in the directory if there are too many files to fit in the system's command line buffer.

By using a program like `cmake-file-scanner`, you can avoid these disadvantages and generate a more comprehensive list of source files.

## DISCLAMER:
I wrote none of this code (or even the README). This is all written by Phind, a powerful AI search engine for devs. If you are experiencing errors not mentioned above, or cannot find a solution to any problems you encounter, it is recommended to ask Phind for a solution. You can find Phind at https://www.phind.com/.
