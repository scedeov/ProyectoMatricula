#ifndef OBJETOBASE
#define OBJETOBASE

#include <string>

class objetoBase {
protected:
	std::string id;
public:
	std::string getID();
	void setID(std::string);
	virtual std::string toString() = 0;
};

#endif // !OBJETOBASE
