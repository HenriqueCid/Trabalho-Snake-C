#include "../include/backend.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define DIMENSION 10
#define MAX_SNAKE_WIDTH 100

#define R 10

char *map;
int n_moves = 0;
int current_X = 0, current_Y = 2;
/*
	Vetores de structs
*/
struct _position_ *__position_snake, *__position_candy;
struct _snake_ *__snake;
struct _candy_ *__candy;

/*
	Inicia as configurações do jogo
*/
void start_cfg(int *snake, int *candy) {
	srand((unsigned int) time(NULL)); // pseudo aleatório
	register int i;
	//*snake = 3;
	map = (char *) malloc(sizeof(char) * DIMENSION * DIMENSION);
	*candy = rand()%R;

	for( i = 0; i < DIMENSION * DIMENSION; i++)
		*(map + i) = '-';


	// Alocação das structs
	__snake = (struct _snake_ *) malloc(sizeof(struct _snake_));
	__snake->size = 3;
	__snake->body_width = (struct _position_ *) malloc(sizeof(struct _position_) * DIMENSION * DIMENSION/2);;

	// se for mais de um doce, pode ser mais de um struct, apenas multiplicar no malloc por um valor desejado
	__position_candy = (struct _position_ *) malloc(sizeof(struct _position_)); 
	__candy = (struct _candy_ *) malloc(sizeof(struct _candy_));


	// faz todas as posicoes serem invalidas
	adjust_move(__snake);
	// posiciona a cobra
	for (i = 0; i < __snake->size; ++i)	make_position(__snake->body_width + i, 0, i); 


}


/*
	Define os xs e ys no vetor de estruturas 
	Para valores x == y == -1  -> posição não preenchida, caso contrário, posição preenchida
		struct _position_ *__position : qualquer struct que represente a posição
		int value_X & int value_X : variaveis da struct vao assumir estes valores (x,y)
*/	
void make_position(struct _position_ *__position, int value_X, int value_Y) {
	*(map + value_X + value_Y) = '#';
	__position->x = value_X;
	__position->y = value_Y;
}

/*
	Posiciona a cobra na matriz
*/
void position_snake(int *snake, struct _snake_ *__snake) {

}


/*
	Gera o doce em uma posição aleatória
*/
void create_candy(int *map, int *candy) {

}

/*
	Movimenta a cobra na matriz
*/

void move_snake(struct _snake_ *__snake, char *key) {

	switch(*key) {
			case 'w':

				break;
			case 'a':
				break;	
			case 's':

				break;	
			case 'd':


				break;	
			case 'q':

				exit(0);
				break;	
			default:
				break;	
		}
		n_moves++;

}

/*
	Escreve na tela o jogo
*/
void show_screen() {
	printf("|");
	register int i;
	for(i = 0; i < DIMENSION*DIMENSION; i++) {
		printf("%c", *(map + i));
		((i+1) % DIMENSION == 0) ? printf("|\n|") : 0;
	}
}

/*
	Começa o jogo

*/
void start_game() {
	char key;
	while(1) {
		scanf("%c", &key);
		move_snake(__snake, &key);
	}
}

void instructions() {
	printf(" ============== Instructions ============= |\n");
	printf("| ===== < w > = UP    == < s > = DOWN ===== |\n");
	printf("| ===== < d > = RIGHT == < a > = LEFT ===== |\n");
	printf("| ============== Instructions ============= |\n");
}
void welcome_game() {
	printf("| ======  WELCOME TO  THE SNAKE GAME ====== |\n");
	printf("| ============== Instructions ============= |\n");
	printf("| ===== < w > = UP    == < s > = DOWN ===== |\n");
	printf("| ===== < d > = RIGHT == < a > = LEFT ===== |\n");
	printf("| ========== LET'S PLAY THE GAME  ==========|\n");
	printf("     => Press <ENTER> to start the game <=\n");

	char key;
	scanf("%c", &key);
	system("@cls||clear");
	(key == '\n') ? show_screen(): exit(0);
	start_game();
}

void adjust_move(struct _snake_ *__snake) {
	register int i;
	for (i = 0; i < DIMENSION; ++i) make_position(__snake->body_width + i, -1, -1); 
}

