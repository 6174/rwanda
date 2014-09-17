package com.rwanda.hellojni;

/* 
This class has a number of native method's and fields that
are accessed from native method.
JNI is used to implement the native methods.
These examples also show how to access fields of this class
from Native Methods
*/

public class JNITest {

public native void arg0Test();

public native void arg1Test(int arg1);
public native void arg1Test(double arg1);
public native void arg1Test(long arg1);
public native void arg1Test(char arg1);


public native void arg2Test(int arg1, int arg2);
public native void arg2Test(long arg1, long arg2);
public native void arg2Test(double arg1, double arg2);
public native void arg2Test(char arg1, char arg2);

public native void arg6Test(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
public native void arg6Test(double arg1, double arg2, double arg3, double arg4, double arg5, double arg6);

public native int arg0TestI();
public native double arg0TestD();


static {
  System.loadLibrary("arg-native");
}

public char field1;
public int field2;
public char dummy1;
public long field3;
public float field4;
public char dummy2;
public double field5;

public Character FF1()   { return new Character (field1); }
public Integer   FF2()   { return new Integer (field2); }
public Long      FF3()   { return new Long (field3); }
public Float     FF4()   { return new Float(field4); }
public Double    FF5()   { return new Double(field5); } 

public char   f1() { return field1; }
public int    f2() { return field2; }
public long   f3() { return field3; }
public float  f4() { return field4; }
public double f5() { return field5; }

public native void nativeAccessTest();
public native void nativeInvokeTest();

public static void main(String[] args) {
 JNITest myTest = new JNITest();

 // Assign all the fields
 myTest.field1 = 'a';
 myTest.field2 = 2718;
 myTest.field3 = 2718281;
 myTest.field4 = (float) 3.1415;
 myTest.field5 = 3.14159265;


 System.out.println();
 System.out.println("------- Arg0 Testing ---------\n");
 System.out.println();

 myTest.arg0Test();

 System.out.println();
 System.out.println("------- Arg1 Testing ---------\n");
 System.out.println();
 myTest.arg1Test(2718);
 myTest.arg1Test(2.718);
 myTest.arg1Test((long) 27182);
 myTest.arg1Test('a');

 System.out.println();
 System.out.println("------- Arg2 Testing ---------\n");
 System.out.println();
 myTest.arg2Test(2718, 31415);
 myTest.arg2Test((long) 27182, (long) 314159);
 myTest.arg2Test(2.718, 3.1415926);
 myTest.arg2Test('a', 'b');

 System.out.println();
 System.out.println("------- Arg6 Testing ---------\n");
 System.out.println();
 myTest.arg6Test(27, 31, 271, 314, 2718, 3141);
 myTest.arg6Test(2.7, 3.1, 2.71, 3.14, 2.718, 3.141);


 System.out.println();
 System.out.println("------- Arg0 Testing returns int---------\n");
 System.out.println();
 
 int ix = myTest.arg0TestI();
 System.out.println("arg0 Test return = " + ix + "\n");

 System.out.println();
 System.out.println("------- Arg0 Testing returns double---------\n");
 System.out.println();
 
 double dx = myTest.arg0TestD();
 System.out.println("arg0 Test return = " + dx + "\n");

 System.out.println();
 System.out.println("------- Field Access (from Native world) ---------\n");
 System.out.println();
 System.out.println(" Field values in Java World \n");
 System.out.println("myTest.field1 = "+myTest.field1
                    +"\n myTest.field2 = "+myTest.field2 
                    +"\n myTest.field3 = "+myTest.field3 
                    +"\n myTest.field4 = "+myTest.field4 
                    +"\n myTest.field5 = "+myTest.field5); 

 System.out.println("\nField values in Native World \n");
 myTest.nativeAccessTest();

 System.out.println();
 System.out.println("------- Method calls (from Native World) ---------\n");
 System.out.println();
 System.out.println(" Field values (using getters) in Java World \n");
 System.out.println("myTest.FF1() = "+myTest.FF1().toString() 
                    +"\n myTest.FF2() = "+myTest.FF2().toString()  
                    +"\n myTest.FF3() = "+myTest.FF3().toString()  
                    +"\n myTest.FF4() = "+myTest.FF4().toString()  
                    +"\n myTest.FF5() = "+myTest.FF5().toString()); 

 System.out.println("\nField values (using getters) in Native World \n");
 myTest.nativeInvokeTest();
}
}