#pragma once
#include<iostream>
#include<string>
#include"PointCloud.h"
#include"Point.h"
using namespace std;
class DepthCamera // Clas ad�
{
private:
	string fileName; // dosya ad� tan�mlan�yor
public:
	PointCloud Capture(); // Fonksiyon �a��r�l�yor
	void setfileName(string fName); // Dosya ad� atan�yor
	string getfileName(); // Dosya ad� d�nd�r�l�yor
};


