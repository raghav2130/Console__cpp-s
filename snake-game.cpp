#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
using namespace std;
#define fio ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                         \
    cout.tie(nullptr);

#define ll long long
#define ull unsigned long long 
#define ndl "\n"
#define Z size()
 
//  inputcrap
#define in1(a)                  cin >> a;
#define in2(a, b)               cin >> a >> b;
#define in3(a, b, c)            cin >> a >> b >> c;
#define in4(a, b, c, d)         cin >> a >> b >> c >> d;
#define in5(a, b, c, d, e)      cin >> a >> b >> c >> d >> e;
#define inchk(inpt , n) ff(i,0,n) cout<<inpt[i]; cout<<ndl;
 
// Loopyverse
#define arr_fill(arr, n)    ff(i, 0, n)  cin>>arr[i];
#define arr_sprint(arr, n)   ff(i, 0, n) cout << arr[i];
#define arr_bprint(arr, n)   ff(i, 0, n) cout << arr[i]<<" ";
#define arr_nprint(arr, n)   ff(i, 0, n) cout << arr[i]<<ndl;
#define w(t) while (t--)
#define wm(t) while (t)
#define ff(i, a, b) for (ll i = a; i < b; i++)
#define ffe(i, a, b) for (ll i = a; i <= b; i++)
#define fb(i, a, b) for (ll i = a; i > b; i--)
#define fbe(i, a, b) for (ll i = a; i >= b; i--)
 
#define solve() work()
#define test_case() \
    int t = 1;      \
    cin >> t;      \
    w(t) solve();

/* ------------- code starts here --------- */ 

bool gameOver=0;
const int width=20;
const int height=20;
int x,y,fruitx,fruity, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void setup(){
    gameOver=false;
    dir = STOP;
    x = width/2;
    y = height/2;
    fruitx = rand() % width;
    fruity = rand() % height;
}
void draw(){
    system("cls");
    ff(i,0,width)   // for top line 
        cout<<"#";
    cout<<endl;

    ff(i,0,height){
        ff(j,0,width){
            if (j == 0 || j == width-1)
                cout<<"#";
            if (i == y and j == x)
                cout<<"O";
            else if (i == fruity and j == fruitx)
                cout<<"F";
            else
                cout<<" ";


        }
        cout<<ndl;
    }

    ff(i,0,width)   // for bottom line 
        cout<<"#";
    cout<<endl;
}
void input(){
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'x':
            gameOver = 1;
            break;
        default:
            break;
        }
    }
}
void logic(){
    switch (dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y++;
            break;
        case DOWN :
            y--;
            break;
        default:
            break;
    }
}
int main ()
{
    fio;
    setup();
    wm(!gameOver)
    {
        draw();
        input();
        logic();
    }

}
