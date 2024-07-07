#include "canvas.h"

#define EXPECTED_LENGTH 3
#define CHAR_LOCATION 1

///minor function prototypes

//ASCIICanvas
void getData(std::fstream *afile,std::vector<std::string> *vec,std::string *str); 
int manipulateData(std::vector<std::string> *vec,std::vector<unsigned int> *values);
void buildVisuals(std::vector<unsigned int> values,std::string str,char c,std::fstream *file);

//////////Canvas base class
Canvas::Canvas(){
	height = 0;
	width = 0;
}

///Major functions
void Canvas::setHeight(unsigned int h){
	height = h;
}

void Canvas::setWidth(unsigned int w){
	width = w;
}
void Canvas::setCanvasFile(std::string s){
	canvas_file = s;
}

void Canvas::setEmptySpace(char c){
	emptySpaceChar = c;	
}

void Canvas::get(std::vector<unsigned int> *values,std::string *str,char *c){
	if(values != nullptr){
		values->push_back(height);
		values->push_back(width);
	}
	if(str != nullptr){
		*str = canvas_file;
	}
	if(c != nullptr){
		*c = emptySpaceChar;
	}
}

void Canvas::print(int member){
	switch(member){
	case HEIGHT:
		std::cout << height;
		break;
	case WIDTH:
		std::cout << width;
		break;
	case CANVAS_FILE:
		std::cout << canvas_file;
		break;
	case EMPTY_SPACE_CHAR:
		std::cout  << emptySpaceChar;
		break;
	}
}

//////////AsciiCanvas
ASCIICanvas::ASCIICanvas(){
	Canvas();
}

///Major functions
int ASCIICanvas::readASCII(std::fstream *afile){
	std::vector<std::string> vec;
	std::vector<unsigned int> values;
	std::string str;
	
	getData(afile,&vec,&str);
	manipulateData(&vec,&values);

	setWidth(values.at(HEIGHT));
	setHeight(values.at(WIDTH));
	setCanvasFile(vec.at(CANVAS_FILE));

	str = vec.at(EMPTY_SPACE_CHAR);
	if( str.length() < EXPECTED_LENGTH ){ // check for the illegal char '='
		return 1; 
	}

	setEmptySpace(str.at(CHAR_LOCATION));



	return 0;	
}


int ASCIICanvas::createCanvas(){
	std::vector<unsigned int> dimensions;
	std::string can_file;
	char emptySpaceChar;

	get(&dimensions,&can_file,&emptySpaceChar);

	std::fstream canFile(can_file.c_str());
	if(canFile.is_open() == false){ std::cout << "booooo\n"; }
	
	buildVisuals(dimensions,can_file,emptySpaceChar,&canFile);
	canFile.close();
	return 0;
}


//Minor functions
void buildVisuals(std::vector<unsigned int> values,std::string str,char c,std::fstream *file){ // i wonder if this function is understandable

	for(int i=0;i<values.at(HEIGHT)+2;i++){  // adding +2 to make the body (without the border) of the specified size

		if(i==0 || i == values.at(HEIGHT)+1){
			for(int j=0; j<values.at(WIDTH)+2; j++){
				*file << '=';	
			} 
			*file << '\n';	
		}

		else{
			for(int j=0; j<values.at(WIDTH)+2; j++){
				if(j==0 || j == values.at(WIDTH)+1){ 
					*file << '|';
				}
				else{ 
					*file << c;
				}
			} 
			*file << '\n';	
		}

	}
}

void getData(std::fstream *afile,std::vector<std::string> *vec,std::string *str){
	char c;
	while(afile->get(c)){
		if(c == '=' || c == '\n' ){ 
			vec->push_back(*str);
			str->clear();
		}
		else{
			str->push_back(c);
		}
	}
}

int manipulateData(std::vector<std::string> *vec,std::vector<unsigned int> *values){
	unsigned int wid = 0, hei = 0;	

	try{
	hei = stoi(vec->at(HEIGHT));
	wid = stoi(vec->at(WIDTH));
	}
	catch(std::invalid_argument const&ex){
		std::cerr << "invalid argument " << ex.what() << '\n';
		throw; 
	}

	values->push_back(wid);
	values->push_back(hei);

	return 0;
}
