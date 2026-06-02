#ifndef PLAYERH
#define PLAYERH
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

class player
{
public:
	//player(int HEIGHT);
	player();
	~player();
	//void DrawPlayer(int flag);
	void MoveUp();
	void MoveDown(int HEIGHT);
	void MoveLeft();
	void MoveRight(int WIDTH);
	int getBoundX() { return boundx; }
	int getBoundY() { return boundy; }
	int getX() { return x; }
	int getY() { return y; }
	int getDirection();
	int getSpeed();
	void drawArrow();
	void create_arrow_bitmap(ALLEGRO_DISPLAY* display);
	void move_arrow(int width, int height);
private:
	int x;
	int y;
	int speed, dir;
	int boundx;
	int boundy;
	ALLEGRO_BITMAP* arrow_bmp[4];
	ALLEGRO_BITMAP* image;
	
};
#endif

