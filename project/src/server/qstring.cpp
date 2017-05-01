#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include "qstring.h"

char * strcat2(int argc, const char *str1, const char * str2, ...) 
{
    int tmp = 0;
    char *dest = NULL;
    char *cur = NULL;
    va_list va_ptr;
    size_t len = strlen(str1) + strlen(str2);

    argc -= 2;
    tmp = argc;

    va_start(va_ptr, str2);
    while(argc-- && (cur = va_arg(va_ptr,char *))) {
        len += strlen(cur);
    }
    va_end(va_ptr);

    dest = (char *)malloc(len+1);
    dest[0] = '\0';
    strcat(dest, str1);
    strcat(dest, str2);

    argc = tmp;
    va_start(va_ptr, str2);
    while(argc-- && (cur = va_arg(va_ptr,char *))) {
        strcat(dest, cur);
    }
    va_end(va_ptr);

    return dest;
}

char * strim(char *str)
{
    char *end, *sp, *ep;
    size_t len;

    sp = str;
    end = ep = str+strlen(str)-1;
    while(sp <= end && isspace(*sp)) sp++;
    while(ep >= sp && isspace(*ep)) ep--;
    len = (ep < sp) ? 0 : (ep-sp)+1;
    sp[len] = '\0';
    return sp;
}


char ** strsplit(char *line, char delimeter, int *count, int limit)
{
    char *ptr = NULL, *str = line;
    char **vector = NULL;

    *count = 0;
    while((ptr = strchr(str, delimeter))) {
        *ptr = '\0';
        vector = (char **)realloc(vector,((*count)+1)*sizeof(char *));
        vector[*count] = strim(str);
        str = ptr+1;
        (*count)++;	
        if (--limit == 0) break;
    }
    if (*str != '\0') {
        vector = (char **)realloc(vector,((*count)+1)*sizeof(char *));
        vector[*count] = strim(str);
        (*count)++;
    }
    return vector;
}

//字符串分割函数
void StrSplit(const std::string& src, const std::string& separator, std::vector<std::string>& dest)
{
	if(src == "")
	{
		return ;
	}
	std::string str = src;
	std::string substring;
	std::string::size_type start = 0, index;

	do
	{
		index = str.find_first_of(separator, start);
		if (index != std::string::npos)
		{
			substring = str.substr(start, index - start);
			dest.push_back(substring);
			start = str.find_first_not_of(separator, index);
			if (start == std::string::npos) return;
		}
	} while (index != std::string::npos);

	//the last token
	substring = str.substr(start);
	dest.push_back(substring);
}
int yesnotoi(const char *str)
{
    if (strcasecmp(str,"yes") == 0) return 1;
    if (strcasecmp(str,"no") == 0) return 0;
    return -1;
}
