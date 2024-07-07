#include "figures.h"

///minor functions
void correctCoordinates(unsigned int coordinates[]){ // make 0,0 point inside the canvas
	for(int i=0;i<2;i++){
		coordinates[i]++;
	}
}

int dimensionsChecker(unsigned int*coordinates,std::vector<unsigned int> canvasDimensions,unsigned int *dimensions){
	if(coordinates[WIDTH] + dimensions[WIDTH]  > canvasDimensions[WIDTH]+1) { return 1; }
	if(coordinates[HEIGHT] + dimensions[HEIGHT]  > canvasDimensions[HEIGHT]+1) { return 1; }
	else { return 0; }
} 

int dimensionsCheckerDeltoid(unsigned int*coordinates,std::vector<unsigned int> canvasDimensions,unsigned int radius){
	if(coordinates[WIDTH] + 2*radius  > canvasDimensions[WIDTH]+1) { return 1; }
	if(coordinates[HEIGHT]+   radius  > canvasDimensions[HEIGHT]+2) { return 1; }
	else { return 0; }
} 


int manipulateData(std::vector<std::string> *vec,unsigned int *coordinates,unsigned int*dimensions){
	unsigned int tempCoordinates[XY],tempDimensions[XY];	

	try{
	tempCoordinates[0] = stoi(vec->at(HEIGHT));
	tempCoordinates[1] = stoi(vec->at(WIDTH));
	tempDimensions[0] =  stoi(vec->at(2));
	tempDimensions[1] =  stoi(vec->at(3));
	}
	catch(std::invalid_argument const&ex){
		std::cerr << "invalid argument " << ex.what() << '\n';
		throw; 
	}

	coordinates[0] = tempCoordinates[0];
	coordinates[1] = tempCoordinates[1];
	dimensions[0]  = tempDimensions[0];
	dimensions[1] =  tempDimensions[1];

	return 0;
}

int manipulateDataDeltoid(std::vector<std::string> *vec,unsigned int *coordinates,unsigned int*radius){
	unsigned int tempCoordinates[XY];	

	try{
	tempCoordinates[0] = stoi(vec->at(HEIGHT));
	tempCoordinates[1] = stoi(vec->at(WIDTH));
	*radius  =  stoi(vec->at(2));
	}
	catch(std::invalid_argument const&ex){
		std::cerr << "invalid argument " << ex.what() << '\n';
		throw; 
	}

	coordinates[0] = tempCoordinates[0];
	coordinates[1] = tempCoordinates[1];

	return 0;
}

int manipulateDataTriangle(std::vector<std::string> *vec,unsigned int *coordinates,unsigned int*dimensions){
	unsigned int tempCoordinates[XY],tempDimensions[XY];	

	try{
	tempCoordinates[0] = stoi(vec->at(HEIGHT));
	tempCoordinates[1] = stoi(vec->at(WIDTH));
	tempDimensions[0] =  stoi(vec->at(2));
	}
	catch(std::invalid_argument const&ex){
		std::cerr << "invalid argument " << ex.what() << '\n';
		throw; 
	}

	coordinates[0] = tempCoordinates[0];
	coordinates[1] = tempCoordinates[1];
	dimensions[0]  = tempDimensions[0];

	return 0;
}

