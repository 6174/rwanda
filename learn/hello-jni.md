## android jni hello world

## mac 配置tips

1. 用eclipse才能玩NDK, intellij dame
2. 下载NDK, SDK, GenyMotion , 官网可以吧sdk和eclipse一起下载， 配置ANDROID_SDK_HOME, ANDROID_NDK_HOME, 以及吧platform tools和你ndk-build 等放到path中
3. NDK plugin 配置：
  1. eclipse -> help -> new software -> https://dl-ssl.google.com/android/eclipse   更新developtools 全选安装， 没有NDK Plugin 可以选择， 应该是整合到了developtools里边了，
  2. 这个配置好了应该可以找到 eclipse -> preference -> NDK ， 然后设置NDK路径 。 
  3. 新建项目， 项目的右键 -> android tools -> enable native ..
  4. c++ 老是错误提示， 这个时候配置项目preference 选择c++, 去除语法检查
4. javah 配置 
    1.  javah -classpath bin/classes:{$ANDROID_SDK_HOME}/platforms/android20/android.jar  -d jni com.rwanda.hellojni.HelloJni 这样是不行的
    2. 直接cd到src目录，  javah -d ../jni com.rwanda.hellojni.HelloJni 

5. 使用swig来生成jni 
 ```shell 
    brew install swig
    swig -java -package com.apress.swig -outdir src/com/apress/swig jni/Unix.i
 ```
 
 swig java文档： http://www.swig.org/Doc2.0/Java.html
 swig android文档： http://www.swig.org/Doc2.0/Android.html