#pragma once
#include "Lista.h"
class ListaSformatowana : public Lista
{
public:
	ListaSformatowana(int ile);
private:	
	string format(string txt_p);
};

