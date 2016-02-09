#include <inc/string.h>
#include <inc/stdio.h>

#include <kern/video.h>

#define PIC {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,\
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,1,9,9,9,1,9,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,\
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,15,15,15,15,15,0,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,\
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,9,9,9,15,15,15,15,0,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,\
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,15,0,0,0,0,0,0,1,9,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,\
	1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,15,15,0,0,15,0,0,0,9,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,\
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,15,15,0,9,15,15,0,0,9,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,\
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,15,0,0,0,15,15,0,0,9,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,\
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,15,15,15,15,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,\
	0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,15,15,15,15,15,15,15,0,0,0,1,1,1,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,\
	0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,15,15,15,15,15,15,15,9,0,0,0,9,9,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,\
	1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,15,15,15,15,15,15,15,15,15,0,0,0,0,9,9,9,1,1,1,1,1,1,1,0,1,0,0,1,1,\
	1,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,15,15,15,15,15,15,15,15,15,1,0,1,0,1,9,9,1,1,1,1,1,0,1,1,1,0,1,1,0,\
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,15,15,15,15,15,15,15,15,15,0,0,9,9,9,9,9,9,1,1,1,1,1,1,1,1,1,0,1,1,\
	1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,15,15,15,15,15,15,15,15,15,0,0,1,1,9,9,9,1,9,1,1,1,1,1,0,1,1,1,1,1,\
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,15,0,15,0,15,9,9,15,0,1,9,9,1,9,9,1,1,1,1,1,1,1,1,1,0,1,1,1,\
	1,1,1,1,1,1,1,1,1,1,1,1,9,0,0,15,15,15,0,0,15,0,0,15,15,15,15,0,15,9,9,9,9,9,9,9,1,1,1,1,1,1,1,1,1,\
	1,1,1,0,1,0,1,1,1,1,1,1,0,0,15,15,15,15,15,0,15,0,0,15,15,15,15,0,0,9,9,9,9,9,9,9,9,1,1,1,1,1,1,1,1,\
	1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,15,15,0,0,0,0,0,15,0,15,0,1,1,1,9,9,9,9,9,9,9,1,1,1,1,1,1,1,\
	1,1,1,1,1,1,1,1,1,1,1,1,1,9,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,9,1,9,1,9,9,9,9,9,9,1,1,1,1,1,1,\
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,15,0,1,1,1,1,1,9,1,9,9,1,9,9,1,9,9,9,1,9,9,9,9,9,1,1,1,1,1,\
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,1,1,9,1,1,1,9,1,1,9,1,9,1,9,9,1,9,9,9,9,9,9,1,1,1,1,1,\
	1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,1,1,1,1,9,9,9,1,9,9,9,9,9,1,1,1,1,1,\
	1,1,1,1,1,1,1,1,1,9,15,9,9,9,9,9,9,15,1,1,1,9,15,1,9,9,1,9,1,1,15,9,1,9,9,9,1,9,9,9,1,1,9,1,1,\
	1,1,1,1,1,1,1,1,15,15,15,15,15,15,15,9,15,15,9,1,9,15,15,1,15,15,15,1,9,15,15,15,1,1,9,9,9,9,9,9,9,9,9,9,9,\
	1,1,1,1,1,1,1,1,1,0,1,15,15,1,0,0,15,15,0,1,9,15,15,1,9,15,15,15,15,15,15,0,1,9,1,9,1,9,9,9,9,9,9,9,9,\
	1,1,1,1,1,1,1,1,1,1,9,15,15,0,1,1,15,15,1,1,9,15,15,1,1,9,15,15,15,15,0,1,9,9,1,9,9,9,9,1,9,9,9,9,9,\
	1,1,9,9,1,1,1,1,1,9,9,15,15,1,9,9,15,15,0,1,9,15,15,1,9,1,15,15,15,1,1,9,1,9,9,1,9,9,9,9,9,9,9,9,9,\
	9,9,9,9,1,1,1,1,1,1,9,15,15,1,1,1,15,15,9,1,1,15,15,1,1,15,15,15,15,15,15,9,9,1,9,9,1,9,9,1,9,9,9,9,9,\
	9,9,9,9,9,9,9,1,1,1,1,15,15,0,1,1,15,15,15,15,15,15,15,0,15,15,15,0,9,15,15,9,1,9,9,9,9,9,9,9,9,9,9,9,9,\
	9,9,9,9,9,9,9,9,1,1,1,15,15,0,1,9,1,15,15,15,15,1,0,1,15,15,0,0,1,9,15,15,1,1,1,9,9,9,9,9,9,9,9,9,9,\
	9,9,9,9,9,9,9,9,9,9,1,1,0,1,1,1,1,1,0,1,0,0,1,9,1,1,0,1,9,1,1,0,1,9,9,9,1,9,9,9,9,9,9,9,9}

#define width 45
#define height 32
static int c[width*height]=PIC;

#define move_area_height 40
#define move_area_width 95

#define anchor_border_left 0
#define anchor_border_top 0
#define anchor_border_right (move_area_width+anchor_border_left-1)
#define anchor_border_bottom (move_area_height+anchor_border_top-1)

void
draw_tux() 
{   
	int anchor_x=0,anchor_y=0;
	cprintf("is going to prepare buffer\n");
	prepare_buffer();
	cprintf("has prepared buffer\n");

	while(1){
		int getch;
		int x,y;
		getch = getchar();
		if(getch == 'a' && anchor_x > anchor_border_left){
			anchor_x--;
		}
		else if(getch == 's' && anchor_y < anchor_border_bottom){
			anchor_y++;
		}
		else if(getch == 'd' && anchor_x < anchor_border_right){
			anchor_x++;
		}
		else if(getch == 'w' && anchor_y > anchor_border_top){
			anchor_y--;
		}
		else{
			continue;
		}
		prepare_buffer();
		for(y=0;y<height*5;y++){
			for(x=0;x<width*5;x++){
				draw_pixel(anchor_y+y,anchor_x+x,c[y/5*width+x/5]);
			}
		}
		cprintf("is going to display buffer\n");
		display_buffer();
		cprintf("displayed buffer\n");
	}
}

void 
draw_color()
{
	prepare_buffer();
	while(1){
		int getch = getchar();
		if(getch != 'a'){
			int x,y;
			for(x=0;x<256;x++){
				for(y=0;y<160;y++){
					draw_pixel(y,x,x);
				}
			}
			display_buffer();
		}
	}
}



