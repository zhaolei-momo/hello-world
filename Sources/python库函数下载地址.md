https://www.lfd.uci.edu/~gohlke/pythonlibs/#opencv

https://blog.csdn.net/xdygzsxg/article/details/53885786

安装方法  
sklearn：提供了一些简单而有效的工具用于数据挖掘和数据分析。而安装时出现“ImportError: No module named 'sklearn'”的错误，经查找资料，解决办法如下：


查看官网发现sklearn安装需要如下依赖：
Installation
Dependencies
scikit-learn requires:

Python (>= 2.6 or >= 3.3)
NumPy (>= 1.6.1)
SciPy (>= 0.9)
sklearn包下载地址： 
https://pypi.python.org/pypi/scikit-learn/0.18.1 
numpy+mkl： 
http://www.lfd.uci.edu/~gohlke/pythonlibs/ 
scipy： 
http://www.lfd.uci.edu/~gohlke/pythonlibs/ 
强烈推荐python安装包大全网站：

http://www.lfd.uci.edu/~gohlke/pythonlibs/#numpy

最后，按照numpy+mkl->scipy->sklearn的顺序一步步在cmd下 pip install+包的绝对路径 即可，import sklearn结果OK。
