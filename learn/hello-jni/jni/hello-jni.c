/**
 * hello-jni implementation
 * @author 6174
 */
#include <string.h>
#include <jni.h>
#include <android/log.h>

#define  LOG_TAG    "rwanda"

#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
/**
 *  @param JNIEnv 是一个接口指针， 指向可用的JNI 函数表,
 *         thread-local data which contains a pointer to JNIEnv interface pointer
 *  @param jobject, HelloJni类的引用
 *
 *  @desc1
 *  在c 和 c++ 中使用方式不同
 *    c: JNIEnv 指向 JNINativeInterface 结构，必须通过提领操作符获取结构体，JNI函数不知道当前的JNI环境，所以必须吧env 作为参数传入
 *       使用方式为(*env)->NewStringUTF(env,"asdfasd");
 *    c++: JNIEnv是一个c++ class,所以是可以这样使用：
 *       env->NewStringUTF("asdasd");
 *
 *  @desc2
 *  类和实例方法的定义不同
 *  实例方法： (JNIEnv *env, jobject context)
 *  类方法：(JNIEnv *env, jclass  clazz)
 *
 *
 *  @desc3
 *  Java         JNI          C/C++
 *  Boolean      Jboolean     unsigned char
 *  Byte         Jbyte        char
 *  Char         Jchar        unsigned short
 *  Short        Jshort       short
 *  Int          Jint         int
 *  Long         Jlong        long long
 *  Float        Jfloat       float
 *  Double       Jdouble      double
 *
 *  Java type                   Native type
 *  java.lang.Class             jclass
 *  java.lang.Throwable         jthrowable
 *  java.lang.string            jstring
 *  Other objects               jobject
 *  java.lang.Object[]          jobjectArray
 *  boolean[]                   jbooleanArray
 *  ....                        j....Array
 *  Other arrays                jarray
 *
 *
 *  @desc4
 *  操作引用类型: Strings, Arrays, NIO Buffers Fields, Methods
 */
jstring
Java_com_rwanda_hellojni_HelloJni_stringFromJNI( JNIEnv* env, jobject context)
{
	// javaString
	jstring javaString;
	// 如果出现异常情况，会返回null
	javaString = (*env)->NewStringUTF(env, "hello world from JNI");
	// java string -> c string
    const jbyte* str;
    jboolean isCopy;
    str = (*env)->GetStringUTFChars(env, javaString, &isCopy);
    if (0 != str) {
    	LOGD("Java string : %s", str);

    	if (JNI_TRUE == isCopy) {
    		LOGD("C string is a copy of the Java string");
    	} else {
    		LOGD("C string points to actual string");
    	}
    }

    (*env)->ReleaseStringUTFChars(env, javaString, str);
    return javaString;
}
