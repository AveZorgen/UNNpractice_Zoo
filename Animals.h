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
	string ClassInfo = "����������";
	string Roar = "����-����";
public:
	string GetInfo() { return ClassInfo; }
	int isAgressive() { return 0; }
	void MakeRoar() { cout << Roar; }
};

class Rabbit : public Herbivores {
protected:
	string PersonalInfo = "������ ������";
	string Roar = Herbivores::Roar = "���-���";
	string GetInfo() { return ClassInfo + "; " + PersonalInfo; }
};

class Carnivores : public IAnimal {
protected:
	string ClassInfo = "����������";
	string Roar = "����-����";
public:
	string GetInfo() { return ClassInfo; }
	int isAgressive() { return 1; }
	void MakeRoar() { cout << Roar; }
};

class Wolf : public Carnivores {
protected:
	string PersonalInfo = "���� - ������ ����";
	string Roar = Carnivores::Roar = "����";
	string GetInfo() { return ClassInfo + "; " + PersonalInfo; }
};

//��� ����������� � IAnimal ���������� getclone (�������
//���������� ��� ����������
//���� �� ����������, � ����������, ��
//����������� ����������� ������ � � ������
//� ���������� = �����������

//try �� ��� ������
//���� �� ���� ������, �� ������� ����� � ����
//
//� ������ ������ ��������