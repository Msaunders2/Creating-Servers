/*
 * mdb-lookup-server-nc-2.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
static void die(const char *s)
{
	perror(s);
	exit(1);
}

int main(int argc, char **argv)
{

	if (argc != 2) {
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(1);
	}

	char buffer[1000];
	//an infinite loop
	while(1){
		fprintf(stdout, "port number: ");
		pid_t pid;

		while((pid = waitpid((pid_t) -1, NULL, WNOHANG))>0){    
				fprintf(stderr, "[pid=%d] ", (int)pid);
				fprintf(stderr, "mdb-lookup-server terminated\n");

		}
			//buffer	
			(fgets(buffer,sizeof(buffer) ,stdin));
			int num = sscanf(buffer, "%d", &num);

			if(num == 1){
			
				//if(num > 1){
				if(buffer[strlen(buffer)-1] == '\n'){
					buffer[strlen(buffer) - 1] = '\0';
				}
			
				pid = fork();
				if (pid < 0) {
					die("fork failed");
				} else if (pid == 0) {
					// child process
					fprintf(stderr, "[pid=%d] ", (int)getpid());
					fprintf(stderr, "mdb-lookup-server started on port %s\n", argv[1]);
					execl("./mdb-lookup-server-nc.sh", "mdb-lookup-server-nc.sh", 
							argv[1], (char *)0);
					die("execl failed");
				} else {
					// parent process
					// not neccessary
				}
			}

		}
	
	return 0;
}
