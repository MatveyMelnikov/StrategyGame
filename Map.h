#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;
using namespace sf;

Sprite Map;
Texture MapTexture;

Texture cityTexture;
Image cityimg;
Texture cityTextureSmall;
Image cityimgSmall;

Font font;

Sprite countrymapsprite;
Texture countrymaptexture;

Texture enemycitytexture;
Texture ourcitytexture;
Texture enemymaincitytexture;
Texture ourmaincitytexture;

string playercountry = "Russia";
string enemycountry = "Norway";

Sprite cityframe;
Texture cityframetexture;

map <string, vector<int>> countries;

float find_distance(int ax, int ay, int bx, int by)
{
	return (float)sqrt(abs(ax - bx) + abs(ay - by));
}

class City
{
private:
	string name = " ";
	int x = 0, y = 0;
	int NumOfUnitInCity = -1;
public:
	string startcountry = " ";
	string country = " ";
	Sprite CitySprite;
	Text citynametext;
	bool containedunit = 0;
public:
	City(int _x, int _y, string _name, string countrynamem);
	void SetPosition(int _x, int _y);
	Vector2i GetPosition();
	void change_unit_in_city(int unitnum);
	int get_unit_in_city();
};

vector <City> ArrOfCity;

City::City(int _x, int _y, string _name, string countryname)
{
	country = countryname;
	startcountry = countryname;
	if (_name != " ")
	{
		CitySprite.setScale(0.4f, 0.4f);
		CitySprite.setTexture(cityTexture);
	}
	else
	{
		CitySprite.setScale(0.3f, 0.3f);
		CitySprite.setTexture(cityTextureSmall);
	}
	CitySprite.setPosition((float)_x, (float)_y);
	CitySprite.setOrigin(20.5f, 20.5f);
	if (_name != " ")
	{
		citynametext.setFont(font);
		citynametext.setScale(Vector2f(0.5f, 0.5f));
		citynametext.setString(_name);
		citynametext.setPosition((float)_x - (6 + 5 * (_name.size() / 2)), (float)_y + 5);
	}
	x = _x;
	y = _y;
	name = _name;
	countries[countryname].push_back(ArrOfCity.size());
	ArrOfCity.push_back(*this);
	if (name != " ") 
		swap(countries[countryname][0], countries[countryname][countries[countryname].size() - 1]);
	//0 элемент в стране - столица
}

void City::SetPosition(int _x, int _y)
{
	CitySprite.setPosition((float)_x, (float)_y);
	x = _x;
	y = _y;
}

Vector2i City::GetPosition()
{
	Vector2i pos;
	pos.x = x;
	pos.y = y;
	return pos;
}

void City::change_unit_in_city(int unitnum)
{
	NumOfUnitInCity = unitnum;
}

int City::get_unit_in_city()
{
	return NumOfUnitInCity;
}

void Load_Citys()
{
	cityimg.loadFromFile("img/city.png");
	cityimg.createMaskFromColor(Color(255, 255, 255));
	cityTexture.loadFromImage(cityimg);
	cityimgSmall.loadFromFile("img/smallcity.png");
	cityimgSmall.createMaskFromColor(Color(255, 255, 255));
	cityTextureSmall.loadFromImage(cityimgSmall);
	font.loadFromFile("fonts/abbieshire.ttf");
	cout << "10 %" << endl;
	////////////////////////////////////
	//Neth:
	City Amsterdam(285, 355, "Amsterdam", "Neth");
	//Bel:
	City Brussels(270, 390, "Brussels", "Brussels");
	//Switz:
	City Bern(315, 485, "Bern", "Switz");
	//Mace:
	City Skople(550, 590, "Skople", "Mace");
	//Hungary:
	City Budapest(495, 460, "Budapest", "Hungary");
	City ahun(465, 473, " ", "Hungary");
	City bhun(527, 454, " ", "Hungary");
	//Slovakia:
	City Bratislava(490, 430, "Bratislava", "Slovakia");
	City aslo(517, 424, " ", "Slovakia");
	City bslo(469, 437, " ", "Slovakia");
	//Latvia:
	City Riga(530, 233, "Riga", "Latvia");
	City alat(562, 242, " ", "Latvia");
	City blat(494, 243, " ", "Latvia");
	//Lithuania:
	City Vilnus(543, 285, "Vilnus", "Lithuania");
	City alit(520, 281, " ", "Lithuania");
	City blit(517, 260, " ", "Lithuania");
	//Denmark:
	City Copenkagen(360, 285, "Copenkagen", "Denmark");
	//Norway:
	City Oslo(360, 190, "Oslo", "Norway"); //9
	City Bn(323, 213, " ", "Norway");
	City Cn(305, 175, " ", "Norway");
	City Dn(312, 152, " ", "Norway");
	City En(345, 155, " ", "Norway");
	City Fn(363, 154, " ", "Norway");
	City Gn(350, 112, " ", "Norway");
	City Rn(363, 91, " ", "Norway");
	City Zn(393, 20, " ", "Norway"); //17
	//Sweden:
	City Stockholm(425, 200, "Stockholm", "Sweden"); //18
	City Js(450, 35, " ", "Sweden");
	City Ks(440, 75, " ", "Sweden");
	City Ls(425, 115, " ", "Sweden");
	City Ms(395, 107, " ", "Sweden");
	City Os(388, 193, " ", "Sweden");
	City Qs(380, 228, " ", "Sweden");
	City Ss(407, 247, " ", "Sweden");
	City Ts(435, 180, " ", "Sweden");
	City Vs(410, 165, " ", "Sweden");
	City as(417, 21, " ", "Sweden");
	City bs(403, 57, " ", "Sweden");
	//Finland:
	City Helsinki(512, 145, "Helsinki", "Finland"); //30
	City Hf(485, 15, " ", "Finland");
	City If(505, 35, " ", "Finland");
	City cf(520, 53, " ", "Finland");
	City df(530, 88, " ", "Finland");
	City ef(555, 81, " ", "Finland");
	City ff(553, 104, " ", "Finland");
	City gf(515, 108, " ", "Finland");
	City hf(480, 109, " ", "Finland");
	City iF(482, 141, " ", "Finland");
	City jf(552, 125, " ", "Finland"); //40
    //Russia:
	City Moscow(670, 215, "Moskow", "Russia"); //41
	City kr(581, 69, " ", "Russia");
	City lr(611, 66, " ", "Russia");
	City mr(579, 148, " ", "Russia");
	City nr(590, 171, " ", "Russia");
	City oR(568, 193, " ", "Russia");
	City pr(645, 196, " ", "Russia");
	City qr(681, 177, " ", "Russia");
	City rr(620, 235, " ", "Russia");
	City sr(645, 252, " ", "Russia");
	City tr(672, 262, " ", "Russia");
	City ur(670, 294, " ", "Russia");
	City vr(659, 108, " ", "Russia");
	City wr(647, 136, " ", "Russia");
	City ir(497, 291, " ", "Russia");
	//UK:
	City London(200, 360, "London", "UK"); //56
	City Au(175, 255, " ", "UK");
	City Bu(129, 274, " ", "UK");
	City Cu(165, 223, " ", "UK");
	City Du(189, 291, " ", "UK");
	City Eu(193, 321, " ", "UK");
	City Fu(155, 343, " ", "UK");
	City Gu(146, 369, " ", "UK");
    //Estonia:
	City Tallin(530, 185, "Tallin", "Estonia");
	City NE(548, 204, " ", "Estonia");
	//Belarus:
	City Minsk(585, 295, "Minsk", "Belarus"); //66
	City PB(604, 251, " ", "Belarus");
	City UB(617, 277, " ", "Belarus");
	City WB(637, 308, " ", "Belarus");
	City XB(608, 326, " ", "Belarus");
	City xB(558, 333, " ", "Belarus");
	City zB(546, 310, " ", "Belarus");
	//Ukraine:
	City Kiev(640, 360, "Kiev", "Ukraine"); //73
	City ak(679, 330, " ", "Ukraine");
	City bk(614, 372, " ", "Ukraine");
	City ck(568, 360, " ", "Ukraine");
	City dk(542, 426, " ", "Ukraine");
	City ek(568, 414, " ", "Ukraine");
	City fk(597, 397, " ", "Ukraine");
	City gk(621, 402, " ", "Ukraine");
	City hk(662, 372, " ", "Ukraine");
	City ik(696, 357, " ", "Ukraine");
	City jk(682, 420, " ", "Ukraine");
	City kk(667, 438, " ", "Ukraine");
	//Romania:
	City Bucharest(610, 507, "Bucharest", "Romania");
	City aro(545, 459, " ", "Romania");
	City bro(591, 440, " ", "Romania");
	City cro(642, 450, " ", "Romania");
	City dro(576, 472, " ", "Romania");
	City ero(545, 501, " ", "Romania");
	City fro(569, 517, " ", "Romania");
	City gro(653, 500, " ", "Romania");
	City hro(611, 452, " ", "Romania");
	//Bulgaria:
	City Sofia(590, 560, "Sofia", "Bulgaria"); //94
	City abu(614, 540, " ", "Bulgaria");
	City bbu(642, 550, " ", "Bulgaria");
	//Serbia:
	City Belgrad(520, 523, "Belgrad", "Serbia");
	City ase(548, 537, " ", "Serbia");
	City bse(548, 561, " ", "Serbia");
	City sse(533, 574, " ", "Serbia");
	//Bosnia and Herzegovina:
	City Sarajevo(480, 548, "Sarajevo", "BaH"); //101
	City abah(482, 530, " ", "BaH");
	//Montnegro:
	City am(510, 566, " ", "Montnegro");
	//Albania
	City aa(529, 617, " ", "Albania");
	//Greece:
	City ag(584, 600, " ", "Greece");
	City bg(554, 627, " ", "Greece");
	City cg(592, 655, " ", "Greece");
	//Turkey:
	City at(672, 584, " ", "Turkey");
	//Croatia:
	City acr(449, 507, " ", "Croatia"); //109
	//Slovenia:
	City asl(429, 499, " ", "Slovenia");
	//Austria:
	City Vienna(445, 455, "Vienna", "Austria");
	City Aa(357, 478, " ", "Austria");
	City aaus(430, 480, " ", "Austria"); //172
	City baus(408, 453, " ", "Austria");
	City caus(396, 481, " ", "Austria"); //174
	//Poland:
	City Warsaw(500, 350, "Warsaw", "Poland"); //113
	City ap(525, 326, " ", "Poland");
	City bp(530, 368, " ", "Poland");
	City cp(497, 401, " ", "Poland");
	City dp(473, 396, " ", "Poland");
	City ep(449, 384, " ", "Poland");
	City fp(448, 319, " ", "Poland");
	City gp(494, 316, " ", "Poland");
	City hp(444, 356, " ", "Poland");
	City ip(491, 377, " ", "Poland");
	//Czech republic:
	City Prague(410, 410, "Prague", "CzechR");
	City acz(450, 422, " ", "CzechR");
	//Germany: //129
	City Berlin(395, 355, "Berlin", "Germany");
	City age(378, 327, " ", "Germany");
	City bge(342, 318, " ", "Germany");
	City cge(333, 340, " ", "Germany");
	City gge(305, 385, " ", "Germany");
	City hge(325, 411, " ", "Germany");
	City ige(339, 450, " ", "Germany");
	City jge(373, 454, " ", "Germany");
	City kge(397, 381, " ", "Germany");
	City lge(369, 361, " ", "Germany");
	//France:
	City Paris(225, 435, "Paris", "France"); //135
	City afr(236, 402, " ", "France");
	City bfr(298, 440, " ", "France");
	City cfr(275, 469, " ", "France");
	City dfr(265, 503, " ", "France");
	City efr(277, 556, " ", "France");
	City ffr(207, 552, " ", "France");
	City gfr(176, 521, " ", "France");
	City hfr(164, 464, " ", "France");
	City ifr(161, 441, " ", "France");
	City jfr(211, 420, " ", "France");
	//Italy:
	City Rome(410, 600, "Rome", "Italy"); //146
	City ai(435, 614, " ", "Italy");
	City bi(470, 653, " ", "Italy");
	City ci(378, 562, " ", "Italy");
	City di(354, 527, " ", "Italy");
	City ei(379, 508, " ", "Italy");
	City fi(317, 527, " ", "Italy");
	City ait(332, 643, " ", "Italy");
	//Spain:
	City Madrid(105, 615, "Madrid", "Spain"); //153
	City asp(40, 538, " ", "Spain");
	City bsp(80, 555, " ", "Spain");
	City csp(130, 559, " ", "Spain");
	City dsp(155, 590, " ", "Spain");
	City esp(199, 599, " ", "Spain");
	City fsp(138, 673, " ", "Spain");
	City gsp(49, 672, " ", "Spain");
	City hsp(49, 638, " ", "Spain");
	//Portugal:
	City Lisbon(25, 640, "Lisbon", "Portugal"); //162
	City apo(15, 602, " ", "Portugal");
	City bpo(23, 570, " ", "Portugal");
	//Ireland:
	City Dublin(107, 311, "Dublin", "Ireland"); //165
	cout << "60 %" << endl;
	cout << "100 %" << endl;
}

void CheckCitysInCountry()
{
	for (auto it = ArrOfCity.begin(); it != ArrOfCity.end(); it++)
	{
		if ((*it).country == playercountry and (*it).citynametext.getString() == "")
			(*it).CitySprite.setTexture(ourcitytexture);
		else if ((*it).country == playercountry and (*it).citynametext.getString() != "")
			(*it).CitySprite.setTexture(ourmaincitytexture);

		else if ((*it).country == enemycountry and (*it).citynametext.getString() == "")
			(*it).CitySprite.setTexture(enemycitytexture);
		else if ((*it).country == enemycountry and (*it).citynametext.getString() != "")
			(*it).CitySprite.setTexture(enemymaincitytexture);

		else if ((*it).citynametext.getString() == "")
			(*it).CitySprite.setTexture(cityTextureSmall);
		else if ((*it).citynametext.getString() != "")
			(*it).CitySprite.setTexture(cityTexture);
	}
}

void Load_Map()
{
	MapTexture.loadFromFile("img/map.jpg");
	Map.setTexture(MapTexture);
	countrymaptexture.loadFromFile("img/globalmap.jpg");
	countrymapsprite.setTexture(countrymaptexture);
	countrymapsprite.setPosition(1000, 1000);
	countrymapsprite.setScale(0.7f, 0.7f);

	cityimgSmall.loadFromFile("img/ourcity.png");
	cityimgSmall.createMaskFromColor(Color(255, 255, 255));
	ourcitytexture.loadFromImage(cityimgSmall);

	cityimgSmall.loadFromFile("img/enemycity.png");
	cityimgSmall.createMaskFromColor(Color(255, 255, 255));
	enemycitytexture.loadFromImage(cityimgSmall);

	cityimgSmall.loadFromFile("img/enemymaincity.png");
	cityimgSmall.createMaskFromColor(Color(255, 255, 255));
	enemymaincitytexture.loadFromImage(cityimgSmall);

	cityimgSmall.loadFromFile("img/ourmaincity.png");
	cityimgSmall.createMaskFromColor(Color(255, 255, 255));
	ourmaincitytexture.loadFromImage(cityimgSmall);

	Image img;
	img.loadFromFile("img/cityframe.png");
	img.createMaskFromColor(Color(255, 255, 255));
	cityframetexture.loadFromImage(img);
	cityframe.setTexture(cityframetexture);
	cityframe.setOrigin(20, 20);
	cityframe.setScale(0.4f, 0.4f);
	cityframe.setPosition(1000, 1000);

	Load_Citys();
	CheckCitysInCountry();
}

int ClickedCity(Vector2f MousePos, int CityNow)
{
	int a = -1;
	float last_dist = 10;
	for (unsigned int i = 0; i < ArrOfCity.size(); i++)
	{
		float distance = find_distance((int)MousePos.x, (int)MousePos.y, 
			ArrOfCity[i].GetPosition().x, ArrOfCity[i].GetPosition().y);
		float distance_city_now = find_distance((int)MousePos.x, (int)MousePos.y,
			ArrOfCity[CityNow].GetPosition().x, ArrOfCity[CityNow].GetPosition().y);

		if (distance < 5 and i != CityNow and distance < distance_city_now and distance < last_dist)
		{
			a = i;
			last_dist = distance;
		}
	}
	return a;
}

int selected_city(Vector2f MousePos)
{
	int a = -1;
	float last_dist = 10;
	for (unsigned int i = 0; i < ArrOfCity.size(); i++)
	{
		float distance = find_distance((int)MousePos.x, (int)MousePos.y,
			ArrOfCity[i].GetPosition().x, ArrOfCity[i].GetPosition().y);
		if (distance < 5 and distance < last_dist)
		{
			a = i;
			last_dist = distance;
		}
	}
	return a;
}