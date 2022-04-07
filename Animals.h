#pragma once
#include <iostream>
#include <string>

using namespace std;

class IAnimal {
public:
	virtual string GetInfo() = 0;
	virtual int isAgressive() = 0;
	virtual void MakeRoar() = 0;
};

class Herbivores : public IAnimal {
protected:
	string ClassInfo = "Травоядное";
	string Roar = "Хрум-хрум";
public:
	string GetInfo() { return ClassInfo; }
	int isAgressive() { return 0; }
	void MakeRoar() { cout << Roar; }
};

class Rabbit : public Herbivores {
protected:
	string PersonalInfo = "Кролик Роджер";
	string Roar = Herbivores::Roar = "Фыр-фыр";
	string GetInfo() { return ClassInfo + "; " + PersonalInfo; }
};

class Carnivores : public IAnimal {
protected:
	string ClassInfo = "Плотоядное";
	string Roar = "Чавк-чавк";
public:
	string GetInfo() { return ClassInfo; }
	int isAgressive() { return 1; }
	void MakeRoar() { cout << Roar; }
};

class Wolf : public Carnivores {
protected:
	string PersonalInfo = "Волк - зубами щёлк";
	string Roar = Carnivores::Roar = "Аууф";
	string GetInfo() { return ClassInfo + "; " + PersonalInfo; }
};

//для копирования в IAnimal определить getclone (который
//объяснаяет как копировать
//если не копировать, а перемещать, то
//конструктор копирования пустым и в приват
//и приравание = перемещение

//try во все клетки
//если во всех ошибки, то создать новую и туда
//
//в клетке массив животных