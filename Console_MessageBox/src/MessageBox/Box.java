package MessageBox;

import Common.Console;



public class Box {
	final static int BUTTON_OK = 1;
	final static int BUTTON_CANCEL = 2;
	
	int button = 1;
	
	int size_x = 10;
	int size_y = 10;
	int pos_x = 0;
	int pos_y = 0;
	
	int str_color = 15;
	int str_bcolor = 0;
	
	int edge_color = 15;
	int edge_bcolor = 0;
	
	String caption ="";
	String Message ="";
	
	
	public void print(String caption,String msg, int mode)
	{

	}
	
	//테두리 출력 / 최소 중앙으로부터 +3
	public void printEdge()
	{
		
		
	}
	
	//제목 개별 설정
	public void setCaption(String cap)
	{
		caption = cap;
	}
	
	//메세지 내용 설정
	public void setMessage(String msg)
	{
		Message = msg;
	}

	//테두리 모냥 설정
	public void setEdgeForm(String str_form )
	{

		
	}
	
	//테두리 색
	public void setEdgeColor(int num)
	{
		edge_color = num;
	}
	
	//테두리 배경색
	public void setEdgebColor(int num)
	{
		edge_bcolor = num;
	}
	
	//크기 설정  최소 10,10
	public void setSize(int x,int y)
	{
		if(x < 10)
			size_x = 10;
		else
			size_x = x;
		
		if(y < 10)
			size_y = 10;
		else
			size_y = y;		
	}
	
	//위치 설정
	public void setPosition(int x,int y)
	{
		pos_x = x;
		pos_y = y;
	}
	
	public void setStringColor(int num)
	{
		str_color = num;
		str_color = num;
	}
	
	public void setButton(int count)
	{
		this.button=1;
			///테스트다 테스트 !! 
	}
}
