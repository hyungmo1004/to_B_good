package dll;
import java.util.Scanner;

public class DLL 
{
	{
		System.loadLibrary("DLLname");
	}
	public native void printTest();
	public static void main(String[] args)
	{
		DLL dll = new DLL();
		
		dll.printTest();
	}

}
