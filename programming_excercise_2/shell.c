#include <bits/posix1_lim.h>
#include <limits.h>
#include <linux/limits.h>
#include <unistd.h>
#include <pwd.h>
#include <stdio.h>


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
	execlp(command,args);

}

int main (int argc, char* argv[]){
	char command[128];
	char args[128];
	get_new_input(command, args);

	// printf("Befehl: %s\nArgument: %s\n",command,args);
	execute_command(command, args);
	return 0;

}
