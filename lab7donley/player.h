#ifndef PLAYERH
#define PLAYERH
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#define MAXSPEED 3
class player
{
public:
	player(int HEIGHT);
	~player();
	void DrawPlayer();
	void MoveUp();
	void MoveDown(int HEIGHT);
	void create_player_bitmap(ALLEGRO_DISPLAY* display);
	void erase_player();
	void MoveLeft();
	void MoveRight(int WIDTH);
	int getSpeed();
	void move_player(int width, int height);
	int getDirection();
	int getBoundX() { return boundx; }
	int getBoundY() { return boundy; }
	int getX() { return x; }
	int getY() { return y; }
private:
	int x;
	int y;
	int score;
	int boundx;
	int boundy;
	int dir, speed;
	ALLEGRO_BITMAP* player_bmp[4];
	ALLEGRO_BITMAP* image;
};
#endif

