#include "rpn.h"

int main()
{
	char s[256];
	char rpn[256] = "(A + B)/C + D * A";
	
	translate_to_rpn(s, rpn);
	printf("%s", s);
	return 0;
}