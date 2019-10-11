#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "Soldier.h"
using namespace std;
using namespace sf;

void SetTexture(int NumOfUnit, Texture &texture1, Texture &texture2, Texture &texture3)
{
	if (InfantryArr[NumOfUnit].MyCountry == playercountry)
	{
		InfantryArr[NumOfUnit].InfantryUnitSprite.setTexture(texture1);
	}
	else if (InfantryArr[NumOfUnit].MyCountry == enemycountry)
	{
		InfantryArr[NumOfUnit].InfantryUnitSprite.setTexture(texture2);
	}
	else
	{
		InfantryArr[NumOfUnit].InfantryUnitSprite.setTexture(texture3);
	}
}

void ResetTexturesForAllUnits()
{
	frame.setPosition(1000, 1000);
	for (unsigned int i = 0; i < InfantryArr.size(); i++)
	{
		if (InfantryArr[i].get_status() != 1)
		{
			if (InfantryArr[i].type == "infantry")
				SetTexture(i, InfantryUnitTexture, EnemyInfantryUnitTexture, NeutralInfantryUnitTexture);
			else if (InfantryArr[i].type == "guard")
				SetTexture(i, GuardInfantryUnitTexture, EnemyGuardInfantryUnitTexture, NeutralGuardInfantryUnitTexture);
			else if (InfantryArr[i].type == "artillery")
				SetTexture(i, ArtilleryUnitTexture, EnemyArtilleryUnitTexture, NeutralArtilleryUnitTexture);
			else if (InfantryArr[i].type == "light infantry")
				SetTexture(i, LightInfantryTexture, EnemyLightInfantryTexture, NeutralLightInfantryTexture);
			else if (InfantryArr[i].type == "tank")
				SetTexture(i, TankUnitTexture, EnemyTankUnitTexture, NeutralTankUnitTexture);
		}
		else
		{
			if (InfantryArr[i].type == "infantry")
			{
				SetTexture(i, InfantryUnitTexturedef,
					EnemyInfantryUnitTexturedef, NeutralInfantryUnitTexturedef);
			}
			else if (InfantryArr[i].type == "guard")
			{
				SetTexture(i, GuardInfantryUnitTexturedef,
					EnemyGuardInfantryUnitTexturedef, NeutralGuardInfantryUnitTexturedef);
			}
			else if (InfantryArr[i].type == "artillery")
			{
				SetTexture(i, ArtilleryUnitTexturedef, 
					EnemyArtilleryUnitTexturedef, NeutralArtilleryUnitTexturedef);
			}
			else if (InfantryArr[i].type == "light infantry")
			{
				SetTexture(i, LightInfantryTexturedef,
					EnemyLightInfantryTexturedef, NeutralLightInfantryTexturedef);
			}
		}
	}
}

void SetActiveTextureForUnit(int NumOfUnit)
{
	frame.setPosition((float)InfantryArr[NumOfUnit].GetPosition().x, (float)InfantryArr[NumOfUnit].GetPosition().y);
}
