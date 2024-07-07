#include "canvas.h"
#include "figures.h"
#include <assert.h>

#define ARG_EXPECTED 2

int argChecker(int argc,int argExpected){
	if(argc == argExpected)  { return true; }
	else 			 { return false;}
}

int main(int argc,char* argv[]){
	assert(argChecker(argc,ARG_EXPECTED));
	std::string configFile = argv[1];
	
	//open config file 
	std::fstream file(configFile); 
	if(file.is_open() == false){ std::cout << "BOOO" << "\n"; }; 

	//creating the canvas 
	ASCIICanvas canvas1;
	canvas1.readASCII(&file);
	canvas1.createCanvas();
	file.close();
	
	//creating the shapes 
	Rectangle reccy1;
	Deltoid del1;
	Triangle tri1;

	//read the shapes from the config file and put them on the canvas
	reccy1.getRectangle(configFile,canvas1);
	del1.getDeltoid(configFile,canvas1);
	tri1.getTriangle(configFile,canvas1);

	return 0;
}
