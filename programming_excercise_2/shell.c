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

int main (int argc, char* argv[]){
	const char* user_name = get_user_name();

	char host_name[128];
	if(gethostname(host_name, 128)){
		return 1;
	}

	printf("%s@%s: ", user_name, host_name);

	char command[128];
	char args[128];
	scanf("%127s %127s", command, args);
	printf("Befehl: %s\nArgument: %s\n",command,args);
	return 0;

}
