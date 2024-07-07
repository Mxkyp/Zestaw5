#ifndef CANVAS_H
#define CANVAS_H
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

#define HEIGHT 0
#define WIDTH 1
#define CANVAS_FILE 2
#define EMPTY_SPACE_CHAR 3

class Canvas{
	public:
		Canvas();
		void setHeight(unsigned int h);
		void setWidth(unsigned int w);
		void setCanvasFile(std::string s);
		void setEmptySpace(char c);
		void print(int member);
		void get(std::vector<unsigned int> *values,std::string *str,char *c);

	private:
		unsigned int height;
		unsigned int width;
		std::string canvas_file;
		char emptySpaceChar;
};

class ASCIICanvas: public Canvas{
	public:
		ASCIICanvas();
		int readASCII(std::fstream *afile); // function for reading information from an ASCII FIlE
		int createCanvas(); // function used to build a canvas based on the information received from the function above
};


#endif
