#include "figures.h"

//major function prototypes
void createTriangle(unsigned int*coordinates,unsigned int *dimensions,std::vector<unsigned int> canvasDimensions,std::fstream *file);
void getDataTriangle(std::fstream *afile,std::vector<std::string> *vec,std::string *str);

//////////Triangle
int Triangle::getTriangle(std::string fileName,ASCIICanvas &c){ // function to used to get the circle onto the canvas
	std::fstream afile(fileName); 
	std::vector<std::string> vec;
	unsigned int coordinates[2] = {0,0}, dimensions[1]={0};
	std::string str;
	
	getDataTriangle(&afile,&vec,&str);
	manipulateDataTriangle(&vec,coordinates,dimensions); // minor function to modify the data into the correct format
	draw(c,coordinates,dimensions);
	afile.close();
	return 0;	
}


int Triangle::draw(ASCIICanvas &c,unsigned int coordinates[],unsigned int dimensions[]){
	std::vector<unsigned int> canvasDimensions;
	std::string canv_adress;
	
	correctCoordinates(coordinates);
	c.get(&canvasDimensions,&canv_adress,nullptr);

	if(dimensionsChecker(coordinates,canvasDimensions,dimensions) == 1) { return 1; }
	std::fstream canFile(canv_adress.c_str());
	if(canFile.is_open() == false){ std::cout << "booooo\n"; }

	
	createTriangle(coordinates,dimensions,canvasDimensions,&canFile);		
	canFile.close();
	return 0;
}

void createTriangle(unsigned int*coordinates,unsigned int *dimensions,std::vector<unsigned int> canvasDimensions,std::fstream *file){
	std::string str;													      

	for(unsigned int i=0;i<coordinates[HEIGHT];i++){
		getline(*file,str);
	}

	(*file).seekp(coordinates[WIDTH],std::ios_base::cur);

	for(unsigned int i=0;i<dimensions[HEIGHT];i++){
		for(unsigned int j=0;j<i+1;j++){
			*file << '#';
		}
		getline(*file,str);
		(*file).seekp(coordinates[WIDTH],std::ios_base::cur);
	}

}

void getDataTriangle(std::fstream *afile,std::vector<std::string> *vec,std::string *str){
	char c;
	bool rightShape = false;
	while(afile->get(c)){
		if(c == '\n'){
			vec->push_back(*str);
			str->clear();
			break;
		}
		else if(c != 'T' && rightShape == false){
				std::getline(*afile,*str);
				str->clear();
		}
		else if (c=='T'){
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
