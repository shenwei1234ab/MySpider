#include <dlfcn.h>
//#include "mySo.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//http://blog.chinaunix.net/uid-26000296-id-3778641.html
//c++ 必须这么写,负责无法被动态的调用
extern "C"
{

	void test()
	{
		std::cout<<"test function"<<std::endl;
	}

	 struct hello_ST_API
	{
	 const char *module;
	 int  (*GetValue)(char *pszVal);
	 int   (*PrintfHello)();
	};


	int GetValue(char *pszVal)
	{
	 int retval = -1;

	 if (pszVal)
	  retval = sprintf(pszVal, "%s", "123456");
	  printf("%s, %d, pszVer = %s\n", __FUNCTION__, __LINE__, pszVal);
	 return retval;
	}

	int PrintfHello()
	{
	 int retval = -1;

	 printf("%s, %d, hello everyone\n", __FUNCTION__, __LINE__);
	 return 0;
	}

	hello_ST_API Hello ={"hello",GetValue,PrintfHello};

}
