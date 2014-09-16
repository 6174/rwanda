/**
 * hello-jni implementation
 * @author 6174
 */
#include <string.h>
#include <jni.h>

jstring
Java_com_rwanda_hellojni_HelloJni_stringFromJNI( JNIEnv* env, jobject context)
{
     return (*env)->NewStringUTF(env, "Hello from JNSadI");
}
