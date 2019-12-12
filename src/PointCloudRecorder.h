#include <string>
#include <vector>
#include <fstream>
#include "Point.h"
#include "PointCloud.h"

class PointCloudRecorder
{
private:
	std::string fileName;
public:
	PointCloudRecorder();
	PointCloudRecorder(std::string);
	~PointCloudRecorder();

	void setFileName(std::string);
	std::string getFileName();

	bool save(const PointCloud&);
};
