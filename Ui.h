#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "Soldier.h"
#include "Functions.h"
using namespace std;
using namespace sf;

Sprite bgsprite;
Texture bgtexture;
Vector2f DefViewSize;

Sprite imgsprite;
Texture imgtexture;

Text textbg;
Text textproperty;

Text textendurance;

Sprite movecounter;
Texture movecountertexture;

Sprite defbutton;
Texture defbuttontexture;

Sprite startbuttonsprite;
Texture startbuttontexture;

Sprite reatreatbutton;
Texture reatreattexture;

Text textpersonnel;
Text textcountry;

Sprite personnelcounter;
Texture personnelcountertexture;

Sprite unitcityimg;
Texture unitcityimgtexture;
Sprite lightunitcityimg;
Texture lightunitcityimgtexture;
Sprite tankunitcityimg;
Texture tankunitcityimgtexture;
Sprite artillerycityimg;
Texture artillerycityimgtexture;

Sprite applybutton;
Texture applybuttontexture;

int NumOfUnitNow = 0;
int numofcitynow = -1;
int active = 0;
int selectedunit = 0;

void CheckCounter(int NumOfUnit)
{
	if(InfantryArr[NumOfUnit].type == "artillery")
	{
		switch (InfantryArr[NumOfUnit].numofmoves)
		{
		case 2:
			movecountertexture.loadFromFile("img/artmovecounter.jpg");
			break;
		case 1:
			movecountertexture.loadFromFile("img/artmovecounter1.jpg");
			break;
		default:
			movecountertexture.loadFromFile("img/movecounter3.jpg");
			break;
		}
	}
	else if (InfantryArr[NumOfUnit].type == "light infantry")
	{
		switch (InfantryArr[NumOfUnit].numofmoves)
		{
		case 4:
			movecountertexture.loadFromFile("img/lightmovecounter.jpg");
			break;
		case 3:
			movecountertexture.loadFromFile("img/lightmovecounter1.jpg");
			break;
		case 2:
			movecountertexture.loadFromFile("img/lightmovecounter2.jpg");
			break;
		case 1:
			movecountertexture.loadFromFile("img/lightmovecounter3.jpg");
			break;
		default:
			movecountertexture.loadFromFile("img/movecounter3.jpg");
			break;
		}
	}
	else
	{
		switch (InfantryArr[NumOfUnit].numofmoves)
		{
		case 3:
			movecountertexture.loadFromFile("img/movecounter.jpg");
			break;
		case 2:
			movecountertexture.loadFromFile("img/movecounter1.jpg");
			break;
		case 1:
			movecountertexture.loadFromFile("img/movecounter2.jpg");
			break;
		default:
			movecountertexture.loadFromFile("img/movecounter3.jpg");
			break;
		}
	}
	//////////////////////
	switch (InfantryArr[NumOfUnit].personnel)
	{
	case 10:
		personnelcountertexture.loadFromFile("img/counterpersonnel/counterpersonnel.jpg");
		break;
	case 9:
		personnelcountertexture.loadFromFile("img/counterpersonnel/counterpersonnel1.jpg");
		break;
	case 8:
		personnelcountertexture.loadFromFile("img/counterpersonnel/counterpersonnel2.jpg");
		break;
	case 7:
		personnelcountertexture.loadFromFile("img/counterpersonnel/counterpersonnel3.jpg");
		break;
	case 6:
		personnelcountertexture.loadFromFile("img/counterpersonnel/counterpersonnel4.jpg");
		break;
	case 5:
		personnelcountertexture.loadFromFile("img/counterpersonnel/counterpersonnel5.jpg");
		break;
	case 4:
		personnelcountertexture.loadFromFile("img/counterpersonnel/counterpersonnel6.jpg");
		break;
	case 3:
		personnelcountertexture.loadFromFile("img/counterpersonnel/counterpersonnel7.jpg");
		break;
	case 2:
		personnelcountertexture.loadFromFile("img/counterpersonnel/counterpersonnel8.jpg");
		break;
	case 1:
		personnelcountertexture.loadFromFile("img/counterpersonnel/counterpersonnel9.jpg");
		break;
	}
}

float GetBgPos(float deviation, View view, bool isitx)
{
	if (isitx)
		return (view.getCenter().x - view.getSize().x / 2) + deviation * (view.getSize().x / DefViewSize.x);
	else
		return (view.getCenter().y - view.getSize().y / 2) + deviation * (view.getSize().y / DefViewSize.y);
}

void ScaleCameraObjects(View view)
{
	bgsprite.setScale(view.getSize().x / DefViewSize.x, view.getSize().y / DefViewSize.y);
	imgsprite.setScale(view.getSize().x / DefViewSize.x, view.getSize().y / DefViewSize.y);
	textbg.setScale(view.getSize().x / DefViewSize.x, view.getSize().y / DefViewSize.y);
	textendurance.setScale(view.getSize().x / DefViewSize.x, view.getSize().y / DefViewSize.y);
	movecounter.setScale(view.getSize().x / DefViewSize.x, view.getSize().y / DefViewSize.y);
	defbutton.setScale(view.getSize().x / DefViewSize.x, view.getSize().y / DefViewSize.y);
	reatreatbutton.setScale(view.getSize().x / DefViewSize.x, view.getSize().y / DefViewSize.y);
	startbuttonsprite.setScale(view.getSize().x / DefViewSize.x, view.getSize().y / DefViewSize.y);
	personnelcounter.setScale(view.getSize().x / DefViewSize.x, view.getSize().y / DefViewSize.y);
	textpersonnel.setScale(view.getSize().x / DefViewSize.x, view.getSize().y / DefViewSize.y);
	textcountry.setScale(view.getSize().x / DefViewSize.x, view.getSize().y / DefViewSize.y);
	unitcityimg.setScale(view.getSize().x / DefViewSize.x, view.getSize().y / DefViewSize.y);
	lightunitcityimg.setScale(view.getSize().x / DefViewSize.x, view.getSize().y / DefViewSize.y);
	tankunitcityimg.setScale(view.getSize().x / DefViewSize.x, view.getSize().y / DefViewSize.y);
	artillerycityimg.setScale(view.getSize().x / DefViewSize.x, view.getSize().y / DefViewSize.y);
	textproperty.setScale(view.getSize().x / DefViewSize.x, view.getSize().y / DefViewSize.y);
	applybutton.setScale(view.getSize().x / DefViewSize.x, view.getSize().y / DefViewSize.y);
}

void PressedButton()
{
	if (InfantryArr[NumOfUnitNow].type == "tank")
	{
		defbuttontexture.loadFromFile("img/defbuttonactive.jpg");
		return;
	}
	else if (InfantryArr[NumOfUnitNow].reatreat or InfantryArr[NumOfUnitNow].supportto != -1)
		return;
	if (InfantryArr[NumOfUnitNow].get_status() == 0 and InfantryArr[NumOfUnitNow].numofmoves > 0)
	{
		defbuttontexture.loadFromFile("img/defbuttonactive.jpg");
		InfantryArr[NumOfUnitNow].defensive_position();
		if (InfantryArr[NumOfUnitNow].type == "infantry")
		{
			SetTexture(NumOfUnitNow, InfantryUnitTexturedef, EnemyInfantryUnitTexturedef,
				NeutralInfantryUnitTexturedef);
		}
		else if (InfantryArr[NumOfUnitNow].type == "guard")
		{
			SetTexture(NumOfUnitNow, GuardInfantryUnitTexturedef,
				EnemyGuardInfantryUnitTexturedef, NeutralGuardInfantryUnitTexturedef);
		}
		else if (InfantryArr[NumOfUnitNow].type == "artillery")
		{
			SetTexture(NumOfUnitNow, ArtilleryUnitTexturedef,
				EnemyArtilleryUnitTexturedef, NeutralArtilleryUnitTexturedef);
		}
		else if (InfantryArr[NumOfUnitNow].type == "light infantry")
		{
			SetTexture(NumOfUnitNow, LightInfantryTexturedef,
				EnemyLightInfantryTexturedef, NeutralLightInfantryTexturedef);
		}
	}
	else if (InfantryArr[NumOfUnitNow].get_status() == 1)
	{
		defbuttontexture.loadFromFile("img/defbutton.jpg");
		InfantryArr[NumOfUnitNow].stowed_condition();
		if (InfantryArr[NumOfUnitNow].type == "infantry")
			SetTexture(NumOfUnitNow, InfantryUnitTexture, EnemyInfantryUnitTexture, NeutralInfantryUnitTexture);
		else if (InfantryArr[NumOfUnitNow].type == "guard")
		{
			SetTexture(NumOfUnitNow, GuardInfantryUnitTexture,
				EnemyGuardInfantryUnitTexture, NeutralGuardInfantryUnitTexture);
		}
		else if (InfantryArr[NumOfUnitNow].type == "artillery")
		{
			SetTexture(NumOfUnitNow, ArtilleryUnitTexture,
				EnemyArtilleryUnitTexture, NeutralArtilleryUnitTexture);
		}
		else if (InfantryArr[NumOfUnitNow].type == "light infantry")
		{
			SetTexture(NumOfUnitNow, LightInfantryTexture,
				EnemyLightInfantryTexture, NeutralLightInfantryTexture);
		}
	}
}

void CheckButton()
{
	if (InfantryArr[NumOfUnitNow].type == "tank")
	{
		defbuttontexture.loadFromFile("img/defbuttonactive.jpg");
	}
	else if (InfantryArr[NumOfUnitNow].get_status() == 1)
	{
		defbuttontexture.loadFromFile("img/defbuttonactive.jpg");
	}
	else
	{
		defbuttontexture.loadFromFile("img/defbutton.jpg");
	}
	if (!InfantryArr[NumOfUnitNow].reatreat)
	{
		reatreattexture.loadFromFile("img/reatreatbutton.jpg");
	}
	else if (InfantryArr[NumOfUnitNow].reatreat)
	{
		reatreattexture.loadFromFile("img/defbuttonactive.jpg");
	}
}

void NextMove()
{
	for (auto it = InfantryArr.begin(); it != InfantryArr.end(); it++)
	{
		if (it->type=="artillery")
			it->numofmoves = 2;
		else if (it->type == "light infantry")
			it->numofmoves = 4;
		else
			it->numofmoves = 3;
		it->CaptureCity();
		if(it->attackedunit != -1 and InfantryArr[it->attackedunit].supportto != -1) //с приоритетами проблема
			it->Attack();
	}
	for (auto it = InfantryArr.begin(); it != InfantryArr.end(); it++)
		if (it->attackedunit != -1 and InfantryArr[it->attackedunit].supportto == -1)
			it->Attack();
	for (auto it = InfantryArr.begin(); it != InfantryArr.end(); it++)
	{
		if (ArrOfCity[it->containedcity].country != it->MyCountry)
			it->steptodisbandment += 1;
		else
			it->steptodisbandment = 0;
	}
	for (auto it = InfantryArr.begin(); it != InfantryArr.end();)
	{
		if (it->dead or it->steptodisbandment == 3)
		{
			ArrOfCity[it->CityNow].change_unit_in_city(-1);
			ArrOfCity[it->containedcity].containedunit = 0;
			it = InfantryArr.erase(it);
		}
		else it++;
	}
	for (unsigned int i = 0; i < InfantryArr.size(); i++)
	{
		auto unit = InfantryArr.begin() + i;
		unit->numofunit = i;
		ArrOfCity[unit->CityNow].change_unit_in_city(i);
		unit->set_reatreat_city(-1);
		unit->reatreatarrownum = -1;
		unit->reatreat = 0;
		unit->attackedunit = -1;
		unit->supportstrength = 0;
		unit->supportto = -1;
		unit->supportunits.clear();
		if (unit->personnel < 10)
			unit->steptoheal += 1;
		if (unit->steptoheal == 2)
		{
			unit->steptoheal = 0;
			unit->personnel += 1;
			unit->stockstrength = calculate_stock_strength(unit->startstrength, unit->personnel);
			unit->strength = calculate_strength(unit->stockstrength, unit->get_status(), unit->type);
		} 
	}
	CheckCitysInCountry();
	ArrowArr.clear();
}

void PressedReatreatButton()
{
	if (!InfantryArr[NumOfUnitNow].reatreat)
	{
		reatreattexture.loadFromFile("img/defbuttonactive.jpg");
		InfantryArr[NumOfUnitNow].reatreat = 1;
	}
	else if (InfantryArr[NumOfUnitNow].reatreat and InfantryArr[NumOfUnitNow].reatreatarrownum != -1)
	{
		reatreattexture.loadFromFile("img/reatreatbutton.jpg");
		InfantryArr[NumOfUnitNow].reatreat = 0;
		InfantryArr[NumOfUnitNow].set_reatreat_city(-1);
		ArrowArr.erase(ArrowArr.begin() + InfantryArr[NumOfUnitNow].reatreatarrownum);
		InfantryArr[NumOfUnitNow].reatreatarrownum = -1;
	}
}

void ShowInfoAboutUnit(int numofunit, View view)
{
	ScaleCameraObjects(view);

	bgsprite.setPosition(view.getCenter().x - view.getSize().x / 2,
		view.getCenter().y - view.getSize().y / 2);
	active++;

	if (InfantryArr[numofunit].type == "infantry") imgtexture.loadFromFile("img/unitimg.jpg");
	else if (InfantryArr[numofunit].type == "guard") imgtexture.loadFromFile("img/guardunitimg.jpg");
	else if (InfantryArr[numofunit].type == "tank") imgtexture.loadFromFile("img/tankunitimg.jpg");
	else if (InfantryArr[numofunit].type == "artillery") imgtexture.loadFromFile("img/artilleryunitimg.jpg");
	else if (InfantryArr[numofunit].type == "light infantry") imgtexture.loadFromFile("img/lightunitimg.jpg");
	imgsprite.setPosition(GetBgPos(10, view, 1),
		GetBgPos(10, view, 0));

	textbg.setString(InfantryArr[numofunit].name);
	textbg.setPosition(GetBgPos(10, view, 1), GetBgPos(120, view, 0));


	textendurance.setPosition(GetBgPos(118, view, 1), GetBgPos(53, view, 0));

	NumOfUnitNow = numofunit;
	CheckButton();
	CheckCounter(NumOfUnitNow);
	movecounter.setPosition(GetBgPos(118, view, 1), GetBgPos(69, view, 0));

	defbutton.setPosition(GetBgPos(200, view, 1), GetBgPos(10, view, 0));

	startbuttonsprite.setPosition(GetBgPos(612, view, 1), GetBgPos(10, view, 0));

	reatreatbutton.setPosition(GetBgPos(118, view, 1), GetBgPos(10, view, 0));

	personnelcounter.setPosition(GetBgPos(118, view, 1), GetBgPos(101, view, 0));

	textpersonnel.setPosition(GetBgPos(118, view, 1), GetBgPos(85, view, 0));

	textcountry.setString(InfantryArr[numofunit].MyCountry);
	textcountry.setPosition(GetBgPos(10, view, 1), GetBgPos(95, view, 0));
}

void HideInfoAboutUnit(View view)
{
	bgsprite.setPosition(1000, 1000);
	imgsprite.setPosition(1000, 1000);
	textbg.setPosition(1000, 1000);
	textendurance.setPosition(1000, 1000);
	movecounter.setPosition(1000, 100);
	defbutton.setPosition(1000, 1000);
	reatreatbutton.setPosition(1000, 1000);
	personnelcounter.setPosition(1000, 1000);
	textpersonnel.setPosition(1000, 1000);
	textcountry.setPosition(1000, 1000);
	unitcityimg.setPosition(1000, 1000);
	lightunitcityimg.setPosition(1000, 1000);
	tankunitcityimg.setPosition(1000, 1000);
	artillerycityimg.setPosition(1000, 1000);
	active = 0;
}

void MoveInfoAboutUnit(View view)
{
	if (active == 0) return;

	ScaleCameraObjects(view);

	bgsprite.setPosition(view.getCenter().x - view.getSize().x / 2,
		view.getCenter().y - view.getSize().y / 2);
	imgsprite.setPosition(GetBgPos(10, view, 1), GetBgPos(10, view, 0));
	textbg.setPosition(GetBgPos(10, view, 1), GetBgPos(120, view, 0));
	textendurance.setPosition(GetBgPos(118, view, 1), GetBgPos(53, view, 0));
	CheckCounter(NumOfUnitNow);
	movecounter.setPosition(GetBgPos(118, view, 1), GetBgPos(69, view, 0));
	defbutton.setPosition(GetBgPos(200, view, 1), GetBgPos(10, view, 0));
	startbuttonsprite.setPosition(GetBgPos(612, view, 1), GetBgPos(10, view, 0));
	reatreatbutton.setPosition(GetBgPos(118, view, 1), GetBgPos(10, view, 0));
	textpersonnel.setPosition(GetBgPos(118, view, 1), GetBgPos(85, view, 0));
	textcountry.setPosition(GetBgPos(10, view, 1), GetBgPos(95, view, 0));
	personnelcounter.setPosition(GetBgPos(118, view, 1), GetBgPos(101, view, 0));
}

void reset_all_icons()
{
	unitcityimgtexture.loadFromFile("img/cityicons/unitcityimg.jpg");
	lightunitcityimgtexture.loadFromFile("img/cityicons/lightunitcityimg.jpg");
	tankunitcityimgtexture.loadFromFile("img/cityicons/tankunitcityimg.jpg");
	artillerycityimgtexture.loadFromFile("img/cityicons/artillerycityimg.jpg");
	applybuttontexture.loadFromFile("img/cityicons/applybutton.jpg");
}

void show_city_info(View view, int citynum)
{
	numofcitynow = citynum;
	HideInfoAboutUnit(view);
	reset_all_icons();
	unitcityimg.setPosition(GetBgPos(11, view, 1), GetBgPos(40, view, 0));
	lightunitcityimg.setPosition(GetBgPos(74, view, 1), GetBgPos(40, view, 0));
	tankunitcityimg.setPosition(GetBgPos(137, view, 1), GetBgPos(40, view, 0));
	artillerycityimg.setPosition(GetBgPos(200, view, 1), GetBgPos(40, view, 0));
	textcountry.setString(ArrOfCity[numofcitynow].country);
	textcountry.setPosition(GetBgPos(10, view, 1), GetBgPos(10, view, 0));

	if (selectedunit == 0) textbg.setString("|  0.0  |  0.0  |  0.0  |  0.0  |");
	textbg.setCharacterSize(23);
	textbg.setPosition(GetBgPos(17, view, 1), GetBgPos(85, view, 0));

	textproperty.setString("   Str       Def      Supp   Steps");
	textproperty.setCharacterSize(17);
	textproperty.setPosition(GetBgPos(17, view, 1), GetBgPos(110, view, 0));

	if (ArrOfCity[citynum].country != playercountry or ArrOfCity[citynum].get_unit_in_city() != -1
		or ArrOfCity[citynum].containedunit == 1)
		applybuttontexture.loadFromFile("img/cityicons/applybuttonactive.jpg");
	applybutton.setPosition(GetBgPos(137, view, 1), GetBgPos(15, view, 0));

	bgsprite.setPosition((view.getCenter().x - view.getSize().x / 2),
		(view.getCenter().y - view.getSize().y / 2));
	ScaleCameraObjects(view);
}

void move_city_info(View view)
{
	unitcityimg.setPosition(GetBgPos(11, view, 1), GetBgPos(40, view, 0));
	lightunitcityimg.setPosition(GetBgPos(74, view, 1), GetBgPos(40, view, 0));
	tankunitcityimg.setPosition(GetBgPos(137, view, 1), GetBgPos(40, view, 0));
	artillerycityimg.setPosition(GetBgPos(200, view, 1), GetBgPos(40, view, 0));
	textcountry.setPosition(GetBgPos(10, view, 1), GetBgPos(10, view, 0));
	textbg.setPosition(GetBgPos(17, view, 1), GetBgPos(85, view, 0));
	textproperty.setPosition(GetBgPos(17, view, 1), GetBgPos(110, view, 0));
	applybutton.setPosition(GetBgPos(137, view, 1), GetBgPos(15, view, 0));
	bgsprite.setPosition((view.getCenter().x - view.getSize().x / 2),
		(view.getCenter().y - view.getSize().y / 2));
	ScaleCameraObjects(view);
}

void hide_city_info(View view)
{
	numofcitynow = -1;
	selectedunit = 0;
	//HideInfoAboutUnit(view);

	bgsprite.setPosition(1000, 1000);
	textbg.setPosition(1000, 1000);
	textcountry.setPosition(1000, 1000);

	cityframe.setPosition(1000, 1000);
	unitcityimg.setPosition(1000, 1000);
	lightunitcityimg.setPosition(1000, 1000);
	tankunitcityimg.setPosition(1000, 1000);
	artillerycityimg.setPosition(1000, 1000);
	textproperty.setPosition(1000, 1000);
	textbg.setCharacterSize(17);
	applybutton.setPosition(1000, 1000);
}

void check_city_info(Vector2f mousepos)
{
	reset_all_icons();
	if (unitcityimg.getGlobalBounds().contains(mousepos.x, mousepos.y))
	{
		unitcityimgtexture.loadFromFile("img/cityicons/activeicon.jpg");
		textbg.setString("|  1.0  |  1.5  |  0.5  |  3.0  |");
		selectedunit = 1;
	}
	else if (lightunitcityimg.getGlobalBounds().contains(mousepos.x, mousepos.y))
	{
		lightunitcityimgtexture.loadFromFile("img/cityicons/activeicon.jpg");
		textbg.setString("|  0.7  |  1.0  |  0.5  |  4.0  |");
		selectedunit = 2;
	}
	else if (tankunitcityimg.getGlobalBounds().contains(mousepos.x, mousepos.y))
	{
		tankunitcityimgtexture.loadFromFile("img/cityicons/activeicon.jpg");
		textbg.setString("|  1.7  |  0.0  |  0.5  |  3.0  |");
		selectedunit = 3;
	}
	else if (artillerycityimg.getGlobalBounds().contains(mousepos.x, mousepos.y))
	{
		artillerycityimgtexture.loadFromFile("img/cityicons/activeicon.jpg");
		textbg.setString("|  0.5  |  1.0  |  1.0  |  2.0  |");
		selectedunit = 4;
	}
	else if (applybutton.getGlobalBounds().contains(mousepos.x, mousepos.y) and selectedunit != 0 and
		ArrOfCity[numofcitynow].country == playercountry and ArrOfCity[numofcitynow].get_unit_in_city() == -1 and
		ArrOfCity[numofcitynow].containedunit == 0)
	{
		if (selectedunit == 1) Unit newunit(numofcitynow, "infantry");
		else if (selectedunit == 2) Unit newunit(numofcitynow, "light infantry");
		else if (selectedunit == 3) Unit newunit(numofcitynow, "tank");
		else Unit newunit(numofcitynow, "artillery");
	}
	else
	{
		reset_all_icons();
		selectedunit = 0;
	}
	if (ArrOfCity[numofcitynow].country != playercountry or ArrOfCity[numofcitynow].get_unit_in_city() != -1
		or ArrOfCity[numofcitynow].containedunit == 1)
		applybuttontexture.loadFromFile("img/cityicons/applybuttonactive.jpg");
}

void LoadFunc(View view)
{
	DefViewSize.x = view.getSize().x;
	DefViewSize.y = view.getSize().y;

	bgtexture.loadFromFile("img/background1.jpg");
	bgsprite.setTexture(bgtexture);
	bgsprite.setPosition(1000, 1000);

	imgtexture.loadFromFile("img/unitimg.jpg");
	imgsprite.setTexture(imgtexture);
	imgsprite.setPosition(1000, 1000);

	textbg.setString(" ");
	textbg.setFont(unitsfont);
	textbg.setCharacterSize(17);
	textbg.setPosition(1000, 1000);
	textbg.setFillColor(Color(169, 169, 169));

	textendurance.setString(" ");
	textendurance.setFont(unitsfont);
	textendurance.setCharacterSize(13);
	textendurance.setPosition(1000, 1000);
	textendurance.setFillColor(Color(173, 216, 230));
	textendurance.setString("Endurance:");

	textcountry.setString(" ");
	textcountry.setFont(unitsfont);
	textcountry.setCharacterSize(17);
	textcountry.setPosition(1000, 1000);
	textcountry.setFillColor(Color(169, 169, 169));

	reatreattexture.loadFromFile("img/reatreatbutton.jpg");
	reatreatbutton.setTexture(reatreattexture);
	reatreatbutton.setPosition(1000, 1000);

	movecountertexture.loadFromFile("img/movecounter.jpg");
	movecounter.setTexture(movecountertexture);
	movecounter.setPosition(1000, 1000);

	defbuttontexture.loadFromFile("img/defbutton.jpg");
	defbutton.setTexture(defbuttontexture);
	defbutton.setPosition(1000, 1000);

	startbuttontexture.loadFromFile("img/startbutton.jpg");
	startbuttonsprite.setTexture(startbuttontexture);
	startbuttonsprite.setPosition(1000, 1000);
	//
	textpersonnel.setString(" ");
	textpersonnel.setFont(unitsfont);
	textpersonnel.setCharacterSize(13);
	textpersonnel.setPosition(1000, 1000);
	textpersonnel.setFillColor(Color(173, 216, 230));
	textpersonnel.setString("Personnel:");

	textproperty.setString(" ");
	textproperty.setFont(unitsfont);
	textproperty.setCharacterSize(17);
	textproperty.setPosition(1000, 1000);
	textproperty.setFillColor(Color(169, 169, 169));

	set_texture(unitcityimgtexture, "img/cityicons/unitcityimg.jpg");
	set_sprite(unitcityimg, unitcityimgtexture, Vector2i(1000, 1000), Vector2f(0, 0), Vector2f(1, 1));
	set_texture(lightunitcityimgtexture, "img/cityicons/lightunitcityimg.jpg");
	set_sprite(lightunitcityimg, lightunitcityimgtexture, Vector2i(1000, 1000), Vector2f(0, 0), Vector2f(1, 1));
	set_texture(tankunitcityimgtexture, "img/cityicons/tankunitcityimg.jpg");
	set_sprite(tankunitcityimg, tankunitcityimgtexture, Vector2i(1000, 1000), Vector2f(0, 0), Vector2f(1, 1));
	set_texture(artillerycityimgtexture, "img/cityicons/artillerycityimg.jpg");
	set_sprite(artillerycityimg, artillerycityimgtexture, Vector2i(1000, 1000), Vector2f(0, 0), Vector2f(1, 1));

	set_texture(applybuttontexture, "img/cityicons/applybutton.jpg");
	set_sprite(applybutton, applybuttontexture, Vector2i(1000, 1000), Vector2f(0, 0), Vector2f(1, 1));

	personnelcountertexture.loadFromFile("img/counterpersonnel/counterpersonnel.jpg");
	personnelcounter.setTexture(personnelcountertexture);
	personnelcounter.setPosition(1000, 1000);
}

