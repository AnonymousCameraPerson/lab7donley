#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>

//
//player::~player()
//{
//	//al_destroy_bitmap(image);
//	for (int i = 0; i < 4; i++)
//	{
//		al_destroy_bitmap(player_bmp[i]);
//	}
//}
//player::player(int HEIGHT)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		player_bmp[i] = NULL;
//	}
//}
//void player::create_player_bitmap(ALLEGRO_DISPLAY* display)
//	image = al_create_bitmap(64, 64);
//
//	if (!image) {
//		exit(1);
//	}
//
//	for (int i = 0;i < 4; i++)
//	{
//		player_bmp[i] = al_create_bitmap(32, 32);
//		if (!player_bmp[i]) {
//			exit(1);
//			al_destroy_display(display);
//
//		}
//
//		al_set_target_bitmap(player_bmp[i]);
//		al_clear_to_color(al_map_rgb(0, 0, 0));
//
//		int x = 15;
//		int y = 15;
//		al_draw_filled_rectangle(x - 10, y - 10, x + 10, y + 10, al_map_rgb(255, 255, 255));
//
//		switch (i)
//		{
//		case 0: //Up
//			al_draw_filled_triangle(x - 10, y - 10, x + 11, y - 10, x, y - 15, al_map_rgb(255, 0, 0));
//			break;
//		case 1://Right
//			al_draw_filled_triangle(x + 11, y - 11, x + 11, y + 11, x + 15, y, al_map_rgb(255, 0, 0));
//			break;
//		case 2://Down
//			al_draw_filled_triangle(x - 11, y + 11, x + 11, y + 11, x, y + 15, al_map_rgb(255, 0, 0));
//			break;
//		case 3: //Left
//			al_draw_filled_triangle(x - 11, y - 11, x - 11, y + 11, x - 15, y, al_map_rgb(255, 0, 0));
//			break;
//		}
//	}
//
//	x = 20;
//	y = HEIGHT / 2;
//
//	speed = 7;
//	boundx = al_get_bitmap_width(image);
//	boundy = al_get_bitmap_height(image);
//
//}
//void player::DrawPlayer()
//{
//
//	al_draw_bitmap(player_bmp[getDirection()], x, y, 0);
//}
//void player::MoveUp()
//{
//	y -= speed;
//	if (y < 0)
//		y = 0;
//}
//void player::MoveDown(int HEIGHT)
//{
//	y += speed;
//	if (y > HEIGHT - boundy)
//		y = HEIGHT - boundy;
//}
//void player::MoveLeft()
//{
//	x -= speed;
//	if (x < 0)
//		x = 0;
//}
//void player::MoveRight(int WIDTH)
//{
//	x += speed;
//	if (x > WIDTH - boundx)
//		x = WIDTH - boundx;
//}
//int player::getDirection()
//{
//	return dir;
//}
#include "player.h"
player::player(int HEIGHT)
{
	speed = 0;
	x = 100;
	y = 100;
	dir = 1;
	score = 0;
	for (int i = 0; i < 4; i++)
	{
		player_bmp[i] = NULL;
	}
}
player::~player()
{
	for (int i = 0; i < 4; i++)
	{
		al_destroy_bitmap(player_bmp[i]);
	}
}
void player::DrawPlayer()
{
	al_draw_bitmap(player_bmp[getDirection()], getX(), getY(), 0);
}
void player::create_player_bitmap(ALLEGRO_DISPLAY* display)
{
	for (int i = 0;i < 4; i++)
	{
		player_bmp[i] = al_create_bitmap(32, 32);
		if (!player_bmp[i]) {
			exit(1);
			al_destroy_display(display);

		}

		al_set_target_bitmap(player_bmp[i]);
		al_clear_to_color(al_map_rgb(0, 0, 0));

		int x = 15;
		int y = 15;
		al_draw_filled_rectangle(x - 10, y - 10, x + 10, y + 10, al_map_rgb(255, 255, 255));

		switch (i)
		{
		case 0: //Up
			al_draw_filled_triangle(x - 10, y - 10, x + 11, y - 10, x, y - 15, al_map_rgb(255, 0, 0));
			break;
		case 1://Right
			al_draw_filled_triangle(x + 11, y - 11, x + 11, y + 11, x + 15, y, al_map_rgb(255, 0, 0));
			break;
		case 2://Down
			al_draw_filled_triangle(x - 11, y + 11, x + 11, y + 11, x, y + 15, al_map_rgb(255, 0, 0));
			break;
		case 3: //Left
			al_draw_filled_triangle(x - 11, y - 11, x - 11, y + 11, x - 15, y, al_map_rgb(255, 0, 0));
			break;
		}
	}
}
void player::erase_player()
{

	int left = x;
	int top = y;
	int right = x + 32;
	int bottom = y + 32;

	al_draw_filled_rectangle(left, top, right, bottom, al_map_rgb(0, 0, 0));
}

void player::MoveUp()
{
	dir = 0;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;
}

void player::MoveDown(int HEIGHT)
{
	dir = 2;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;

}


void player::MoveLeft()
{
	dir = 3;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;

}

void player::MoveRight(int WIDTH)
{
	dir = 1;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;

}
int player::getDirection()
{
	return dir;
}
int player::getSpeed()
{
	return speed;
}
//int player::getX()
//{
//	return x;
//}
//int player::getY()
//{
//	return y;
//}
void player::move_player(int width, int height)
{

	//update player position based on direction
	switch (dir)
	{
	case 0:
		y -= speed;
		break;
	case 1:
		x += speed;
		break;
	case 2:
		y += speed;
		break;
	case 3:
		x -= speed;
	}

	//keep player inside the screen
	if (x > width - 32)
	{
		x = width - 32;
		speed = 0;
	}
	if (x < 0)
	{
		x = 0;
		speed = 0;
	}
	if (y > height - 32)
	{
		y = height - 32;
		speed = 0;
	}
	if (y < 0)
	{
		y = 0;
		speed = 0;
	}
}
