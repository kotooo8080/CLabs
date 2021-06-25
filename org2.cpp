// org2.cpp: определяет точку входа для консольного приложения.
//

#include <dos.h>
#include <conio.h>
#include <string.h>

char* colorsRu[16] = { "—Ґа­л©", "‘Ё­Ё©", "‡Ґ«Ґ­л©", "‘Ё­Ґ-§Ґ«Ґ­л©", "Ља б­л©", "Ља б­®-бЁ­Ё©", "Љ®аЁз­Ґўл©", "‘ўҐв«®-бҐал©", "’Ґ¬­®-бҐал©", "џаЄ®-бЁ­Ё©", "џаЄ®-§Ґ«Ґ­Ґ­л©", "џаЄЁ© бЁ­Ґ-§Ґ«Ґ­л©", "џаЄ®-Єа б­л©", "џаЄЁ© Єа б­®-бЁ­Ё©", "†Ґ«вл©", "ЃҐ«л©" };

enum { ENTIRE, UP = 6, DOWN };

void scroll(int direction, char l_row, char l_col, char r_row, char r_col, char attr) {
	union REGS r;
	if (direction) {
		r.h.ah = direction;
		r.h.al = 3;
	}
	else {
		r.h.ah = 6;
		r.h.al = 3;
	}
	r.h.bh = attr;
	r.h.ch = l_row;
	r.h.cl = l_col;
	r.h.dh = r_row;
	r.h.dl = r_col;
	int86(0x10, &r, &r);
}

int main() 
{
	clrscr();
	int x = 15,
		y = 5,
		x1 = 65,
		y1 = 15;
	window(x, y, x1, y1);
	for (int t = 0; t < 16; t++) 
	{
		textbackground(t);
		for (int p = 0; p < 16; p++)
		{
			textcolor(p);
			cprintf("%d %s Sample text\r", t, colorsRu[p]);
			scroll(DOWN, y - 1, x - 1, y1 - 1, x1 - 1, (t * 16 | p));
			delay(400);
		}
	}
	getch();
	return (0);
}