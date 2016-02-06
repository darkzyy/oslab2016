#include <inc/string.h>
#include <inc/stdio.h>

#include <kern/draw.h> // for tux
#include <kern/game.h>
#include <kern/game_draw.h>
#include <kern/game_layout.h>

struct pos protag, box[3];

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
	else if(box[1].x == protag.x+right &&
				box[1].y == protag.y+down) {
		return 3;
	}
	else {
		return 0;
	}
}

static int
protag_movable(int right, int down) {
	if(map[next_x][next_y] == game_wall) {
		return false;
	}
	int box_index = protag_infrontof_box(right, down);
	if(!box_index) {
		return true;
	}
	else{
		box_index -= 1;
		int target_area = map[next_box_x(box_index)][next_box_y(box_index)];
		if(target_area == game_wall) {
			return false;
		}
		else if(box_index != 0 && 
					((next_box_x(box_index) == box[1].x &&
					  next_box_y(box_index) == box[1].y ) || 
					 (next_box_x(box_index) == box[2].x &&
					  next_box_y(box_index) == box[2].y ))) {
			return false;
		}
		else if(box_index != 1 && 
					((next_box_x(box_index) == box[0].x &&
					  next_box_y(box_index) == box[0].y ) || 
					 (next_box_x(box_index) == box[2].x &&
					  next_box_y(box_index) == box[2].y ))) {
			return false;
		}
		else if(box_index != 2 && 
					((next_box_x(box_index) == box[0].x &&
					  next_box_y(box_index) == box[0].y ) || 
					 (next_box_x(box_index) == box[1].x &&
					  next_box_y(box_index) == box[1].y ))) {
			return false;
		}
		else {
			return true;
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
	if(map[box[0].x][box[0].y] == game_dest && 
				map[box[1].x][box[1].y] == game_dest &&
				map[box[2].x][box[2].y] == game_dest) {
		return true;
	}
	else{
		return false;
	}
}

void
game_loop(void) { /* driven by keyboard interuption */
	game_display();
	while(1) {
		int getch = getchar();
		if(getch == 'a') {
		}
		else if(getch == 's') {
		}
		else if(getch == 'd') {
		}
		else if(getch == 'w') {
		}
		else if(getch == 'v') {
		}
		else{
			continue;
		}

		game_display();

		if(victory()) {
			draw_tux();
		}
	}
}
