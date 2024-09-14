#include <graphics.h>
#include <iostream>
class Bars
{
    int color, height;
public:
    static int starty, startx,width;
    inline void getAtt(int colour, int ht) // to initialize the Bars attributes
    {
        color = colour;        height = starty-ht;
    }
    void draw(int x1)
    {
        setfillstyle(color, color);
        bar(x1, starty, x1 + 30,height);
    }
    friend void BubbleSort(Bars[], int);
};
void BUBBLE(int left,int top,int right,int bottom,int COLOR)
{
    char bubble[] = "BUBBLE";
    setcolor(COLOR);
    outtextxy(left+10, top-20,bubble);
            
    //vertical lines
    line(left,bottom,left,top);
    line(right,bottom,right,top);
    //horizontal lines
    line(left,bottom,right,bottom);
    line(left,top,right,top);
}
int Bars::starty;    int Bars::startx;    int Bars::width;
void BubbleSort(Bars b[], int size)// sorting and drawing until the end
{
    int total = size;
    char step[]="step: 0";     char pass[] = "pass: 0";
    char exp[4][80] = {{"Now observe the BUBBLE (yellow box),we just focus on Bars inside this BUBBLE "},
                       {"If the 1st Bars is taller than 2nd, we swap them else the BUBBLE moves forward"},
                       {"And this is how bubble carries Barss with it until a taller Bars is not found  "},
                       {"When no smaller Bars is found,BUBBLE restarts its journey from first Bars again"}};
    int y=0;
    for(int i=0;i<4;i++)
    {
        outtextxy(0,y,exp[i]);      
        delay(1000);     
        y+=15;
    }
    delay(7000);
    for (int i = 0; i < total - 1; i++)
    {
        delay(1000);
        pass[6]='0';
        for (int j = 0; j < total - 1 - i; j++)
        {
            int maxHeight = std::min(b[j].height,b[j+1].height);
            if (b[j].height < b[j + 1].height)
            {
                //not reverse sorting, more the height shorter the Bars    
                //if height is smaller i.e.if Bars is taller, then exchange properties with next Bars 
                BUBBLE(Bars::startx+(j-1)*40-5,maxHeight-5,Bars::startx+j*40+5+Bars::width,Bars::starty+5,0);
                //clearing previous rectangle
                BUBBLE(Bars::startx+j*40-5,maxHeight-5,Bars::startx+(j+1)*40+5+Bars::width,Bars::starty+5,14);
                //drawing rectangle before swapping
                std::swap(b[j], b[j + 1]);
                
            }
            delay(500);cleardevice();
            //drawing after swapping
            BUBBLE(Bars::startx+j*40-5,maxHeight-5,Bars::startx+(j+1)*40+5+Bars::width,Bars::starty+5,14);
            pass[6]++;
            
            outtext(pass);
            outtextxy(0,40,step); 
            
           for (int k = 0; k < 8; k++)// drawing the modified graph
                b[k].draw(Bars::startx + k * 40);
            delay(500);
        }
        step[6]++;
    }
}
int main()
{
    int gd = DETECT, gm, start = 200, size = 8;
    initgraph(&gd, &gm, NULL);
    char PROBLEM[] ="PROBLEM : Arrange them in ascending order of their height";         
    outtext(PROBLEM);
    char SOLUTION[] ="SOLUTION : Use Bubble sort ";  outtextxy(0, 20, SOLUTION);
    
    // initializing values for all boxes and drawing for 1st time
    Bars ::starty = getmaxy() - 5;    Bars ::startx = getmaxx()/2-160;    Bars::width=30;
    Bars b[size];   
    int values[] = {400, 100, 200, 250, 300, 50, 60, 150};
    for (int i = 0; i < size; i++)
    {
        b[i].getAtt(i + 1, values[i]);
        b[i].draw(Bars::startx + i * 40);
    }
    delay(4000);   
    BubbleSort(b, size); // actual sorting
    char sorted[] = "The graph is now sorted";  outtextxy(250,0,sorted);
    char Thanks[] = "Thanks for watching !!!";  outtextxy(250, 25, Thanks);
    restorecrtmode();    getchar();
    closegraph();
    return 0;
}
