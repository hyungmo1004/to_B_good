package Test;
import java.util.Scanner;
import Common.Console;
import Common.Console.Color;

public class test {

	public static void main(String[] args) {
		Console con = new Console();
		Scanner scan = new Scanner(System.in);
		String strTemp;
		
		//안녕하세요.
		System.out.println("자바 콘솔 테스트합니다.");
		
		System.out.println("gotoXY(10,10) Test Text = dddd");
		Console.gotoXY(10, 10);
		System.out.println("dddd");
		System.out.println("다음 테스트를 위해서 엔터를 눌러주세요.");
		
		scan.nextLine();
		
		Console.cls();
		
		System.out.println("setTitle");
		do
		{
			System.out.print("변경 타이틀 명(종료시 999입력): ");
			strTemp = scan.nextLine();
			Console.setTitle(strTemp);
		}while(!strTemp.equals("999"));
		
		Console.cls();
		
		System.out.println("폰트색상을 테스트합니다.");
		
		for(int i=1;i<16;i++)
		{
			Console.fontColor(Color.getSizeType(i));
			System.out.println("테스트 폰트" + i );
		}
		Console.fontColor(Color.getSizeType(0));
		
		System.out.println();
		System.out.println("폰트 배경을 테스트합니다.");
		for(int i=1;i<16;i++)
		{
			Console.backgroundColor(Color.getSizeType(i));
			System.out.println("폰트 배경테스트" + i );
		}
		
		System.out.println();
		scan.nextLine();
		Console.cls();
	}

}
