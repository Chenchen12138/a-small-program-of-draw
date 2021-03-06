// C++大作业.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Circle.h"
#include "Ellipse_.h"
#include "Line.h"
#include "Rectangle_.h"
#include "Button.h"
#include "window.h"
void print(Shape *r)
{
	int k = 0;
	bool bDraw = false;
	mouse_msg msg = { 0 };
	for (; is_run(); delay_fps(60))
	{
		while (mousemsg())
		{
			msg = getmouse();
		}
		if (msg.is_down())
		{
			if (msg.is_left())
			{
				setwritemode(R2_XORPEN);
				r->setxy(msg.x, msg.y);
				r->InitialPoint(msg);
				r->draw();
				bDraw = true;
			}
			else if (msg.is_right())
			{
				if (bDraw)
				{
					r->draw();
					setwritemode(R2_COPYPEN);
					bDraw = false;
				}
			}
		}
		else if (msg.is_move())
		{
			if (bDraw)
			{
				r->draw();
				r->AdjustPoint(msg);
				r->draw();
			}
		}
		else if (msg.is_up())
		{
			if (bDraw)
			{
				setwritemode(R2_COPYPEN);
				r->AdjustPoint(msg);
				r->draw();
				bDraw = false;
			}
		}
			if ( kbhit() ) 
				k = getch();
			if (k == 'q') break;
	}
}
void fillprint(Shape *r)
{
	int k = 0;
	bool bDraw = false;
	mouse_msg msg = { 0 };
	for (; is_run(); delay_fps(60))
	{
		while (mousemsg())
		{
			msg = getmouse();
		}
		if (msg.is_down())
		{
			if (msg.is_left())
			{
				setwritemode(R2_XORPEN);
				r->setxy(msg.x, msg.y);
				r->InitialPoint(msg);
				r->draw();
				bDraw = true;
			}
			else if (msg.is_right())
			{
				if (bDraw)
				{
					r->draw();
					setwritemode(R2_COPYPEN);
					bDraw = false;
				}
			}
		}
		else if (msg.is_move())
		{
			if (bDraw)
			{
				r->draw();
				r->AdjustPoint(msg);
				r->draw();
			}
		}
		else if (msg.is_up())
		{
			if (bDraw)
			{
				setwritemode(R2_COPYPEN);
				r->AdjustPoint(msg);
				r->drawfill();
				bDraw = false;
			}
		}
		if (kbhit())
			k = getch();
		if (k == 'q') break;
	}
}
void Set()
{
	char str[100];
	int ch;
	//调用对话框函数
	inputbox_getline("请输入", "输入线宽", str, 100);
	ch = str[0]-48;
	setlinestyle(DOTTED_LINE, NULL, ch);                //设置线形和线宽
}
int main()
{
	Circle r;
	Rectangle_ b;
	Ellipse_ e;
	Line l;
	initgraph(800, 600);                             //初始化绘图环境
	window w(0, 0, 800, 600, "mywindows");
	w.show();
	setbkcolor_f(WHITE);
	int x = 2, y = 32;
	Button b1(x, y, x + 32, y + 32, "1.png");
	b1.show();
	y += 33;
	Button b2(x, y, x + 32, y + 32, "2.png");
	b2.show();
	y += 33;
	Button b3(x, y, x + 32, y + 32, "3.png");
	b3.show();
	y += 33;
	Button b4(x, y, x + 32, y + 32, "4.png");
	b4.show();
	setfillcolor(EGERGB(0xFF, 0x0, 0x80));           //设置填充颜色
	setfont(16, 0, "仿宋_GB2312");                   //设置字体
	setcolor(EGERGB(0xff, 0xa5, 0x0));               //设置边框颜色
	Set();
	mouse_msg msg = { 0 };
	for (; is_run(); delay_fps(60))	
	{
		while (mousemsg())
		{
			msg = getmouse();
		}
		if (msg.is_down())						// 有鼠标键按下
		{
			if (msg.is_left())					// 是鼠标左键,画实心
			{
				if ((2 < msg.x &&msg.x < 34) && (32 < msg.y &&msg.y < 64))
					fillprint(&r);

				else if ((2 < msg.x &&msg.x < 34) && (65 < msg.y &&msg.y < 97))
					fillprint(&b);

				else if ((2 < msg.x &&msg.x < 34) && (98 < msg.y &&msg.y < 130))
					fillprint(&e);
				else if ((2 < msg.x &&msg.x < 34) && (131 < msg.y &&msg.y < 163))
					fillprint(&l);
			}
			else if (msg.is_right())              // 是鼠标右键,画空心
			{
				if ((2 < msg.x &&msg.x < 34) && (32 < msg.y &&msg.y < 64))
					print(&r);

				else if ((2 < msg.x &&msg.x < 34) && (65 < msg.y &&msg.y < 97))
					print(&b);

				else if ((2 < msg.x &&msg.x < 34) && (98 < msg.y &&msg.y < 130))
					print(&e);
				else if ((2 < msg.x &&msg.x < 34) && (131 < msg.y &&msg.y < 163))
					print(&l);
			}
		}
	}		
	closegraph();                                    //关闭绘图环境
	return 0;
}