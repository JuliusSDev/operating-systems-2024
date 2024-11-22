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

	char host_name[128];
	if(gethostname(host_name, 128)){
		perror("couldn't get hostname\n");
	}


	char cwd[256];
	getcwd(cwd, 256);

	printf("%s@%s:~%s$ ", user_name, host_name, cwd);
}

void get_shell_input(void){
	char command[128];
	char args[128];
	scanf("%127s %127s", command, args);
	printf("Befehl: %s\nArgument: %s\n",command,args);
}

void get_new_input(void){
	print_shell_prefix();
	get_shell_input();
}

int main (int argc, char* argv[]){
	get_new_input();
	return 0;

}
