#include "Header.h"

String^ delSpace(String^ str)
{
	str = str->Trim();
	while (str->IndexOf("  ") >= 0)
		str = str->Replace("  ", " ");
	return str;
}

String^ getStr(array<String^>^ arr, int& c)
{
	String^ out = "";
	for each (String ^ s in arr) {
		if (s->Length % 2 != 0)
		{
			int pos = floor(s->Length / 2);
			out += s->Remove(pos, 1) + " ";
			c++;
		}
		else 
			out +=  s + " ";
	}
	return delSpace(out);
}

String^ f(String^ in, int& count) 
{
	delSpace(in);
	array <TCHAR>^ dlm = { ' ' };
	array <String^>^ words = in->Split(dlm);
	String^ out = getStr(words, count);
	return out;
}
