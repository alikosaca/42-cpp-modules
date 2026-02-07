#include "Sed.hpp"

Sed::Sed(const std::string& fileName, const std::string s1, const std::string s2) : fileName(fileName), s1(s1), s2(s2){}

Sed::~Sed(){}

void Sed::Replace() {
	std::ifstream myFile(this->fileName.c_str());
	if (!myFile.is_open()) {
	    std::cerr << "Hata: Dosya acilamadi." << std::endl;
	    return;
	}

	std::ofstream outFile((this->fileName + ".replace").c_str());
	if (!outFile.is_open()) {
	    std::cerr << "Hata: Olusturma dosyasi acilamadi." << std::endl;
	    myFile.close();
	    return;
	}

    std::string line;
    while (std::getline(myFile, line)) {
		std::string res;
		size_t lastPos = 0;
		size_t pos = 0;

		while ((pos = line.find(this->s1, lastPos)) != std::string::npos) {
		    res += line.substr(lastPos, pos - lastPos);
		    res += this->s2;
		    lastPos = pos + this->s1.length();
		}
		res += line.substr(lastPos);
		outFile << res;
		if (!myFile.eof()) {
		    outFile << std::endl;
		}
    }

    myFile.close();
    outFile.close();
}