#include "ListaSformatowana.h"
ListaSformatowana::ListaSformatowana(int ile) : Lista(ile) {};
string ListaSformatowana::format(string txt_p)
{
	if (txt_p.empty()) return "";
	if (txt_p[txt_p.length() - 1] == '.')
		return txt_p;
	else
		return txt_p + ".";
};

