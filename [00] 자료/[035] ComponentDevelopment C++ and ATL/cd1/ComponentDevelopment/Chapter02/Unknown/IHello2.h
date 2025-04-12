// ÆÄÀÏ¸í : IHello2.h
enum IID
{
	IID_IUnknown,
	IID_IHello,
	IID_IGoodbye
};

class IUnknown
{
public:
	virtual bool QueryInterface(IID iid, void** ppv) = 0;
	virtual int AddRef() = 0;
	virtual int Release() = 0;
};

class IHello : public IUnknown
{
public:
	virtual char* sayHello(char* name) = 0;
};

class IGoodbye : public IUnknown
{
public:
	virtual char* sayGoodbye(char* name) = 0;
};

extern IUnknown* CreateInstance();
