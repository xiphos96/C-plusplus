export module mymodule;

int f_private()
{
	return 456;
}

export int f()
{
	return f_private();
}