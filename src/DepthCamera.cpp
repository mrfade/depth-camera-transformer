#include "DepthCamera.h"
#include<iostream>
#include<fstream>
using namespace std;
PointCloud DepthCamera :: Capture() { 
	PointCloud points; // Nesne
	double x, y, z; // Noktan�n koordinatlar�
	ifstream file;
	file.open(fileName); //Dosya a��l�yor
	while (!file.eof()) // Dosya sonuna kadar kooordianatlar al�n�p atan�yor
	{

		file >> x >> y >> z; // Al�n�yor

		points.addPoint(x, y, z); // G�nderiliyor

	}

	file.close();// Dosya kapat�l�yor
	return points; // Nesne d�nd�r�l�yor
}

void DepthCamera::setfileName(string fName) 
{
	fileName = fName; //Dosya ad� atan�yor
}
string DepthCamera::getfileName() {
	return fileName; // Dosya ad� d�nd�r�l�yor
}