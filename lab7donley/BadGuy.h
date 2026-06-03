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
	void StartBadGuy(int WIDTH, int HEIGHT, const BadGuy BadGuys[], int NUM_BadGuyS);
	int getBoundX() { return boundx; }
	int getBoundY() { return boundy; }
	int getX() const { return x; }
	int getY() const { return y; }
	bool getLive() const { return live; }
	void setLive(bool l) { live = l; }
private:
	int x;
	int y;
	bool live;
	int speed;
	int boundx;
	int boundy;
	int NUM;
	ALLEGRO_BITMAP* image;
};

#endif