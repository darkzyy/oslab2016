#include <inc/lib.h>

static int map[9][9] = {
	{ 1, 1, 1, 1, 1, 3, 3, 3, 3},
	{ 1, 0, 0, 0, 1, 3, 3, 3, 3},
	{ 1, 0, 0, 0, 1, 3, 1, 1, 1},
	{ 1, 0, 0, 0, 1, 3, 1, 2, 1},
	{ 1, 1, 1, 0, 1, 1, 1, 2, 1},
	{ 3, 1, 1, 0, 0, 0, 0, 2, 1},
	{ 3, 1, 0, 0, 0, 1, 0, 0, 1},
	{ 3, 1, 0, 0, 0, 1, 1, 1, 1},
	{ 3, 1, 1, 1, 1, 1, 3, 3, 3}
};

#define grey	20
#define blue	9
#define yellow	13
#define pink	14
#define black	0
#define red		6


enum {
	game_space = 0,
	game_wall,
	game_dest,
	game_out
};

struct pos{
    int x;
    int y;
};
struct pos protag, box[3];

#define LEN 20

static void
draw_map() {
	int x,y;
	for(y = 0;y < 9;y++){
		for(x = 0;x < 9;x++){
			if(map[y][x] == game_space){
				sys_draw_sqr(x*LEN, y*LEN, blue, LEN);
			}
			else if(map[y][x] == game_wall){
				sys_draw_sqr(x*LEN, y*LEN, grey, LEN);
			}
			else if(map[y][x] == game_dest){
				sys_draw_sqr(x*LEN, y*LEN, red, LEN);
			}
			else if(map[y][x] == game_out){
				sys_draw_sqr(x*LEN, y*LEN, black, LEN);
			}
		}
	}
}

static void
draw_box() { /*and protagonist*/
	sys_draw_sqr(protag.x*LEN, protag.y*LEN, pink, LEN);
	sys_draw_sqr(box[0].x*LEN, box[0].y*LEN, yellow, LEN);
	sys_draw_sqr(box[1].x*LEN, box[1].y*LEN, yellow, LEN);
	sys_draw_sqr(box[2].x*LEN, box[2].y*LEN, yellow, LEN);
}

void
game_display(){
	cprintf("game displaying\n");
	draw_map();
	draw_box();
	sys_display();
}

#undef LEN


#define next_x (protag.x+right)
#define next_y (protag.y+down)
#define next_box_x(index) (box[index].x+right)
#define next_box_y(index) (box[index].y+down)

static void
position_init() {
	protag.x = 3;
	protag.y = 1;
	box[0].x = 3;
	box[0].y = 2;
	box[1].x = 2;
	box[1].y = 2;
	box[2].x = 2;
	box[2].y = 3;
}

static int
protag_infrontof_box(int right, int down) { // if false return 0,else return box index + 1
	if(box[0].x == protag.x+right &&
				box[0].y == protag.y+down) {
		return 1;
	}
	else if(box[1].x == protag.x+right &&
				box[1].y == protag.y+down) {
		return 2;
	}
	else if(box[2].x == protag.x+right &&
				box[2].y == protag.y+down) {
		return 3;
	}
	else {
		return 0;
	}
}

static int
protag_movable(int right, int down) {
	if(map[next_y][next_x] == game_wall) {
		cprintf("reason 1\n");
		return 0;
	}
	int box_index = protag_infrontof_box(right, down);
	if(!box_index) {
		return 1;
	}
	else{
		box_index -= 1;
		int target_area = map[next_box_y(box_index)][next_box_x(box_index)];
		if(target_area == game_wall) {
			cprintf("reason 2\n");
			return 0;
		}
		else if(box_index != 0 && 
					((next_box_x(box_index) == box[1].x &&
					  next_box_y(box_index) == box[1].y ) || 
					 (next_box_x(box_index) == box[2].x &&
					  next_box_y(box_index) == box[2].y ))) {
			cprintf("reason 3\n");
			return 0;
		}
		else if(box_index != 1 && 
					((next_box_x(box_index) == box[0].x &&
					  next_box_y(box_index) == box[0].y ) || 
					 (next_box_x(box_index) == box[2].x &&
					  next_box_y(box_index) == box[2].y ))) {
			cprintf("reason 4\n");
			return 0;
		}
		else if(box_index != 2 && 
					((next_box_x(box_index) == box[0].x &&
					  next_box_y(box_index) == box[0].y ) || 
					 (next_box_x(box_index) == box[1].x &&
					  next_box_y(box_index) == box[1].y ))) {
			cprintf("reason 5\n");
			return 0;
		}
		else {
			return 1;
		}
	}
}

static void
protag_move(int right, int down) {
	if(protag_movable(right, down)) {
		int box_index = protag_infrontof_box(right, down);
		if(box_index) { //pushing a box
			box_index -= 1;
			box[box_index].x += right;
			box[box_index].y += down;
		}
		protag.x += right;
		protag.y += down;
	}
	else{
		return;
	}
}

static int
victory() {
	if(map[box[0].y][box[0].x] == game_dest && 
				map[box[1].y][box[1].x] == game_dest &&
				map[box[2].y][box[2].x] == game_dest) {
		return 1;
	}
	return 0;
}

void
umain(int argc, char **argv) { /* driven by keyboard interuption */
__game_restart:
	position_init();
	game_display();
	while(1) {
		int getch = getchar();
		if(getch == 'a') {
			protag_move(-1, 0);
		}
		else if(getch == 's') {
			protag_move(0, 1);
		}
		else if(getch == 'd') {
			protag_move(1, 0);
		}
		else if(getch == 'w') {
			protag_move(0, -1);
		}
		else if(getch == 'r') {
			goto __game_restart;
		}
		else{
			continue;
		}

		game_display();

		if(victory()) {
			goto __game_restart;
		}
	}
}
