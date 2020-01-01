/**
 * @file DepthCamera.h
 * @author Onur Nafi G�zel (ongguzel@gmail.com)
 * @date December, 2019
 * @edited_by Ersan Tzampaz Chatip (hatipersan@gmail.com)
 */
#pragma once
#include<iostream>
#include<string>
#include"PointCloud.h"
#include"Point.h"
#include "PointCloudGenerator.h"

using namespace std;
class DepthCamera :public PointCloudGenerator
{
private:
	string fileName;
public:
	PointCloud Capture(); //! Fonksiyon �a��r�l�yor
	void setfileName(string fName); //! Dosya ad� atan�yor
	string getfileName(); //! Dosya ad� d�nd�r�l�yor
	PointCloud captureFor(); //! Get, filter and transform pointcloud
};

