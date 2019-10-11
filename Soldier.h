#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "Map.h"
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;

//Player Units:
Texture InfantryUnitTexture;
Texture InfantryUnitTexturedef;
Texture GuardInfantryUnitTexture;
Texture GuardInfantryUnitTexturedef;
Texture TankUnitTexture;
Texture ArtilleryUnitTexture;
Texture ArtilleryUnitTexturedef;
Texture LightInfantryTexture;
Texture LightInfantryTexturedef;

//Enemy Units:
Texture EnemyInfantryUnitTexture;
Texture EnemyInfantryUnitTexturedef;
Texture EnemyGuardInfantryUnitTexture;
Texture EnemyGuardInfantryUnitTexturedef;
Texture EnemyTankUnitTexture;
Texture EnemyArtilleryUnitTexture;
Texture EnemyArtilleryUnitTexturedef;
Texture EnemyLightInfantryTexture;
Texture EnemyLightInfantryTexturedef;

//Neutral Units:
Texture NeutralInfantryUnitTexture;
Texture NeutralInfantryUnitTexturedef;
Texture NeutralGuardInfantryUnitTexture;
Texture NeutralGuardInfantryUnitTexturedef;
Texture NeutralTankUnitTexture;
Texture NeutralArtilleryUnitTexture;
Texture NeutralArtilleryUnitTexturedef;
Texture NeutralLightInfantryTexture;
Texture NeutralLightInfantryTexturedef;

//Arrows:
Texture ArrowAttackTexture;
Texture ArrowSupportTexture;
Texture ArrowMarchTexture;
Texture ArrowReatreatTexture;

Font unitsfont;

Sprite frame;
Texture frametexture;

Sprite defense;
Texture defensetexture;

Sprite enemydefense;
Texture enemydefensetexture;

Sprite neutraldefense;
Texture neutraldefensetexture;


class Arrow
{
private:
	int posx = 0, posy = 0;
	float degree = 0.0;
public:
	string type = " ";
	Sprite arrowsprite;
	Sprite arrowspritearrow;
public:
	Arrow(int aposx, int aposy, int bposx, int bposy, string _type);
};

vector <Arrow> ArrowArr;

Arrow::Arrow(int aposx, int aposy, int bposx, int bposy, string _type)
{
	posx = aposx;
	posy = aposy;
	float dX = float(posx - bposx);
	float dY = float(posy - bposy);
	float rotation = float((atan2(dY, dX)) * 180 / 3.14);
	type = _type;
	if (type == "attack") arrowsprite.setTexture(ArrowAttackTexture);
	else if (type == "support")
	{
		arrowsprite.setTexture(ArrowSupportTexture);
	}
	else if (type == "march") arrowsprite.setTexture(ArrowMarchTexture);
	else
		arrowsprite.setTexture(ArrowReatreatTexture);
	arrowsprite.setScale(1, 0.8f);
	arrowsprite.setOrigin(40, 20);
	float distance = float(sqrt(abs(aposx - bposx) + abs(aposy - bposy)));
	float scalea = distance / 6;
	arrowsprite.scale(scalea, 1);
	arrowsprite.setRotation(rotation);
	arrowsprite.setPosition(float(posx), float(posy));
	ArrowArr.push_back(*this);
}

class Unit
{
private:
	int x = 0, y = 0;
	int ReatreatCity = -1;
	int status = 0;
public:
	string type = " ";
	float strength = 0.0;
	float stockstrength = 0.0;
	float supportstrength = 0.0;
	float startstrength = 0.0;
	vector <int> supportunits;
	int supportto = -1;
	int numofunit = -1;
	int numofmoves = 3;
	string MyCountry = " ";
	string CountryNow = " ";
	string name = "";
	Sprite InfantryUnitSprite;
	Text citynametext;
	int CityNow = 0;
	bool reatreat = 0;
	int reatreatarrownum = -1;
	int attackedunit = -1;
	int personnel = 10;
	int steptoheal = 0;
	int steptodisbandment = 0;
	int containedcity = 0;
	bool dead = 0;
public:
	Unit(int NumCityInArr, string Type);
	Vector2i GetPosition();
	void Attack();
	void Support(int unitnumtosupport);
	void Move(int CityNum);
	void CaptureCity();
	int get_reatreat_city();
	void set_reatreat_city(int numofcity);
	void defensive_position();
	void stowed_condition();
	int get_status();
	void reatreat_to_city();
	void move_to_attacked_city(int attackedcity);
};

vector <Unit> InfantryArr;

Unit::Unit(int NumCityInArr, string Type)
{
	MyCountry = ArrOfCity[NumCityInArr].country;
	type = Type;
	string formation = " ";
	if (Type == "guard")
	{
		strength = 1.5;
		name = "(G) ";
		if(MyCountry == playercountry)
		    InfantryUnitSprite.setTexture(GuardInfantryUnitTexture);
		else if(MyCountry == enemycountry)
			InfantryUnitSprite.setTexture(EnemyGuardInfantryUnitTexture);
		else
			InfantryUnitSprite.setTexture(NeutralGuardInfantryUnitTexture);
		formation = " infantry brigade";
	}
	else if (Type == "infantry")
	{
		strength = 1;
		if (MyCountry == playercountry)
			InfantryUnitSprite.setTexture(InfantryUnitTexture);
		else if (MyCountry == enemycountry)
			InfantryUnitSprite.setTexture(EnemyInfantryUnitTexture);
		else
			InfantryUnitSprite.setTexture(NeutralInfantryUnitTexture);
		formation = " infantry brigade";
	}
	else if (type == "tank")
	{
		strength = float(1.7);
		if (MyCountry == playercountry)
			InfantryUnitSprite.setTexture(TankUnitTexture);
		else if (MyCountry == enemycountry)
			InfantryUnitSprite.setTexture(EnemyTankUnitTexture);
		else
			InfantryUnitSprite.setTexture(NeutralTankUnitTexture);
		formation = " tank division";
	}
	else if (type == "artillery")
	{
		strength = 0.5;
		if (MyCountry == playercountry)
			InfantryUnitSprite.setTexture(ArtilleryUnitTexture);
		else if (MyCountry == enemycountry)
			InfantryUnitSprite.setTexture(EnemyArtilleryUnitTexture);
		else
			InfantryUnitSprite.setTexture(NeutralArtilleryUnitTexture);
		formation = " artillery battery";
		numofmoves = 2;
	}
	else if (type == "light infantry")
	{
		name = "(L) ";
		strength = float(0.7);
		if (MyCountry == playercountry)
			InfantryUnitSprite.setTexture(LightInfantryTexture);
		else if (MyCountry == enemycountry)
			InfantryUnitSprite.setTexture(EnemyLightInfantryTexture);
		else
			InfantryUnitSprite.setTexture(NeutralLightInfantryTexture);
		formation = " infantry brigade";
		numofmoves = 4;
	}
	stockstrength = strength;
	startstrength = strength;
	numofunit = InfantryArr.size();
	CityNow = NumCityInArr;
	CountryNow = ArrOfCity[CityNow].country;
	ArrOfCity[CityNow].change_unit_in_city(numofunit);
	containedcity = CityNow;
	ArrOfCity[CityNow].containedunit = 1;
	if (ArrOfCity[NumCityInArr].citynametext.getString() != "")
		name += ArrOfCity[NumCityInArr].citynametext.getString() + formation;
	else
		name += to_string(NumCityInArr) + formation;
	x = ArrOfCity[NumCityInArr].GetPosition().x;
	y = ArrOfCity[NumCityInArr].GetPosition().y + 1;
	InfantryUnitSprite.setOrigin(20.5f, 20.5f);
	InfantryUnitSprite.setScale(0.8f, 0.8f);
	string NameOfCity = ArrOfCity[NumCityInArr].citynametext.getString();
	InfantryUnitSprite.setPosition((float)x, (float)y);
	InfantryArr.push_back(*this);
}

Vector2i Unit::GetPosition()
{
	Vector2i pos;
	pos.x = x;
	pos.y = y;
	return pos;
}

bool Enumeration(int numa, int numb, int valuea, int valueb)
{
	if (numa == valuea and numb == valueb or numa == valueb and numb == valuea)
		return 1;
	else
		return 0;
}

bool CheckWay(int citya, int cityb)
{
	if (Enumeration(citya, cityb, 54, 48)) return 1;
	else if (Enumeration(citya, cityb, 72, 47)) return 1;
	else if (Enumeration(citya, cityb, 46, 29)) return 1;
	else if (Enumeration(citya, cityb, 33, 130)) return 1;
	else if (Enumeration(citya, cityb, 32, 16)) return 1;
	else if (Enumeration(citya, cityb, 18, 16)) return 1;
	else if (Enumeration(citya, cityb, 156, 64)) return 1;
	else if (Enumeration(citya, cityb, 1, 64)) return 1;
	else if (Enumeration(citya, cityb, 155, 71)) return 1;
	else if (Enumeration(citya, cityb, 109, 157)) return 1;
	else if (Enumeration(citya, cityb, 117, 160)) return 1;
	else if (Enumeration(citya, cityb, 117, 161)) return 1;
	else if (Enumeration(citya, cityb, 160, 164)) return 1;
	else if (Enumeration(citya, cityb, 157, 164)) return 1;
	else if (Enumeration(citya, cityb, 158, 164)) return 1;
	else if (Enumeration(citya, cityb, 65, 66)) return 1;
	else if (Enumeration(citya, cityb, 4, 105)) return 1;
	else if (Enumeration(citya, cityb, 104, 116)) return 1;
	else if (Enumeration(citya, cityb, 2, 161)) return 1;
	else if (Enumeration(citya, cityb, 2, 148)) return 1;
	else if (Enumeration(citya, cityb, 2, 150)) return 1;
	else if (Enumeration(citya, cityb, 163, 151)) return 1;
	else if (Enumeration(citya, cityb, 163, 150)) return 1;
	else if (Enumeration(citya, cityb, 153, 168)) return 1;
	else if (Enumeration(citya, cityb, 153, 169)) return 1;
	else if (Enumeration(citya, cityb, 152, 169)) return 1;
	else if (Enumeration(citya, cityb, 167, 176)) return 1;
	else if (Enumeration(citya, cityb, 167, 175)) return 1;
	else if (Enumeration(citya, cityb, 22, 31)) return 1;
	else if (Enumeration(citya, cityb, 22, 35)) return 1;
	else if (Enumeration(citya, cityb, 142, 2)) return 1;
	else if (Enumeration(citya, cityb, 78, 81)) return 1;
	else if (Enumeration(citya, cityb, 77, 82)) return 1;
	else if (Enumeration(citya, cityb, 85, 127)) return 1;
	else if (Enumeration(citya, cityb, 88, 96)) return 1;
	else if (Enumeration(citya, cityb, 99, 103)) return 1;
	else if (Enumeration(citya, cityb, 100, 103)) return 1;
	else if (Enumeration(citya, cityb, 66, 177)) return 1;
	else return 0;
}

float calculate_stock_strength(float startstrength, int personnel)
{
	return floor(((startstrength/10) * personnel) * 10) / 10;
}

float calculate_strength(float stockstrength, int status, string type)
{
	if (status == 1)
	{
		if (type == "artillery")
			return stockstrength * 2;
		else if (type == "light infantry")
			return float(floor(stockstrength * 1.42));
		else
			return float(stockstrength + (stockstrength / 2));
	}
	else
		return stockstrength;
}

void Unit::Attack()
{
	if (attackedunit == -1) return;
	auto enemy = InfantryArr.begin() + attackedunit;
	int attackedcity = enemy->CityNow;
	strength += supportstrength;
	enemy->strength += enemy->supportstrength;
	if (enemy->strength < strength)
	{
		personnel -= 1;
		stockstrength = calculate_stock_strength(startstrength, personnel);
		strength = calculate_strength(stockstrength, status, type);
		enemy->personnel -= int((2 + ceil(strength / enemy->strength)));
		if (enemy->supportto != -1)
		{
			InfantryArr[enemy->supportto].supportstrength -= enemy->stockstrength / 2;
			InfantryArr[enemy->supportto].supportunits.erase(find(InfantryArr[enemy->supportto].supportunits.begin(),
				InfantryArr[enemy->supportto].supportunits.end(), enemy->numofunit));
		}
		enemy->stockstrength = calculate_stock_strength(enemy->startstrength, enemy->personnel);
		if ((enemy->get_reatreat_city() == -1 and enemy->status != 1) or (enemy->personnel < 1))
		{
			enemy->dead = 1;
			ArrOfCity[enemy->CityNow].change_unit_in_city(-1);
			ArrOfCity[enemy->containedcity].containedunit = 0;
		}
		else if (enemy->personnel > 1 and enemy->status == 1)
		{
			enemy->strength = calculate_strength(enemy->stockstrength, enemy->status, enemy->type);
		}
		else
		{
			enemy->reatreat_to_city();
			enemy->strength = calculate_strength(enemy->stockstrength, enemy->status, enemy->type);
		}
		for (auto it = enemy->supportunits.begin(); it != enemy->supportunits.end(); it++)
		{
			InfantryArr[(*it)].personnel -= 1;
			InfantryArr[(*it)].stockstrength = calculate_stock_strength(startstrength, personnel);
			InfantryArr[(*it)].strength = calculate_strength(stockstrength, status, type);
		}
		if (enemy->status != 1) move_to_attacked_city(attackedcity);
	}
	else if (enemy->strength > strength)
	{
		if (enemy->status != 1)
			enemy->personnel -= 1;
		else
			enemy->personnel -= 3;
		enemy->stockstrength =
			calculate_stock_strength(enemy->startstrength, enemy->personnel);
		personnel -= int((2 + ceil(enemy->strength / strength)));
		stockstrength = calculate_stock_strength(startstrength, personnel);
		enemy->strength =
			calculate_strength(enemy->stockstrength, enemy->status, enemy->type);
		if (ReatreatCity == -1 or personnel < 1 and status != 1)
		{
			dead = 1;
			ArrOfCity[CityNow].change_unit_in_city(-1);
			ArrOfCity[containedcity].containedunit = 0;
		}
		else
		{
			strength = calculate_strength(stockstrength, status, type);
			reatreat_to_city();
		}
		for (auto it = supportunits.begin(); it != supportunits.end(); it++)
		{
			InfantryArr[(*it)].personnel -= 1;
			InfantryArr[(*it)].stockstrength = calculate_stock_strength(startstrength, personnel);
			InfantryArr[(*it)].strength = calculate_strength(stockstrength, status, type);
		}
	}
	else
	{
		personnel -= 1;
		stockstrength = calculate_stock_strength(startstrength, personnel);
		strength = calculate_strength(stockstrength, status, type);
		if (enemy->status != 1)
			enemy->personnel -= 1;
		else
			enemy->personnel -= 3;
		enemy->stockstrength = calculate_stock_strength(enemy->startstrength, enemy->personnel);
		enemy->strength = calculate_strength(enemy->stockstrength, enemy->status, enemy->type);
	}
}

void Unit::Support(int unitnumtosupport)
{
	InfantryArr[unitnumtosupport].supportunits.push_back(numofunit);
	if (type == "tank")
		InfantryArr[unitnumtosupport].supportstrength += float(stockstrength / 3.14);
	else if (type == "artillery")
		InfantryArr[unitnumtosupport].supportstrength += float(stockstrength * 2);
	else if (type == "light infantry")
		InfantryArr[unitnumtosupport].supportstrength += float(stockstrength / 1.4);
	else
	    InfantryArr[unitnumtosupport].supportstrength += float(stockstrength / 2);
	supportto = unitnumtosupport;
}

void Unit::Move(int citynum)
{
	float distance = 0;
	string newcitycountry = " ";
	newcitycountry = ArrOfCity[citynum].startcountry;
	if (CheckWay(CityNow, citynum)) distance = 13;
	else if (newcitycountry == CountryNow or newcitycountry == MyCountry) distance = 11;
	else distance = 7.5;
	if (reatreat and ArrOfCity[citynum].get_unit_in_city() == -1 and ReatreatCity == -1 and status != 1
		and sqrt(abs(ArrOfCity[citynum].GetPosition().x - x)
			+ abs(ArrOfCity[citynum].GetPosition().y - y)) <= distance)
	{
		for (auto it = InfantryArr.begin(); it != InfantryArr.end(); it++)
			if (it->get_reatreat_city() == citynum)
			{
				reatreat = 0;
				return;
			}
		set_reatreat_city(citynum);
		Arrow A(GetPosition().x, GetPosition().y,
			ArrOfCity[citynum].GetPosition().x, ArrOfCity[citynum].GetPosition().y, "reatreat");
		reatreatarrownum = ArrowArr.size() - 1;
		return;
	} //reatret
	else if (reatreat and reatreatarrownum == -1)
		reatreat = 0;
	else if(sqrt(abs(ArrOfCity[citynum].GetPosition().x - x)
		+ abs(ArrOfCity[citynum].GetPosition().y - y)) <= distance
		and status != 1)
	{
		if (ArrOfCity[citynum].get_unit_in_city() != -1 and
			InfantryArr[ArrOfCity[citynum].get_unit_in_city()].MyCountry != MyCountry and supportto == -1)
		{
			Arrow A(GetPosition().x, GetPosition().y,
				ArrOfCity[citynum].GetPosition().x, ArrOfCity[citynum].GetPosition().y, "attack");
			attackedunit = ArrOfCity[citynum].get_unit_in_city();
		}  //attack
		else if (ArrOfCity[citynum].get_unit_in_city() != -1 and
			InfantryArr[ArrOfCity[citynum].get_unit_in_city()].MyCountry == MyCountry and supportto == -1)
		{
			Arrow A(GetPosition().x, GetPosition().y,
				ArrOfCity[citynum].GetPosition().x, ArrOfCity[citynum].GetPosition().y, "support");
			Support(ArrOfCity[citynum].get_unit_in_city());
		} //support
		else if (ArrOfCity[citynum].get_unit_in_city() == -1 and attackedunit == -1 and reatreatarrownum == -1 and
			supportto == -1 and supportunits.empty() and numofmoves > 0)
		{
			for (auto it = InfantryArr.begin(); it != InfantryArr.end(); it++)
				if (it->get_reatreat_city() == citynum)
					return;
			Arrow A(GetPosition().x, GetPosition().y,
				ArrOfCity[citynum].GetPosition().x, ArrOfCity[citynum].GetPosition().y, "march");
			status = 0;
			ArrOfCity[CityNow].change_unit_in_city(-1);
			InfantryUnitSprite.setPosition((float)ArrOfCity[citynum].GetPosition().x,
				(float)ArrOfCity[citynum].GetPosition().y);
			x = ArrOfCity[citynum].GetPosition().x;
			y = ArrOfCity[citynum].GetPosition().y;
			CityNow = citynum;
			ArrOfCity[citynum].change_unit_in_city(numofunit);
			CountryNow = newcitycountry;
			string NameOfCity = ArrOfCity[citynum].citynametext.getString();
			numofmoves--;
		} //move
	}
} 

void Unit::CaptureCity()
{
	if (ArrOfCity[CityNow].country != MyCountry)
		ArrOfCity[CityNow].country = MyCountry;
	CheckCitysInCountry();
}

int Unit::get_reatreat_city()
{
	return ReatreatCity;
}

void Unit::set_reatreat_city(int numofcity)
{
	ReatreatCity = numofcity;
}

void Unit::defensive_position()
{
	status = 1;
	numofmoves -= 1;
	if (type == "infantry" or type == "guard")
		strength += stockstrength / 2;
	else if (type == "artillery")
		strength += stockstrength;
	else if (type == "light infantry")
		strength = float(floor(stockstrength * 1.43 * 10) / 10);
}

void Unit::stowed_condition()
{
	status = 0;
	strength = stockstrength;
}

int Unit::get_status()
{
	return status;
}

void Unit::reatreat_to_city()
{
	status = 0;
	ArrOfCity[CityNow].change_unit_in_city(-1);
	InfantryUnitSprite.setPosition((float)ArrOfCity[ReatreatCity].GetPosition().x,
		(float)ArrOfCity[ReatreatCity].GetPosition().y);
	x = ArrOfCity[ReatreatCity].GetPosition().x;
	y = ArrOfCity[ReatreatCity].GetPosition().y;
	CityNow = ReatreatCity;
	ArrOfCity[ReatreatCity].change_unit_in_city(numofunit);
	CountryNow = ArrOfCity[ReatreatCity].startcountry;
	string NameOfCity = ArrOfCity[ReatreatCity].citynametext.getString();
	ReatreatCity = -1;
	reatreatarrownum = -1;
	reatreat = 0;
	attackedunit = -1;
}

void Unit::move_to_attacked_city(int attackedcity)
{
	status = 0;
	ArrOfCity[CityNow].change_unit_in_city(-1);
	InfantryUnitSprite.setPosition((float)ArrOfCity[attackedcity].GetPosition().x,
		(float)ArrOfCity[attackedcity].GetPosition().y);
	x = ArrOfCity[attackedcity].GetPosition().x;
	y = ArrOfCity[attackedcity].GetPosition().y;
	CityNow = attackedcity;
	ArrOfCity[attackedcity].change_unit_in_city(numofunit);
	CountryNow = ArrOfCity[attackedcity].startcountry;
	string NameOfCity = ArrOfCity[attackedcity].citynametext.getString();
}

void set_texture(Texture& texture, string way)
{
	Image img;
	img.loadFromFile(way);
	img.createMaskFromColor(Color(255, 255, 255));
	texture.loadFromImage(img);
}

void set_sprite(Sprite& sprite, Texture& texture, Vector2i pos, Vector2f origin, Vector2f scale)
{
	sprite.setTexture(texture);
	sprite.setPosition((float)pos.x, (float)pos.y);
	sprite.setOrigin(origin.x, origin.y);
	sprite.setScale(scale.x, scale.y);
}

void random_spawn(string country)
{
	//Unit AMoscowUnit(49, "infantry");
	int numsofcitys = 0;
	vector <int> randcitys;
	if ((countries[country].size() - 1) < 2)
		numsofcitys = countries[country].size() - 1;
	else
		numsofcitys = 2;
	srand(time(0));
	while (1)
	{
		int border1 = countries[country][1];
		int border2 = countries[country][countries[country].size() - 1];
		int city = 0;
		city = rand() % (border2 - border1 + 1) + border1;
		cout << border1 << "=<" << city << "=<" << border2 << endl;
		if (find(randcitys.begin(), randcitys.end(), city) == randcitys.end())
		{
			numsofcitys -= 1;
			randcitys.push_back(city);
		}
		if (numsofcitys == 0) break;
	}
	cout << "Citys in country: " << endl;
	for (unsigned int i = 0; i < countries[country].size(); i++)
		cout << countries[country][i] << endl;
	cout << "Rand citys: " << endl;
	for (int i = 0; i < randcitys.size(); i++)
		cout << randcitys[i] << endl;
	cout << endl;
	for (auto it = randcitys.begin(); it != randcitys.end(); it++)
		Unit A((*it), "infantry");
	Unit B(countries[country][0], "guard");
}

void SpawnFirstUnits()
{
	unitsfont.loadFromFile("fonts/rodchenko.ttf");
	set_texture(InfantryUnitTexture, "img/unit.png");
	set_texture(GuardInfantryUnitTexture, "img/guardunit.png");
	set_texture(InfantryUnitTexturedef, "img/unitdef.png");
	set_texture(GuardInfantryUnitTexturedef, "img/guardunitdef.png");
	set_texture(TankUnitTexture, "img/tankunit.png");
	set_texture(ArtilleryUnitTexture, "img/artilleryunit.png");
	set_texture(ArtilleryUnitTexturedef, "img/artilleryunitdef.png");
	set_texture(LightInfantryTexture, "img/lightunit.png");
	set_texture(LightInfantryTexturedef, "img/lightunitdef.png");
	//player units
	set_texture(EnemyInfantryUnitTexture, "img/enemyunit.png");
	set_texture(EnemyGuardInfantryUnitTexture, "img/enemyguardunit.png");
	set_texture(EnemyInfantryUnitTexturedef, "img/enemyunitdef.png");
	set_texture(EnemyGuardInfantryUnitTexturedef, "img/enemyguardunitdef.png");
	set_texture(EnemyTankUnitTexture, "img/enemytankunit.png");
	set_texture(EnemyArtilleryUnitTexture, "img/enemyartilleryunit.png");
	set_texture(EnemyArtilleryUnitTexturedef, "img/enemyartilleryunitdef.png");
	set_texture(EnemyLightInfantryTexture, "img/enemylightunit.png");
	set_texture(EnemyLightInfantryTexturedef, "img/enemylightunitdef.png");
	//enemy units
	set_texture(NeutralInfantryUnitTexture, "img/neutralunit.png");
	set_texture(NeutralGuardInfantryUnitTexture, "img/neutralguardunit.png");
	set_texture(NeutralInfantryUnitTexturedef, "img/neutralunitdef.png");
	set_texture(NeutralGuardInfantryUnitTexturedef, "img/neutralguardunitdef.png");
	set_texture(NeutralTankUnitTexture, "img/neutraltankunit.png");
	set_texture(NeutralArtilleryUnitTexture, "img/neutralartilleryunit.png");
	set_texture(NeutralArtilleryUnitTexturedef, "img/neutralartilleryunitdef.png");
	set_texture(NeutralLightInfantryTexture, "img/neutrallightunit.png");
	set_texture(NeutralLightInfantryTexturedef, "img/neutrallightunitdef.png");
	//neutral units
	set_texture(ArrowAttackTexture, "img/attack.png");
	set_texture(ArrowSupportTexture, "img/support.png");
	set_texture(ArrowMarchTexture, "img/march.png");
	set_texture(ArrowReatreatTexture, "img/reatreat.png");
	//arrows

	set_texture(frametexture, "img/frame.png");
	set_sprite(frame, frametexture, Vector2i(1000, 1000), Vector2f(20, 20), Vector2f(0.8, 0.8));

	random_spawn("Russia");
	random_spawn("Estonia");
	random_spawn("Norway");
	random_spawn("UK"); //что-то не так

	/*Unit AMoscowUnit(49, "infantry");
	Unit BMoscowUnit(50, "tank");
	Unit CMoscowUnit(51, "artillery");
	Unit AUnit(5, "infantry");
	Unit AAUnit(8, "light infantry");
	Unit AaAUnit(9, "light infantry");
	Unit BUnit(6, "guard");
	Unit CUnit(22, "guard");
	Unit DUnit(26, "guard");*/
}

int ClickedSoldier(Vector2f MousePos)
{
	for (unsigned int i = 0; i < InfantryArr.size(); i++)
	{
		if (sqrt(abs(MousePos.x - InfantryArr[i].GetPosition().x) +
			abs(MousePos.y - InfantryArr[i].GetPosition().y)) < 5)
		{
			return i;
		}
	}
	return -1;
}