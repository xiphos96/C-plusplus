// ÆÄÀÏ¸í : Hello.h
#include "IHello.h"

class CHello : public IHello, 
			   public IGoodbye
{
public:
	char* sayHello(char* name);
	char* sayGoodbye(char* name);
private:
	char buf[256];
};
