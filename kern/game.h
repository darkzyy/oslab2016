#ifndef _GAME_H_
#define _GAME_H_

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

extern struct pos protag, box[3];

#endif /*_GAME_H_*/
