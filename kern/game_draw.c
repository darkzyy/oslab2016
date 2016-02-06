#include <kern/video.h>
#include <kern/game.h>
#include <kern/game_draw.h>
#include <kern/game_layout.h>

#define LEN 20

static void
draw_map() {
	int x,y;
	for(y = 0;y < 9;y++){
		for(x = 0;x < 9;x++){
			if(map[y][x] == game_space){
				draw_square(x*LEN, y*LEN, blue, LEN);
			}
			else if(map[y][x] == game_wall){
				draw_square(x*LEN, y*LEN, grey, LEN);
			}
			else if(map[y][x] == game_dest){
				draw_square(x*LEN, y*LEN, red, LEN);
			}
			else if(map[y][x] == game_out){
				draw_square(x*LEN, y*LEN, black, LEN);
			}
			else{
				assert(0);
			}
		}
	}
}

static void
draw_box() { /*and protagonist*/
	draw_square(protag.x*LEN, protag.y*LEN, pink, LEN);
	draw_square(box[0].x*LEN, box[0].y*LEN, yellow, LEN);
	draw_square(box[1].x*LEN, box[1].y*LEN, yellow, LEN);
	draw_square(box[2].x*LEN, box[2].y*LEN, yellow, LEN);
}

void
game_display(){
	cprintf("game displaying\n");
	draw_map();
	draw_box();
	display_buffer();
}

#undef LEN
