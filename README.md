# get_next_line Project at 1337

## Overview

This project, implemented at 1337 school, focuses on creating a function called `get_next_line` that reads a line from a given file descriptor. The goal is to enable the reading of a text file one line at a time through repeated calls to the function.

## Project Files

- **get_next_line.c**: The main implementation file containing the `get_next_line` function.
- **get_next_line_utils.c**: The file where helper functions required for the main implementation are placed.
- **get_next_line.h**: The header file with the prototype of the `get_next_line` function.

## Function Prototype

```c
char *get_next_line(int fd);
```

## Parameters
- `fd`: The file descriptor to read from.

## Return Value
- Read line: If the function successfully reads a line.
- `NULL`: If there is nothing else to read or if an error occurred.

## External Functions
- `read`: Used for reading from the file descriptor.
- `malloc`: Utilized for dynamic memory allocation.
- `free`: Employed for releasing allocated memory.

## Functionality
- Repeated calls to `get_next_line` allow reading the text file pointed to by the file descriptor, one line at a time.
- The function returns the line that was read.
- If there is nothing else to read or an error occurs, it returns `NULL`.
- Works with both file reading and reading from standard input.

## Note
- The returned line includes the terminating `\n` character, except if the end of the file was reached and does not end with a `\n` character.

## How to Use

1. Clone the repository to your local machine.

    ```bash
    git clone <repository-url>
    ```

2. Compile the project files.

    ```bash
    gcc -Wall -Wextra -Werror -D BUFFER_SIZE=<your-buffer-size> get_next_line.c get_next_line_utils.c -o gnl
    ```

3. Run the executable.

    ```bash
    ./gnl <file-to-read>
    ```

4. Check the output, and observe the behavior of the `get_next_line` function.

Feel free to explore and modify the code to suit your needs or extend its functionality.

**Note:** Replace `<your-buffer-size>` with the desired buffer size for reading lines from the file.

# Bonus Part

If you want to challenge yourself further, you can attempt the bonus part:

- **get_next_line_bonus.c**: The bonus part implementation file.
- **get_next_line_utils_bonus.c**: The bonus part file with helper functions.
- **get_next_line_bonus.h**: The bonus part header file with the prototype of the `get_next_line` function for the bonus part.

## Bonus Objectives:

1. Develop `get_next_line()` using only one static variable.
2. Manage multiple file descriptors at the same time.

   For example, if you can read from the file descriptors 3, 4, and 5, you should be able to read from a different fd per call without losing the reading thread of each file descriptor or returning a line from another fd.

   It means that you should be able to call `get_next_line()` to read from fd 3, then fd 4, then 5, then once again 3, once again 4, and so forth.

Append the `_bonus.[c|h]` suffix to the bonus part files.

It means that, in addition to the mandatory part files, you will turn in the 3 following files:

- **get_next_line_bonus.c**
- **get_next_line_bonus.h**
- **get_next_line_utils_bonus.c**


## Contributions

Contributions to the project are welcome. If you encounter any issues or have improvements to suggest, feel free to create a pull request or open an issue in the repository.

Happy coding!
