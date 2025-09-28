# OpenCV & C++

This code follows the tutorial presented at [this youtube playlist tutorial](https://youtube.com/playlist?list=PLUTbi0GOQwghR9db9p6yHqwvzc989q_mu&si=IQo60Ht2uCPmS9Gj).

## Tutorial 00: Instalation
### Installing from source

To install from source let's go through the following steps
```bash
sudo apt update && sudo apt upgrade
```

Now we clone the OpenCV source code repository by running the following command:
```bash
git clone https://github.com/opencv/opencv.git
```

Create a build directory and navigate to it by running the following commands:
```bash
cd opencv
mkdir build
cd build
```

Configure the build by running the following command:
```bash
cmake -D CMAKE_BUILT_TYPE=Release \
      -D CMAKE_INSTALL_PREFIX=/usr/local \
      -D OPENCV_GENERATE_PKGCONFIG=ON ..
```

Build and install OpenCV by running the following commands:
```bash
make -j8
sudo make install
```

Verify that OpenCV is installed correctly by running the following command,
```bash
pkg-config --modversion opencv4
```
the output must be something like:
```PlainText
4.13.0
```

### Addig library to source path

To add the library to source path permanetly, we need to execute,
```bash
echo "/usr/local/lib/" | sudo tee /etc/ld.so.conf.d/opencv.conf
sudo ldconfig
```
and to visualize if this have been successfull, we execute,
```bash
ldconfig -p | grep opencv
```
this generates the output
```PlainText
libopencv_videoio.so.413 (libc6,x86-64) => /usr/local/lib/libopencv_videoio.so.413
libopencv_videoio.so (libc6,x86-64) => /usr/local/lib/libopencv_videoio.so
...
```

### Testing Installation

Let's make a short program to test the installation of the libray.
```cpp
#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img(200, 200, CV_8UC3, cv::Scalar(0,255,0));
    if(img.empty()) {
        std::cerr << "Error: OpenCV not working!" << std::endl;
        return -1;
    }
    std::cout << "OpenCV is working! Version: " << CV_VERSION << std::endl;
    return 0;
}
```

Let's compile it and execute it
```bash
g++ main.cpp -o main.x `pkg-config --cflags --libs opencv4`
./main.x
```
which output must be,
```PlainText
OpenCV is working! Version: 4.13.0-dev
```


## Tutorial 01