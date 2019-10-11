#include <iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Soldier.h"
#include "Camera.h"
#include "Ui.h"
#include "Functions.h"

using namespace std;
using namespace sf;

RenderWindow window(VideoMode(700, 700), "Strategy");

Clock clocknow;

void DrawCitys()
{
	for (auto it = ArrOfCity.begin(); it != ArrOfCity.end(); it++)
	{
		window.draw((*it).CitySprite);
		window.draw((*it).citynametext);
	}
	window.draw(cityframe);
}

void DrawUnits()
{
	for (auto it = InfantryArr.begin(); it != InfantryArr.end(); it++)
	{
		window.draw((*it).InfantryUnitSprite);
	}
	if (!ArrowArr.empty())
	{
		for (auto it = ArrowArr.begin(); it != ArrowArr.end(); it++)
		{
			if ((*it).type != "march" and (*it).type != "reatreat")
				window.draw((*it).arrowsprite);
		}
	}
}

void DrawArrows()
{
	if (!ArrowArr.empty())
	{
		for (auto it = ArrowArr.begin(); it != ArrowArr.end(); it++)
		{
			if ((*it).type == "march")
				window.draw((*it).arrowsprite);
			else if ((*it).type == "reatreat")
			{
				window.draw((*it).arrowsprite);
				window.draw((*it).arrowspritearrow);
			}
		}
	}
}

void DrawInfo()
{
	window.draw(frame);
	window.draw(bgsprite);
	window.draw(imgsprite);
	window.draw(textbg);
	window.draw(movecounter);
	window.draw(defbutton);
	window.draw(textendurance);
	window.draw(startbuttonsprite);
	window.draw(reatreatbutton);
	window.draw(personnelcounter);
	window.draw(textpersonnel);
	window.draw(textcountry);
	window.draw(unitcityimg);
	window.draw(lightunitcityimg);
	window.draw(tankunitcityimg);
	window.draw(artillerycityimg);
	window.draw(textproperty);
	window.draw(applybutton);
}

int main()
{
	view.reset(FloatRect(0, 0, 700, 700));
	Vector2i MousePosW = Mouse::getPosition(window);
	float time = 0.0;
	int NumOfUnit = -1;
	int citynum = -1;
	LoadFunc(view);
	Load_Map();
	SpawnFirstUnits();
	Map.setScale(0.7f, 0.7f);
	Vector2f Mousepos;
	while (window.isOpen())
	{
		time = float(clocknow.getElapsedTime().asMicroseconds());
		clocknow.restart();
		MousePosW = Mouse::getPosition(window);
		SetCenterOfCamera(MousePosW, time, window.getSize().x, window.getSize().y);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if(event.type == Event::MouseButtonPressed and NumOfUnit == -1)
				if(event.key.code == Mouse::Left)
				{
					Mousepos = window.mapPixelToCoords(Mouse::getPosition(window));
					cout << "X: " << Mousepos.x << " Y: " << Mousepos.y << endl;
					if (!bgsprite.getGlobalBounds().contains(Mousepos.x, Mousepos.y)) 
						NumOfUnit = ClickedSoldier(Mousepos);
					if (startbuttonsprite.getGlobalBounds().contains(Mousepos.x, Mousepos.y))
					{
						NextMove();
						NumOfUnit = -1;
						hide_city_info(view);
						HideInfoAboutUnit(view);
					}
					else if (defbutton.getGlobalBounds().contains(Mousepos.x, Mousepos.y))
						PressedButton();
					else if (reatreatbutton.getGlobalBounds().contains(Mousepos.x, Mousepos.y))
						PressedReatreatButton();
					else if (NumOfUnit != -1)
					{
						cout << "Strength: " << InfantryArr[NumOfUnit].strength << "Personnel: " << InfantryArr[NumOfUnit].personnel << endl;
						cout << "Support strength: " << InfantryArr[NumOfUnit].supportstrength << "Suppnum: " << InfantryArr[NumOfUnit].supportunits.size() << endl;
						SetActiveTextureForUnit(NumOfUnit);
						hide_city_info(view);
						ShowInfoAboutUnit(NumOfUnit ,view);
					}
					else
					{
						if (!bgsprite.getGlobalBounds().contains(Mousepos.x, Mousepos.y))
							citynum = selected_city(Mousepos);
						if (citynum != -1 and numofcitynow == -1)
						{
							cityframe.setPosition((float)ArrOfCity[citynum].GetPosition().x,
								(float)ArrOfCity[citynum].GetPosition().y);
							show_city_info(view, citynum);
						}
						else if (bgsprite.getGlobalBounds().contains(Mousepos.x, Mousepos.y) and numofcitynow != -1)
						{
							check_city_info(Mousepos);
						}
						else if (numofcitynow != -1)
						{
							cityframe.setPosition(1000, 1000);
							hide_city_info(view);
							citynum = -1;
						}
						else if (!bgsprite.getGlobalBounds().contains(Mousepos.x, Mousepos.y))
							HideInfoAboutUnit(view);
						ResetTexturesForAllUnits(); //восстанавливаем текстуры и тексты у юнитов
						CheckCitysInCountry();
					}
				}
			if(event.type == Event::MouseButtonReleased and NumOfUnit != -1)
				if(event.key.code == Mouse::Left)
				{
					Mousepos = window.mapPixelToCoords(Mouse::getPosition(window));
					int NumOfCity = ClickedCity(Mousepos, InfantryArr[NumOfUnit].CityNow);
					if (NumOfCity != -1 and NumOfUnit != -1) InfantryArr[NumOfUnit].Move(NumOfCity);
					if (active == 1) active++; //из int в bool нужно перевести, иначе бесполезно это всё
					else if (active == 2)
						HideInfoAboutUnit(view);
					ResetTexturesForAllUnits();
					ShowInfoAboutUnit(NumOfUnit, view);
					NumOfUnit = -1;
				}

			if (numofcitynow != -1)
				move_city_info(view);

			if(event.type == Event::MouseWheelMoved)
			{
				ScrollCamera(event.mouseWheel.delta);
			}

			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Tab)
			{
				countrymapsprite.setPosition(0, 0);
			}
			if (event.type == Event::KeyReleased)
				if(event.key.code == Keyboard::Tab)
			{
				countrymapsprite.setPosition(1000, 1000);
			}
			if (event.type == Event::KeyReleased)
				if (event.key.code == Keyboard::C)
				{
					cin >> playercountry;
				}
		}
		window.setView(view);
		window.clear();
		window.draw(Map);
		DrawArrows();
		DrawCitys();
		DrawUnits();
		DrawInfo();
		window.draw(countrymapsprite);
		window.display();
	}
	//нужно будет вытащить из Functions.h все функции для работы с интерфейсом
	//и поместить их в отдельный ui.h (*) + сделать адекватный доступ в классах +
	//переименовать все переменные на прописные буквы + добавить нужные функции
	//может, всю сортировочную работу поместить в sort.h
	//на каждый ход нужно сортировать вектор юнитов и их номера (*)
	//нужно сделать так, чтобы через бэкграунд не выделялись юниты и города (*)
	//теперь нельзя взаимодействовать с юнитами и гордами сквозь интерфейс города и юнита, НО
	//интерфейс юнита убирается при нажатии на него и я не могу найти где (*)
	return 0;
}