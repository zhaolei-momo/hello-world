[参考原文地址](https://www.cnblogs.com/fnlingnzb-learner/p/6424563.html)  
头文件  
```cpp
#include<io.h>
```
主函数
```cpp
vector<string> files;  
  
////获取该路径下的所有文件  
getFiles(filePath, files );  
  
char str[30];  
int size = files.size();  
for (int i = 0;i < size;i++)  
{  
    cout<<files[i].c_str()<<endl;  
}
```

```cpp
void getFiles( string path, vector<string>& files )  
{  
    //文件句柄  
    long   hFile   =   0;  
    //文件信息  
    struct _finddata_t fileinfo;  
    string p;  
    if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)  
    {  
        do  
        {  
            //如果是目录,迭代之  
            //如果不是,加入列表  
            if((fileinfo.attrib &  _A_SUBDIR))  
            {  
                if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)  
                    getFiles( p.assign(path).append("\\").append(fileinfo.name), files );  
            }  
            else  
            {  
                files.push_back(p.assign(path).append("\\").append(fileinfo.name) );  
            }  
        }while(_findnext(hFile, &fileinfo)  == 0);  
        _findclose(hFile);  
    }  
}
```

＃＃＃＃＃＃＃＃＃＃＃＃＃

另外附录可以在VS执行但是在QT会报错的代码和链接（https://blog.csdn.net/idmer/article/details/53524443）

#include "stdafx.h"
#include <stdio.h>
#include<iostream>
#include<vector>
#include <Windows.h>
#include <fstream>  
#include <iterator>
#include <string>
using namespace std;

#define MAX_PATH 1024  //最长路径长度

/*---------------------------- 
 * 功能 : 递归遍历文件夹，找到其中包含的所有文件
 *---------------------------- 
 * 函数 : find
 * 访问 : public  
 * 
 * 参数 : lpPath [in]      需遍历的文件夹目录
 * 参数 : fileList [in]    以文件名称的形式存储遍历后的文件 
 */
void find(char* lpPath,std::vector<const std::string> &fileList)
{
   char szFind[MAX_PATH];
   WIN32_FIND_DATA FindFileData;
   
   strcpy(szFind,lpPath);
   strcat(szFind,"\\*.*");

   HANDLE hFind=::FindFirstFile(szFind,&FindFileData);
   if(INVALID_HANDLE_VALUE == hFind)    return;

   while(true)
   {
		if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            if(FindFileData.cFileName[0]!='.')
            {
				char szFile[MAX_PATH];
                strcpy(szFile,lpPath);
                strcat(szFile,"\\");
				strcat(szFile,(char* )(FindFileData.cFileName));
                find(szFile,fileList);
            }
        }
        else
        {
			//std::cout << FindFileData.cFileName << std::endl;
			fileList.push_back(FindFileData.cFileName);
        }
        if(!FindNextFile(hFind,&FindFileData))    break;
   }
   FindClose(hFind);
}


int main()
{
	std::vector<const std::string> fileList;//定义一个存放结果文件名称的链表

	//遍历一次结果的所有文件,获取文件名列表
	find("XXXX具体文件夹目录",fileList);//之后可对文件列表中的文件进行相应的操作

	//输出文件夹下所有文件的名称
	for(int i = 0; i < fileList.size(); i++)
	{
		cout << fileList[i] << endl;
	}
	cout << "文件数目：" << fileList.size() << endl;
	return 0;
}
