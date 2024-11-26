#include <bits/posix1_lim.h>
#include <limits.h>
#include <linux/limits.h>
#include <unistd.h>
#include <pwd.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdbool.h>

#include <signal.h>

// Signal handler for SIGINT (Ctrl+C)
void handle_sigint(int sig) {
    printf("\nExiting shell...\n");
    // Perform any cleanup tasks here if needed
    _exit(0); // Exit immediately
}

const char* get_user_name(void){
	struct passwd *p;
	uid_t uid;
	
	if((p = getpwuid(uid = getuid())) == NULL){
		perror("getpwuid() error\n");
	}else {
		return p->pw_name;
	}
	return "USERNAME_ERROR";
}


void print_shell_prefix(void){

	const char* user_name = get_user_name();

	char host_name[HOST_NAME_MAX];
	if(gethostname(host_name, HOST_NAME_MAX)){
		perror("couldn't get hostname\n");
	}


	char cwd[PATH_MAX];
	getcwd(cwd, PATH_MAX);

	printf("%s@%s:~%s$ ", user_name, host_name, cwd);
}

void get_shell_input(char* command, char* args){
	if(scanf("%127s %127s", command, args) == 1){
		args = "";
	}
}

void get_new_input(char* command, char* args){
	print_shell_prefix();
	get_shell_input(command, args);
}

void execute_command(char* command, char* args){
	printf("command: %s\n", command);
	if(command == NULL){
		perror("command is NULL\n");
		return;
	}
	
	execlp(command, command, args, NULL);
	perror("execlp failed");

}

bool is_shell_command(char* command){
	if(strcmp(command, "cd") == 0){
		return true;
	}
	return false;
}


int main (int argc, char* argv[]){
	 // Set up the SIGINT handler
    struct sigaction sa;
    sa.sa_handler = handle_sigint;
    sa.sa_flags = SA_RESTART; // Restart interrupted system calls
    sigaction(SIGINT, &sa, NULL);

	char command[128];
	char args[128];

	while (1) {
		get_new_input(command, args);

		pid_t pid = fork();
		// printf("pid: %d\n", pid);
		if (pid == -1) {
			perror("fork failed");
			return 1;
		} else if (pid == 0) {
			if (is_shell_command(command))
			{
				if(strcmp(command, "cd") == 0){
					if(chdir(args) == -1){
						perror("cd failed");
					}
					continue;
				}
			} else {
				// Child process
				execute_command(command, args);
			}
			//perror("execlp failed");
			return 1;
		} else {
			// Parent process
			int status;
			waitpid(pid, &status, 0);
			printf("Exitstatus: %d\n", status);
		}
	}
	return 0;

}
