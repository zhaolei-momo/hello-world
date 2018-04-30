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
