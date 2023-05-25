-For GCC compiler i set flags: -Wall -Wextra -Werror
-For Clang compiler i set the flags: -Weverything -Werror

-I set the -Werror flag becouse it treats warnings as errors.
Therefore it is impossible to miss a warning.
Without that flag a warning is generated when compiling, but I might miss it. 

How to launch program
>cd build
>./MyExecutable

How to launch test:
>cd build
>make test

How to launch valgrind test:
>cd build
>valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=../valgrind-out.txt ./MyExecutable

If it comes to Valgrind check, there's the summary:
==43850== HEAP SUMMARY:
==43850==     in use at exit: 0 bytes in 0 blocks
==43850==   total heap usage: 59 allocs, 59 frees, 18,950 bytes allocated
==43850== 
==43850== All heap blocks were freed -- no leaks are possible
==43850== 
==43850== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)