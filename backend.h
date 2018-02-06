/*
	Arquivo onde ficarão os protótipos das funções e estruturas
*/
struct _position_ {
	int x;
	int y;
};
struct _snake_ {
	int size;
	struct _position_ *body_width;
};

struct _candy_ {
	int life;
	struct _position_ this_position;
};



void start_cfg(int *snake, int *candy); // inicia as configurações do jogo
void create_candy(int *map, int *candy); // tamanho *map = LINHA x COLUNA
void move_snake(struct _snake_ *__snake, char *key); // move a cobra
void show_screen(); // mostra tela
void make_position(struct _position_ *__position, int value_X, int value_Y); //posiciona elementos
void start_game(); // COmeça o jogo
void welcome_game();
void instructions();
void adjust_move(struct _snake_ *__snake);
