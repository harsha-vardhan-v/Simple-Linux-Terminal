#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char** argv;
	int argc;
	pid_t pid;

	do{
		char command[100], word[20];
		argc = 0;
		free(argv);
		argv = (char**) malloc(10*sizeof(char*));

		printf("Terminal>> ");
		fgets(command, 100, stdin);

		int len = (int) strlen(command), letter_inc = 0;
		for(int i=0; i<len; i++){
			if(command[i] == ' ' || command[i] == '\n'){
				word[letter_inc] = '\0';

                argv[argc] = (char*) malloc(letter_inc*sizeof(char));
				strcpy(argv[argc], word);

				argc++;
				letter_inc = 0;
			}

			else{
				word[letter_inc] = command[i];
				letter_inc++;
			}
		}


		//Creating a process for the given command
		pid = fork();

                if(pid == 0){
                        //Child process to execute the command
                        execvp(argv[0], argv);
                }

		//Parent to wait for the child to finish
                waitpid(-1, NULL, 0);


	}while(strcmp(argv[0], "exit") != 0);

	if(pid != 0){
		free(argv);
	}

	return 0;
}
