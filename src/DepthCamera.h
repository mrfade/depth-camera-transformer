/**
 * @file DepthCamera.h
 * @author Onur Nafi Güzel (ongguzel@gmail.com)
 * @date December, 2019
 */
#pragma once
#include<iostream>
#include<string>
#include"PointCloud.h"
#include"Point.h"
using namespace std;
class DepthCamera // Clas adý
{
private:
	string fileName; // dosya adý tanýmlanýyor
public:
	PointCloud Capture(); // Fonksiyon çaðýrýlýyor
	void setfileName(string fName); // Dosya adý atanýyor
	string getfileName(); // Dosya adý döndürülüyor
};


