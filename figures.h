#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include "canvas.h"

#define XY 2

class Figure{
	public:
	virtual int draw(ASCIICanvas &c,unsigned int coordinates[],unsigned int dimensions[]) = 0;
};

class Rectangle:public Figure{
	public:
		int draw(ASCIICanvas &c,unsigned int coordinates[],unsigned int dimensions[]);
		int getRectangle(std::string fileName,ASCIICanvas &c);
};

class Deltoid:public Figure{
	public:
		int draw(ASCIICanvas &c,unsigned int coordinates[],unsigned int dimensions[]);
		int getDeltoid(std::string fileName,ASCIICanvas &c);
};

class Triangle:public Figure{
	public:
		int draw(ASCIICanvas &c,unsigned int coordinates[],unsigned int dimensions[]);
		int getTriangle(std::string fileName,ASCIICanvas &c);
};


////minor function prototypes
int manipulateData(std::vector<std::string> *vec,unsigned int*dimensions,unsigned int *coordinates);
int manipulateDataDeltoid(std::vector<std::string> *vec,unsigned int *coordinates,unsigned int*radius);
int dimensionsChecker(unsigned int*coordinates,std::vector<unsigned int> canvasDimensions,unsigned int *dimensions);
int dimensionsCheckerDeltoid(unsigned int*coordinates,std::vector<unsigned int> canvasDimensions,unsigned int radius);
void correctCoordinates(unsigned int coordinates[]);
int manipulateDataTriangle(std::vector<std::string> *vec,unsigned int *coordinates,unsigned int*dimensions);

#endif
