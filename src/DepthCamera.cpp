#include "DepthCamera.h"
#include<iostream>
#include<fstream>
using namespace std;
PointCloud DepthCamera :: Capture() { 
	PointCloud points; // Nesne
	double x, y, z; // Noktanýn koordinatlarý
	ifstream file;
	file.open(fileName); //Dosya açýlýyor
	while (!file.eof()) // Dosya sonuna kadar kooordianatlar alýnýp atanýyor
	{

		file >> x >> y >> z; // Alýnýyor

		points.addPoint(x, y, z); // Gönderiliyor

	}

	file.close();// Dosya kapatýlýyor
	return points; // Nesne döndürülüyor
}

void DepthCamera::setfileName(string fName) 
{
	fileName = fName; //Dosya adý atanýyor
}
string DepthCamera::getfileName() {
	return fileName; // Dosya adý döndürülüyor
}