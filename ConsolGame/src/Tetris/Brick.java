package Tetris;

import Common.Console.Color;

import java.util.Scanner;

import Common.Console;

class Point 
{
	int x,y;
	public Point(int x,int y)
	{
		this.x = x;
		this.y = y;
	}
	public Point()
	{
		x=0;
		y=0;
	}
}

public class Brick 
{
	private char drawCh,deleteCh;
	Color FontColor,BackgroundColor;
	private Point[][] point;
	public Brick()
	{
		point = new Point[4][4];
		setBrick('■',' ');
		setColor(Color.WHITE,Color.BLACK);
	}
	public void setColor(Color FontColor,Color BackgroundColor)
	{
		this.FontColor = FontColor;
		this.BackgroundColor = BackgroundColor;
	}
	
	public void setBrick(char drawCh,char deleteCh)
	{
		this.drawCh = drawCh;
		this.deleteCh = deleteCh;
	}
	public void Draw(Boolean bShow, int rot,int x,int y)
	{
		Console.fontColor(FontColor);
		Console.backgroundColor(BackgroundColor);
		for(int i=0;i<4;i++)
		{
			int drawX = x + point[rot][i].x*2;
			int drawY = y + point[rot][i].y;
			Console.gotoXY( drawX,  drawY);
			System.out.print(bShow ? drawCh : deleteCh);
		}
	}
	public void setBrick(int rot, Point point1,Point point2,Point point3,Point point4)
	{
		Point[] pointArr= {point1,point2,point3,point4};
		for(int i=0;i<4;i++)
		{
			point[rot][i] = pointArr[i];
		}
	}
	
	public static void main(String[] args)
	{
		Console cls = new Console();
		Brick[] brick = new Brick[7];
		for(int i=0;i<7;i++)brick[i] = new Brick();
		// 사각형
		brick[0].setColor(Color.LIGHTYELLOW, Color.BLACK);
		brick[0].setBrick(0, new Point(0,0), new Point(1,0), new Point(0,1), new Point(1,1));
		brick[0].setBrick(1, new Point(0,0), new Point(1,0), new Point(0,1), new Point(1,1));
		brick[0].setBrick(2, new Point(0,0), new Point(1,0), new Point(0,1), new Point(1,1));
		brick[0].setBrick(3, new Point(0,0), new Point(1,0), new Point(0,1), new Point(1,1));
		
		// 일자
		brick[1].setColor(Color.LIGHTJADE, Color.BLACK);
		brick[1].setBrick(0, new Point(0,0), new Point(0,1), new Point(0,2), new Point(0,3));
		brick[1].setBrick(1, new Point(0,0), new Point(1,0), new Point(2,0), new Point(3,0));
		brick[1].setBrick(2, new Point(0,0), new Point(0,1), new Point(0,2), new Point(0,3));
		brick[1].setBrick(3, new Point(0,0), new Point(1,0), new Point(2,0), new Point(3,0));
		
		//�ݴ�����
		brick[2].setColor(Color.LIGHTBLUE, Color.BLACK);
		brick[2].setBrick(0, new Point(0,0), new Point(0,1), new Point(0,2), new Point(1,0));
		brick[2].setBrick(1, new Point(0,0), new Point(1,0), new Point(2,0), new Point(2,1));
		brick[2].setBrick(2, new Point(1,0), new Point(1,1), new Point(1,2), new Point(0,2));
		brick[2].setBrick(3, new Point(0,0), new Point(0,1), new Point(1,1), new Point(2,1));
		
		//�����
		brick[3].setColor(Color.LIGHTWHITE, Color.BLACK);
		brick[3].setBrick(0, new Point(1,0), new Point(1,1), new Point(1,2), new Point(0,0));
		brick[3].setBrick(1, new Point(0,1), new Point(1,1), new Point(2,1), new Point(2,0));
		brick[3].setBrick(2, new Point(0,0), new Point(0,1), new Point(0,2), new Point(1,2));
		brick[3].setBrick(3, new Point(0,0), new Point(1,0), new Point(2,0), new Point(0,1));
		
		// ��������
		brick[4].setColor(Color.LIGHTRED, Color.BLACK);
		brick[4].setBrick(0, new Point(0,0), new Point(0,1), new Point(1,1), new Point(1,2));
		brick[4].setBrick(1, new Point(1,0), new Point(2,0), new Point(0,1), new Point(1,1));
		brick[4].setBrick(2, new Point(0,0), new Point(0,1), new Point(1,1), new Point(1,2));
		brick[4].setBrick(3, new Point(1,0), new Point(2,0), new Point(0,1), new Point(1,1));
		
		// �޹���
		brick[5].setColor(Color.LIGHTGREEN, Color.BLACK);
		brick[5].setBrick(0, new Point(1,0), new Point(1,1), new Point(0,1), new Point(0,2));
		brick[5].setBrick(1, new Point(0,0), new Point(1,0), new Point(1,1), new Point(2,1));
		brick[5].setBrick(2, new Point(1,0), new Point(1,1), new Point(0,1), new Point(0,2));
		brick[5].setBrick(3, new Point(0,0), new Point(1,0), new Point(1,1), new Point(2,1));
		
		// T����
		brick[6].setBrick('※',' ');
		brick[6].setColor(Color.LIGHTREDDISH, Color.BLACK);
		brick[6].setBrick(0, new Point(0,1), new Point(1,1), new Point(2,1), new Point(1,0));
		brick[6].setBrick(1, new Point(0,0), new Point(0,1), new Point(0,2), new Point(1,1));
		brick[6].setBrick(2, new Point(0,0), new Point(1,0), new Point(2,0), new Point(1,1));
		brick[6].setBrick(3, new Point(1,0), new Point(1,1), new Point(1,2), new Point(0,1));
		
		for(int y=0;y<7;y++)
		{
			for(int x =0; x<4;x++) brick[y].Draw(true,x,1+(x*2*5),1+(y*5));
		}
		
		Scanner scan = new Scanner(System.in);
		scan.nextLine();
	}
}
