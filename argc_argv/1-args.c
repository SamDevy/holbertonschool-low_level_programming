1. Silence is argument carried out by other means
mandatory
Write a program that prints the number of arguments passed into it.

Your program should print a number, followed by a new line
julien@ubuntu:~/argc, argv$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-args.c -o nargs
julien@ubuntu:~/argc, argv$ ./nargs 
0
julien@ubuntu:~/argc, argv$ ./nargs hello
1
julien@ubuntu:~/argc, argv$ ./nargs "hello, world"
1
julien@ubuntu:~/argc, argv$ ./nargs hello, world
2
julien@ubuntu:~/argc, argv$ 
Repo:

GitHub repository: holbertonschool-low_level_programming
Directory: argc_argv
File: 1-args.c
