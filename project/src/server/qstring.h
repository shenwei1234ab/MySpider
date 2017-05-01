#ifndef QSTRING_H
#define QSTRING_H
#include <string>
#include <vector>
/* 拼接多个字符串
 * argc: the number of strings
 */
extern char * strcat2(int argc, const char *str1, const char * str2, ...);

/* 剪切字符串，不重新分配内存 */
extern char * strim(char *str);

/* 分割字符串
 * count: 分割后的字符串长度
 * limit: 分割多少次
 */
extern char ** strsplit(char *line, char delimeter, int *count, int limit);


extern void StrSplit(const std::string& src, const std::string& separator, std::vector<std::string>& dest);


/* 把字符串yes或no转换成整形, 错误返回-1 
 */
extern int yesnotoi(const char *str);

#endif
