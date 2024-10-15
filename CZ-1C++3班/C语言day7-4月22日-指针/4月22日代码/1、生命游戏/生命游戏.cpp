#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

int map[200][200] = {0};
int maptmp[200][200] = {0};
char str[160000];

void init()
{
	map[1][2] = 1;
	map[2][3] = 1;
	map[3][1] = 1;
	map[3][2] = 1;
	map[3][3] = 1;
}

void initline()
{
	map[1][2] = 1;
	map[2][2] = 1;
	map[3][2] = 1;
}

void initgun()
{
	map[6][1] = 1;
	map[6][2] = 1;
	map[7][1] = 1;
	map[7][2] = 1;
	map[4][10] = 1;
	map[5][10] = 1;
	map[6][9] = 1;
	map[7][9] = 1;
	map[8][9] = 1;
	map[9][10] = 1;
	map[10][10] = 1;
	map[5][8] = 1;
	map[6][7] = 1;
	map[7][6] = 1;
	map[8][7] = 1;
	map[9][8] = 1;
	
	map[2][24] = 1; 
	map[3][24] = 1; 
	map[7][24] = 1; 
	map[8][24] = 1;
	map[2][25] = 1; 
	map[3][25] = 1; 
	map[7][25] = 1; 
	map[8][25] = 1; 
	map[3][26] = 1; 
	map[4][26] = 1; 
	map[5][26] = 1; 
	map[6][26] = 1; 
	map[7][26] = 1; 
	map[4][27] = 1; 
	map[6][27] = 1; 
	map[4][29] = 1; 
	map[5][29] = 1; 
	map[6][29] = 1; 
	map[4][35] = 1; 
	map[5][35] = 1; 
	map[4][36] = 1; 
	map[5][36] = 1;
	
	map[7][15] = 1;
	map[7][16] = 1;
	map[7][17] = 1;
	map[9][17] = 1;
	map[10][17] = 1;
	map[11][17] = 1;
	map[9][20] = 1;
	map[9][21] = 1;
	map[10][21] = 1;
	map[11][20] = 1;
	map[12][19] = 1;
	map[12][20] = 1;
}

int num(int x, int y)
{
	int count = 0;
	for(int i = x - 1; i <= x + 1; i++)
	{
		for(int j = y - 1; j <= y + 1; j++)
		{
			count += map[i][j];
		}
	}
	count -= map[x][y];
	return count;
}


int main()
{
	SetConsoleTitleA("ÉúÃüÓÎÏ·");
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD w = {0, 0};
    CONSOLE_CURSOR_INFO cursorInfo = {1, FALSE};
    SetConsoleCursorInfo(hOut, &cursorInfo);
    initgun();
    while(1)
    {
	    int i, j, tmp;
	    for(i = 1; i <= 199; i++)
	    {
	    	for(j = 1; j <= 199; j++)
	    	{
	    		tmp = num(i, j);
	    		if(tmp == 3)
	    		{
	    			maptmp[i][j] = 1;
				}
				else if(tmp == 2)
				{
					maptmp[i][j] = map[i][j];
				}
				else
				{
					maptmp[i][j] = 0;
				}
			}
		} 
		
		for(i = 1; i <= 199; i++)
	    {
	    	for(j = 1; j <= 199; j++)
	    	{
	    		map[i][j] = maptmp[i][j];
			}
		} 
		
		SetConsoleCursorPosition(hOut, w);
		//SetCursorPos(w.X, w.Y);
		SetConsoleCursorInfo(hOut, &cursorInfo);
		for(i = 1; i <= 150; i++)
		{
			for(j = 1; j <= 150; j++)
	    	{
	    		if(map[i][j])
	    		{
	    			strcat(str, "¡ö");
				}
				else
				{
					strcat(str, "  ");
				}
			}
			strcat(str, "\n");
		} 
		puts(str);
		str[0] = 0;
	}
	return 0;
}
