#include "figures.h"
#define RADIUS 0

//major function prototypes
void createDeltoid(unsigned int*coordinates,unsigned int radius,std::vector<unsigned int> canvasDimensions,std::fstream *file);
void getDataDeltoid(std::fstream *afile,std::vector<std::string> *vec,std::string *str);

//////////Deltoid
int Deltoid::getDeltoid(std::string fileName,ASCIICanvas &c){ // function used to get the deltoid onto the canvas
	std::fstream afile(fileName); 
	std::vector<std::string> vec;
	unsigned int coordinates[2] = {0,0},dimensions[1] = {0};
	std::string str;
	
	getDataDeltoid(&afile,&vec,&str);
	manipulateDataDeltoid(&vec,coordinates,&dimensions[RADIUS]); // minor function to modify the data into the correct format

	draw(c,coordinates,&dimensions[RADIUS]);
	afile.close();
	return 0;	
}

void getDataDeltoid(std::fstream *afile,std::vector<std::string> *vec,std::string *str){
	char c;
	bool rightShape = false;

	while(afile->get(c)){
		if(c == '\n'){
			vec->push_back(*str);
			str->clear();
			break;
		}
		else if(c != 'D' && rightShape == false){
				std::getline(*afile,*str);
				str->clear();
		}
		else if (c=='D'){
			rightShape = true;
		}
		else if(c == '=' ){ 
			if(str->empty() == false){
				vec->push_back(*str);
				str->clear();
			}
		}
		else{
			str->push_back(c);
		}
	}
}

int Deltoid::draw(ASCIICanvas &c,unsigned int coordinates[],unsigned int dimensions[]){ // function for drawing the deltoid
	std::vector<unsigned int> canvasDimensions;
	std::string canv_adress;
	
	correctCoordinates(coordinates);
	c.get(&canvasDimensions,&canv_adress,nullptr);

	if(dimensionsCheckerDeltoid(coordinates,canvasDimensions,dimensions[RADIUS]) == 1) { return 1;}
	std::fstream canFile(canv_adress.c_str());
	if(canFile.is_open() == false){ std::cout << "booooo\n"; }

	
	createDeltoid(coordinates,dimensions[RADIUS],canvasDimensions,&canFile);		
	canFile.close();
	return 0;
}


void createDeltoid(unsigned int*coordinates,unsigned int radius,std::vector<unsigned int> canvasDimensions,std::fstream *file){ // this works but is unelegeant
	std::string str;

	for(unsigned int i=0;i<coordinates[HEIGHT]-radius;i++){
		getline(*file,str);
	}
	for(unsigned int i=0;i<radius;i++){ // create the upper half
	(*file).seekp(coordinates[WIDTH]+radius-i,std::ios_base::cur);
		for(unsigned int j=0;j<2*i+1;j++){
		*file << '#';
		}
		getline(*file,str);
	}
	for(unsigned int i=radius-2;i>0;i--){ //create the bottom half
	(*file).seekp(coordinates[WIDTH]+radius-i,std::ios_base::cur);
		for(unsigned int j=2*i+1;j>0;j--){
		*file << '#';
		}
		getline(*file,str);
	}
	(*file).seekp(coordinates[WIDTH]+radius,std::ios_base::cur);
	*file << '#';
}
