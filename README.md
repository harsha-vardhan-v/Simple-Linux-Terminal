# Simple-Linux-Terminal
Code for a simple terminal like process using C.

How it works:
-------------

-> The program is a while loop waiting for an input string.
-> Then the program forks a new process and the executes the command given by the user.
-> The parent waits for the child process to complete execution.
-> After the execution of the child the process returns to the parent which again waits for the next input.
-> The loop terminates when the command given is "exit".

System Calls Used:
------------------

-> fork() -> creates a new process
-> waitpid() -> to wait for the child to finish execution
-> execvp() -> to execute the command given by the user
