

CPU 占用高解决方案 

[$ sudo kill -s 9 PID](https://blog.csdn.net/andy572633/article/details/7211546) 

[$ sudo service lightdm restart](https://blog.programster.org/restart-ubuntu-gui)

其中-s 9 制定了传递给进程的信号是９，即强制、尽快终止进程。各个终止信号及其作用见附录。

显存因为GPU0溢出，可以用下面方法设置 
CUDA_VISIBLE_DEVICES=1 python demo_MNIST.py
