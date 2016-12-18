package Common;

public class Console {
	private class Option 
	{ 
		public static final boolean BIT = false;
		//Bit is truest to 64bit use , Bit is false to 32bit use 
	}
	
	{
		if(Option.BIT) System.loadLibrary("javaConsoleX64");
		else System.loadLibrary("javaConsoleX86");
	}

	
	public static enum Color 
	{ 
		BLACK(0) , BLUE(1), GREEN(2), JADE(3),RED(4),REDDISH(5),YELLOW(6),
		WHITE(7),GRAY(8),LIGHTBLUE(9),LIGHTGREEN(10),LIGHTJADE(11),
		LIGHTRED(12),LIGHTREDDISH(13),LIGHTYELLOW(14),LIGHTWHITE(15);
	    
		private int value;
	    private Color(int value) {this.value = value;}
	    public int getValue() {return value; }
        public static Color getSizeType(int value) 
        {
            for (Color type : values()) {
                if (type.getValue() == value) {
                    return type;
                }
            }
            return Color.BLACK;
        }
	};
	public static enum CursorType
	{ 
		NOCURSOR(0), SOLIDCURSOR(1), NORMALCURSOR(2);
	    private int value;
	    private CursorType(int value) {this.value = value;}
	    public int getValue() {return value; }
        public static CursorType getSizeType(int value) 
        {
            for (CursorType type : values()) {
                if (type.getValue() == value) {
                    return type;
                }
            }
            return CursorType.NOCURSOR;
        }
	};
	
	public static native void gotoXY(int x,int y);
	public static native void cls();
	public static native void size(int x,int y);
	public static native int whereX();
	public static native int whereY();
	public static native void setTitle(String title);
	public static Color backgroundColor(Color color)
	{return Color.getSizeType(backgroundColor(color.getValue()));}
	
	public static Color fontColor(Color color)
	{return Color.getSizeType(fontColor(color.getValue()));}
	
	public static void setCursor(CursorType type) 
	{setCursor(type.getValue());}
	
	private static native int backgroundColor(int color);
	private static native int fontColor(int color);
	private static native void setCursor(int type);
}