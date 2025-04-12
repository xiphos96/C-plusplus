// ÆÄÀÏ¸í : IHello.h 
class IHello
{
public:
	virtual char* sayHello(char* name) = 0;
};

class IGoodbye
{
public:
	virtual char* sayGoodbye(char* name) = 0;
};

extern IHello* CreateInstance();
extern IGoodbye* QueryInterface(IHello* p);