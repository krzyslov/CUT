Usefull commands that i used:

Automatical test:
>cd build

Valgrind check:
>cd build
>valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=../valgrind-out.txt ./MyExecutable

>valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=/valgrind-out.txt ./MyExecutable