# **CPU Usage Tracker Project**

## Description
This project is a console application written in C that monitors per-core CPU usage on Linux systems. It uses multithreading to read data from the `/proc/stat` file, analyze it, calculate CPU load, and display results in real-time, with a focus on synchronization and stable performance.

## Compiler Flags
- **GCC**: `-Wall -Wextra -Werror`
- **Clang**: `-Weverything -Werror`

> Setting the `-Werror` flag treats all warnings as errors, ensuring that no warning is missed during compilation. This flag prevents potential oversight of important warnings by promoting them to errors that require immediate attention.

## How to Run the Program
To launch the program, use the following commands:
```bash
cd build
./MyExecutable
How to Run Tests
```

To run tests, use:

```bash
cd build
make test
```

How to Run Valgrind Memory Leak Check
For a comprehensive Valgrind memory check, use:
```bash
bash
Skopiuj kod
cd build
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=../valgrind-out.txt ./MyExecutable
```
# To stop the program, press ctrl+c
Valgrind Check Summary
Valgrind results confirm that the program is free of memory leaks:

```yaml
==43850== HEAP SUMMARY:
==43850==     in use at exit: 0 bytes in 0 blocks
==43850==   total heap usage: 59 allocs, 59 frees, 18,950 bytes allocated
==43850== 
==43850== All heap blocks were freed -- no leaks are possible
==43850== 
==43850== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
#Key Features
*Multithreading: Separate threads for reading, analyzing, and displaying CPU usage data, ensuring smooth real-time tracking.
*Error-Free Compilation: Strict compilation flags (-Werror) to ensure code quality and handle warnings as errors.
*Memory Leak Testing: Integrated Valgrind testing to confirm efficient memory usage and prevent leaks.
*Cross-Compiler Compatibility: Compatible with both GCC and Clang, with adaptable build configuration.
Future Improvements
*If time permits, potential additions could include:

