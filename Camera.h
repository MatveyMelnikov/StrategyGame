#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "Ui.h"
#include "Functions.h"
using namespace std;
using namespace sf;

View view;

int step = 5;
int scale = 0;

void SetCenterOfCamera(Vector2i mousepos, float time, int winx, int winy)
{
	if(mousepos.x < winx / 25)
		view.move(float(-0.001 * time), (float)0);
	if(mousepos.x > winx - winx / 25)
		view.move(float(0.001 * time), (float)0);
	if(mousepos.y < winy / 25)
		view.move((float)0, float(-0.001 * time));
	if(mousepos.y > winy - winy / 25)
		view.move((float)0, float(0.001 * time));
	if (step == 5)
	{
		view.setCenter((float)350, (float)350);
		view.setSize((float)700, (float)700);
	}
	else
	{
		if (view.getCenter().x - (view.getSize().x / 2) < 0)
			view.setCenter((view.getSize().x / 2) + 1, view.getCenter().y);

		if (view.getCenter().x + (view.getSize().x / 2) > 700)
			view.setCenter((700 - view.getSize().x / 2) - 1, view.getCenter().y);

		if (view.getCenter().y - (view.getSize().y / 2) < 0)
			view.setCenter(view.getCenter().x, (view.getSize().y / 2) + 1);

		if (view.getCenter().y + (view.getSize().y / 2) > 700)
			view.setCenter(view.getCenter().x, (700 - view.getSize().y / 2) - 1);
	}
	if (numofcitynow == -1) MoveInfoAboutUnit(view);
	else move_city_info(view);
	startbuttonsprite.setPosition(GetBgPos(612, view, 1), GetBgPos(10, view, 0));
}

void ScrollCamera(int delta)
{
	if (delta == -1 and step < 5)
	{
		view.zoom(1.05f);
		step++;
		scale--;
	}
	else if (delta == 1 and step > -5)
	{
		view.zoom(0.95f);
		step--;
		scale++;
	}
	if (numofcitynow == -1) MoveInfoAboutUnit(view);
	else move_city_info(view);
	startbuttonsprite.setScale(view.getSize().x / DefViewSize.x, view.getSize().y / DefViewSize.y);
	startbuttonsprite.setPosition(GetBgPos(612, view, 1), GetBgPos(10, view, 0));
	cout << step << endl;
} 
