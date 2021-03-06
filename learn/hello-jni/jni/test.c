/*
 * test.c
 *
 *  Created on: 2014-9-17
 *      Author: admin
 */


/* JNITest.h generated by applying javah
   on the Java class, and contains the
   function declaration for the native method
*/
#include "JNITest.h"

/* used for printf */
#include "stdio.h"

/* Signatures of several of these are in JNITest.h */

void Java_JNITest_arg0Test(JNIEnv *env, jobject obj) {
  printf("arg0Test: Welcome to the brave new world of JNI -- Java Native Interface\n");
}

void Java_JNITest_arg1Test__I(JNIEnv *env, jobject obj, jint arg1) {
  printf("arg1Test: Testing passing of integers !\n");
  printf("arg1Test: Arg1 = %d\n", arg1);
}

void Java_JNITest_arg1Test__D(JNIEnv *env, jobject obj, jdouble arg1) {
  printf("arg1Test: Testing passing of doubles !\n");
  printf("arg1Test: Arg1 = %f\n", arg1);
}

void Java_JNITest_arg1Test__J(JNIEnv *env, jobject obj, jlong arg1) {
  printf("arg1Test: Testing passing of longs !\n");
  printf("arg1Test: Arg1 = %lld\n", arg1);
}

void Java_JNITest_arg1Test__C(JNIEnv *env, jobject obj, jchar arg1) {
  printf("arg1Test: Testing passing of chars !\n");
  printf("arg1Test: Arg1 = %c\n", arg1);
}

void Java_JNITest_arg2Test__II(JNIEnv *env, jobject obj, jint arg1, jint arg2) {
  printf("arg2Test: Testing passing of two integers !\n");
  printf("arg2Test: Arg1 = %d   Arg2 = %d\n", arg1, arg2);
}

void Java_JNITest_arg2Test__JJ(JNIEnv *env, jobject obj, jlong arg1, jlong arg2) {
  printf("arg2Test: Testing passing of two longs !\n");
  printf("arg2Test: Arg1 = %lld   Arg2 = %lld\n", arg1, arg2);
}

void Java_JNITest_arg2Test__DD(JNIEnv *env, jobject obj, jdouble arg1, jdouble arg2) {
  printf("arg2Test: Testing passing of two doubles !\n");
  printf("arg2Test: Arg1 = %f   Arg2 = %f\n", arg1, arg2);
}

void Java_JNITest_arg2Test__CC(JNIEnv *env , jobject obj, jchar arg1, jchar arg2) {
  printf("arg2Test: Testing passing of two chars !\n");
  printf("arg2Test: Arg1 = %c   Arg2 = %c\n", arg1, arg2);
}

void Java_JNITest_arg6Test__IIIIII(JNIEnv *env , jobject obj, jint arg1, jint arg2, jint arg3, jint arg4, jint arg5, jint arg6 ) {
  printf("arg6Test: Testing passing of six integers !\n");
  printf("arg6Test: Arg1 = %d   Arg2 = %d, Arg 3 = %d\n", arg1, arg2, arg3);
  printf("          Arg4 = %d   Arg5 = %d, Arg 6 = %d\n", arg4, arg5, arg6);
}

void Java_JNITest_arg6Test__DDDDDD(JNIEnv *env , jobject obj, jdouble arg1, jdouble arg2, jdouble arg3, jdouble arg4, jdouble arg5, jdouble arg6 ) {
  printf("arg6Test: Testing passing of six doubles !\n");
  printf("arg6Test: Arg1 = %g   Arg2 = %g, Arg 3 = %g\n", arg1, arg2, arg3);
  printf("          Arg4 = %g   Arg5 = %g, Arg 6 = %g\n", arg4, arg5, arg6);
}

jint Java_JNITest_arg0TestI(JNIEnv *env, jobject obj) {

  printf("arg0Test: Testing returning of ints !\n");
  return 31415;
}

jdouble Java_JNITest_arg0TestD(JNIEnv *env, jobject obj) {

  printf("arg0Test: Testing returning of doubles !\n");
  return 3.141592654;
}

/* Used to access fields of Java. Testing access of misalinged fields
   as well
*/
void Java_JNITest_nativeAccessTest(JNIEnv *env, jobject obj) {

   jfieldID fid1;
   jfieldID fid2;
   jfieldID fid3;
   jfieldID fid4;
   jfieldID fid5;
   jclass cobj;

   printf("In nativeAccessTest (native) function \n");
   cobj = (*env)->GetObjectClass(env, obj);

   fid1 = (*env)->GetFieldID(env, cobj, "field1", "C");
   printf("myTest.field1 = %18c\n", (*env)->GetCharField(env, obj, fid1));

   fid2 = (*env)->GetFieldID(env, cobj, "field2", "I");
   printf("myTest.field2 = %18d\n", (*env)->GetIntField(env, obj, fid2));

   fid3 = (*env)->GetFieldID(env, cobj, "field3", "J");
   printf("myTest.field3 = %18lld\n", (*env)->GetLongField(env, obj, fid3));

   fid4 = (*env)->GetFieldID(env, cobj, "field4", "F");
   printf("myTest.field4 = %18.9g\n", (*env)->GetFloatField(env, obj, fid4));

   fid5 = (*env)->GetFieldID(env, cobj, "field5", "D");
   printf("myTest.field5 = %18.9g\n", (*env)->GetDoubleField(env, obj, fid5));
}

/* Used to call methods of Java.
*/
void Java_JNITest_nativeInvokeTest(JNIEnv *env, jobject obj) {

   jmethodID mid1;
   jmethodID mid2;
   jmethodID mid3;
   jmethodID mid4;
   jmethodID mid5;
   jclass cobj;

   printf("In nativeInvokeTest (native) function \n");
   cobj = (*env)->GetObjectClass(env, obj);

   mid1 = (*env)->GetMethodID(env, cobj, "f1", "()C");
   printf("myTest.f1() = %18c\n", (*env)->CallCharMethod(env, obj, mid1));

   mid2 = (*env)->GetMethodID(env, cobj, "f2", "()I");
   printf("myTest.f2() = %18d\n", (*env)->CallIntMethod(env, obj, mid2));

   mid3 = (*env)->GetMethodID(env, cobj, "f3", "()J");
   printf("myTest.f3() = %18lld\n", (*env)->CallLongMethod(env, obj, mid3));

   mid4 = (*env)->GetMethodID(env, cobj, "f4", "()F");
   printf("myTest.f4() = %18.9g\n", (*env)->CallFloatMethod(env, obj, mid4));

   mid5 = (*env)->GetMethodID(env, cobj, "f5", "()D");
   printf("myTest.f5() = %18.9g\n", (*env)->CallDoubleMethod(env, obj, mid5));
}


