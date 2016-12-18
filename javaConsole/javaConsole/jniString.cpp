#include <stdlib.h>
#include <string.h>
#include <jni.h>
/* 효율성을 높이기 위한 캐슁 변수 */
static jclass class_String;
static jmethodID mid_getBytes, mid_getBytesEncoding;
static jmethodID mid_newString, mid_newStringEncoding;

/* 자바 바이트 배열로부터 C 문자열을 생성하여 반환
*/
char *jbyteArray2cstr(JNIEnv *env, jbyteArray javaBytes)
{
	size_t len = env->GetArrayLength(javaBytes);
	jbyte *nativeBytes = env->GetByteArrayElements(javaBytes, 0);
	char *nativeStr = (char *)malloc(len + 1);
	strncpy(nativeStr, (char *)nativeBytes, len); /* AIX cc컴파일러가 CAST WARNNING을 발생하여 변경 */
	nativeStr[len] = '\0';
	env->ReleaseByteArrayElements(javaBytes, nativeBytes, JNI_ABORT);
	return nativeStr; /* ML(Memory Loss 발생 */
}
/* C 문자열로부터 자바 바이트 배열을 생성하여 반환
*/
jbyteArray cstr2jbyteArray(JNIEnv *env, const char *nativeStr)
{
	jbyteArray javaBytes;
	int len = strlen(nativeStr);
	javaBytes = env->NewByteArray(len);
	env->SetByteArrayRegion(javaBytes, 0, len, (jbyte *)nativeStr);
	return javaBytes;
}

/* 자바 스트링을 디폴트 인코딩의 자바 바이트 배열로 변환.
* String 클래스의 getBytes() 메쏘드를 호출한다.
*/
jbyteArray javaGetBytes(JNIEnv *env, jstring str)
{
	if (mid_getBytes == 0)
	{
		if (class_String == 0)
		{
			jclass cls = env->FindClass("java/lang/String");
			if (cls == 0)
				return 0;  /* 오류 */
			class_String = (jclass)env->NewGlobalRef(cls);
			if (class_String == 0)
				return 0;  /* 오류 */
		}
		mid_getBytes = env->GetMethodID(class_String, "getBytes", "()[B");
		if (mid_getBytes == 0)
			return 0;
	}
	/* str.getBytes(); */
	return (jbyteArray)env->CallObjectMethod(str, mid_getBytes);
}

/* 자바 스트링을 지정된 인코딩 `encoding'의 자바 바이트 배열로 변환.
* String 클래스의 getBytes(String encoding) 메쏘드를 호출한다.
*/
jbyteArray javaGetBytesEncoding(JNIEnv *env, jstring str, const char *encoding)
{
	if (mid_getBytesEncoding == 0)
	{
		if (class_String == 0)
		{
			jclass cls = env->FindClass("java/lang/String");
			if (cls == 0)
				return 0;  /* 오류 */
			class_String = (jclass)env->NewGlobalRef(cls);
			if (class_String == 0)
				return 0;  /* 오류 */
		}
		mid_getBytesEncoding = env->GetMethodID(class_String, "getBytes", "(Ljava/lang/String;)[B");
		if (mid_getBytesEncoding == 0)
			return 0;
	}
	/* str.getBytes( encoding ); */
	return (jbyteArray)env->CallObjectMethod(str, mid_getBytesEncoding, env->NewStringUTF(encoding));
}

/* 디폴트 인코딩의 자바 바이트 배열을 자바 스트링으로 변환.
* String 클래스의 new String(byte[] bytes) 메쏘드를 호출한다.
*/
jstring javaNewString(JNIEnv *env, jbyteArray javaBytes)
{
	if (mid_newString == 0)
	{
		if (class_String == 0)
		{
			jclass cls = env->FindClass("java/lang/String");
			if (cls == 0)
				return 0;  /* 오류 */
			class_String = (jclass)env->NewGlobalRef(cls);
			if (class_String == 0)
				return 0;  /* 오류 */
		}
		mid_newString = (jmethodID)env->GetMethodID(class_String, "<init>", "([B)V");
		if (mid_newString == 0)
			return 0;
	}
	/* new String( javaBytes ); */
	return (jstring)env->NewObject(class_String, mid_newString, javaBytes);
}

/* 지정된 인코딩 `encoding'의 자바 바이트 배열을 자바 스트링으로 변환.
* String 클래스의 new String(byte[] bytes, String encoding)
* 메쏘드를 호출한다.
*/
jstring javaNewStringEncoding(
	JNIEnv *env, jbyteArray javaBytes, const char *encoding)
{
	jstring str;
	if (mid_newString == 0)
	{
		if (class_String == 0)
		{
			jclass cls = env->FindClass("java/lang/String");
			if (cls == 0)
				return 0;  /* 오류 */
			class_String = (jclass)env->NewGlobalRef(cls);
			if (class_String == 0)
				return 0;  /* 오류 */
		}
		mid_newString = (jmethodID)env->GetMethodID(class_String, "<init>", "([BLjava/lang/String;)V");
		if (mid_newString == 0)
			return 0;
	}
	/* new String( javaBytes, encoding ); */
	str = (jstring)env->NewObject(class_String, mid_newString, javaBytes,
		env->NewStringUTF(encoding));
	return str;
}