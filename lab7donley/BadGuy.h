#ifndef BADGUYH
#define BADGUYH
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <array>

class BadGuy
{
public:
	BadGuy();
	~BadGuy();
	void DrawBadGuy();
	void StartBadGuy(int WIDTH, int HEIGHT);
	int getBoundX() { return boundx; }
	int getBoundY() { return boundy; }
	int getX() { return x; }
	int getY() { return y; }
	bool getLive() { return live; }
	void setLive(bool l) { live = l; }
private:
	int x;
	int y;
	bool live;
	int speed;
	int boundx;
	int boundy;
	int boundings[5][5];
	ALLEGRO_BITMAP* image;
};

#endif