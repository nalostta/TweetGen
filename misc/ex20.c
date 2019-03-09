#include"dbg.h"
#include<stdio.h>
#include<stdlib.h>
#include"frm.c"

void test_debug();
void test_log_err();
void test_log_warn();
void test_log_info();
int test_check(char* file_name);
int test_sentinel(int code);
int test_check_mem();
int test_check_debug();

int main(int argc, char *argv[])
{
	printf("\n%d",argc);
	check(argc == 2, "Need an argument.");
    return 0;

error:
    return 1;
}

void test_debug()
{
	//notice there's no need for \n
	debug("I have brown hair.");
	
	//passing in arguments like printf
	debug("I am %d years old.",37);
}

void test_log_err()
{
	log_err("I believe everything is broken.");
	log_err("There are %d problems in %s.",0,"space");
}

void test_log_warn()
{
	log_warn("you can safely ignore this.");
	log_warn("Maybe consider looking at: %s.","/etc/passwd");
}

void test_log_info()
{
	log_info("Well I did something mundane.");
	log_info("It happened %f times today.",1.3f);
}

int test_check(char* file_name)
{
	FILE* input=NULL;
	char* block=NULL;
	
	block=malloc(100);
	check_mem(block);//should work
	
	input=fopen(file_name,"r");
	check(input,"Failed to open %s.",file_name);
	
	free(block);
	fclose(input);
	return 0;
	
error:
	if(block) free(block);
	if(input) fclose(input);
	return -1;
}

int test_sentinel(int code)
{
    char *temp = malloc(100);
    check_mem(temp);

    switch(code) {
        case 1:
            log_info("It worked.");
            break;
        default:
            sentinel("I shouldn't run.");
    }

    free(temp);
    return 0;

error:
    if(temp) free(temp);
    return -1;
}

int test_check_mem()
{
	char* test=NULL;
	check_mem(test);
	
	free(test);
	return 1;
	
error:
	return -1;
}

int test_check_debug()
{
    int i = 0;
    check_debug(i != 0, "Oops, I was 0.");

    return 0;
error:
    return -1;
}
