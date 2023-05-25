How to launch test:
>cd build

How to launch valgrind test:
>cd build
>valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=../valgrind-out.txt ./MyExecutable

>valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=/valgrind-out.txt ./MyExecutable


-For GCC compiler i set flags: -Wall -Wextra -Werror
-For Clang compiler i set the flags: -Weverything -Werror

-I set the -Werror flag becouse it treats warnings as errors.
Therefore it is impossible to miss a warning.
Without that flag a warning is generated when compiling,
but you might miss it. 