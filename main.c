#include "include/backend.h"
#include <malloc.h>
//#include <graphics.h>

int snake, candy;

char *map;


int main(char *argv, char *argc[]) {

	
	start_cfg(&snake, &candy);
	welcome_game();

	free(map);
	return 0;
}