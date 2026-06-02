#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "player.h"

//player::~player()
//{
//	al_destroy_bitmap(image);
//}
player::player()
{
	speed = 0;
	dir = 1;
	for (int i = 0; i < 4; i++)
	{
		arrow_bmp[i] = NULL;
	}

	x = 20;
	y = 20;

	speed = 7;
	boundx = 32;
	boundy = 32;
	//boundx = al_get_bitmap_width(image);
	//boundy = al_get_bitmap_height(image);

}
player::~player()
{
	for (int i = 0; i < 4; i++)
	{
		al_destroy_bitmap(arrow_bmp[i]);
	}
}
//player::player(int HEIGHT)
//{
//
//	image = al_create_bitmap(64, 64);
//	if (!image) {
//		exit(1);
//	}
//
//	al_set_target_bitmap(image);
//	al_clear_to_color(al_map_rgb(0, 0, 0));
//
//	al_draw_filled_rectangle(0, 25, 64, 39, al_map_rgb(75, 75, 75));
//	al_draw_filled_rectangle(25, 0, 39, 64, al_map_rgb(50, 50, 50));
//	al_draw_circle(32, 32, 8, al_map_rgb(0, 0, 0), 5);
//
//	al_draw_line(0, 32, 64, 32, al_map_rgb(255, 100, 255), 2);
//	al_draw_line(32, 0, 32, 64, al_map_rgb(255, 100, 255), 2);
//	al_draw_circle(32, 32, 16, al_map_rgb(200, 200, 200), 5);
//	al_draw_triangle(32, 0, 0, 64, 64, 64, al_map_rgb(255, 255, 255), 5);
//
//
//
//	x = 20;
//	y = HEIGHT / 2;
//
//	speed = 7;
//	boundx = al_get_bitmap_width(image);
//	boundy = al_get_bitmap_height(image);
//
//}
//void player::DrawPlayer(int flag)
//{
//	int cx = al_get_bitmap_width(image) / 2;
//	int cy = al_get_bitmap_height(image) / 2;
//	if (flag == 3)
//		al_draw_rotated_bitmap(image, cx, cy, x, y, -ALLEGRO_PI / 2, 0);
//	else if (flag == 4)
//		al_draw_rotated_bitmap(image, cx, cy, x, y, ALLEGRO_PI / 2, 0);
//	else
//		al_draw_bitmap(image, x, y, flag);
//}
void player::MoveUp()
{
	y -= speed;
	if (y < 0)
		y = 0;
}
void player::MoveDown(int HEIGHT)
{
	y += speed;
	if (y > HEIGHT - boundy)
		y = HEIGHT - boundy;
}
void player::MoveLeft()
{
	x -= speed;
	if (x < 0)
		x = 0;
}

void player::MoveRight(int WIDTH)
{
	x += speed;
	if (x > WIDTH - boundx)
		x = WIDTH - boundx;
	
}


void player::drawArrow()
{
	al_draw_bitmap(arrow_bmp[getDirection()], getX(), getY(), 0);
}
void player::create_arrow_bitmap(ALLEGRO_DISPLAY* display)
{
	for (int i = 0;i < 4; i++)
	{
		arrow_bmp[i] = al_create_bitmap(32, 32);
		
		if (!arrow_bmp[i]) {
			exit(1);
			al_destroy_display(display);

		}

		al_set_target_bitmap(arrow_bmp[i]);
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
int player::getDirection()
{
	return dir;
}

int player::getSpeed()
{
	return speed;
}

void player::move_arrow(int width, int height)
{

	//update arrow position based on direction
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

	//keep arrow inside the screen
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
