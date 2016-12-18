#include <stdlib.h>
#include <string.h>
#include <jni.h>
/* ȿ������ ���̱� ���� ĳ�� ���� */
static jclass class_String;
static jmethodID mid_getBytes, mid_getBytesEncoding;
static jmethodID mid_newString, mid_newStringEncoding;

/* �ڹ� ����Ʈ �迭�κ��� C ���ڿ��� �����Ͽ� ��ȯ
*/
char *jbyteArray2cstr(JNIEnv *env, jbyteArray javaBytes)
{
	size_t len = env->GetArrayLength(javaBytes);
	jbyte *nativeBytes = env->GetByteArrayElements(javaBytes, 0);
	char *nativeStr = (char *)malloc(len + 1);
	strncpy(nativeStr, (char *)nativeBytes, len); /* AIX cc�����Ϸ��� CAST WARNNING�� �߻��Ͽ� ���� */
	nativeStr[len] = '\0';
	env->ReleaseByteArrayElements(javaBytes, nativeBytes, JNI_ABORT);
	return nativeStr; /* ML(Memory Loss �߻� */
}
/* C ���ڿ��κ��� �ڹ� ����Ʈ �迭�� �����Ͽ� ��ȯ
*/
jbyteArray cstr2jbyteArray(JNIEnv *env, const char *nativeStr)
{
	jbyteArray javaBytes;
	int len = strlen(nativeStr);
	javaBytes = env->NewByteArray(len);
	env->SetByteArrayRegion(javaBytes, 0, len, (jbyte *)nativeStr);
	return javaBytes;
}

/* �ڹ� ��Ʈ���� ����Ʈ ���ڵ��� �ڹ� ����Ʈ �迭�� ��ȯ.
* String Ŭ������ getBytes() �޽�带 ȣ���Ѵ�.
*/
jbyteArray javaGetBytes(JNIEnv *env, jstring str)
{
	if (mid_getBytes == 0)
	{
		if (class_String == 0)
		{
			jclass cls = env->FindClass("java/lang/String");
			if (cls == 0)
				return 0;  /* ���� */
			class_String = (jclass)env->NewGlobalRef(cls);
			if (class_String == 0)
				return 0;  /* ���� */
		}
		mid_getBytes = env->GetMethodID(class_String, "getBytes", "()[B");
		if (mid_getBytes == 0)
			return 0;
	}
	/* str.getBytes(); */
	return (jbyteArray)env->CallObjectMethod(str, mid_getBytes);
}

/* �ڹ� ��Ʈ���� ������ ���ڵ� `encoding'�� �ڹ� ����Ʈ �迭�� ��ȯ.
* String Ŭ������ getBytes(String encoding) �޽�带 ȣ���Ѵ�.
*/
jbyteArray javaGetBytesEncoding(JNIEnv *env, jstring str, const char *encoding)
{
	if (mid_getBytesEncoding == 0)
	{
		if (class_String == 0)
		{
			jclass cls = env->FindClass("java/lang/String");
			if (cls == 0)
				return 0;  /* ���� */
			class_String = (jclass)env->NewGlobalRef(cls);
			if (class_String == 0)
				return 0;  /* ���� */
		}
		mid_getBytesEncoding = env->GetMethodID(class_String, "getBytes", "(Ljava/lang/String;)[B");
		if (mid_getBytesEncoding == 0)
			return 0;
	}
	/* str.getBytes( encoding ); */
	return (jbyteArray)env->CallObjectMethod(str, mid_getBytesEncoding, env->NewStringUTF(encoding));
}

/* ����Ʈ ���ڵ��� �ڹ� ����Ʈ �迭�� �ڹ� ��Ʈ������ ��ȯ.
* String Ŭ������ new String(byte[] bytes) �޽�带 ȣ���Ѵ�.
*/
jstring javaNewString(JNIEnv *env, jbyteArray javaBytes)
{
	if (mid_newString == 0)
	{
		if (class_String == 0)
		{
			jclass cls = env->FindClass("java/lang/String");
			if (cls == 0)
				return 0;  /* ���� */
			class_String = (jclass)env->NewGlobalRef(cls);
			if (class_String == 0)
				return 0;  /* ���� */
		}
		mid_newString = (jmethodID)env->GetMethodID(class_String, "<init>", "([B)V");
		if (mid_newString == 0)
			return 0;
	}
	/* new String( javaBytes ); */
	return (jstring)env->NewObject(class_String, mid_newString, javaBytes);
}

/* ������ ���ڵ� `encoding'�� �ڹ� ����Ʈ �迭�� �ڹ� ��Ʈ������ ��ȯ.
* String Ŭ������ new String(byte[] bytes, String encoding)
* �޽�带 ȣ���Ѵ�.
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
				return 0;  /* ���� */
			class_String = (jclass)env->NewGlobalRef(cls);
			if (class_String == 0)
				return 0;  /* ���� */
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