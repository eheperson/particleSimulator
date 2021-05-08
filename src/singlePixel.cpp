#include<iostream>
#include<math.h>
#include<time.h>
/**/
#include<Screen/Screen.h>
/**/
/**/
/**/
/**/
using namespace std;
using namespace particleScreen;
/**/
int main(int argc, char* argv[]){
/**/
/**/
    Screen screen;
/**/
    if( screen.init() == false){
        cout << " Error at initializing SDL !!" << endl;
    };
/**/
    screen.setPixel( 400, 300, 255, 255, 255);
/**/
/**/
    screen.update();
    cout<<"ehe"<<endl;
    system("Pause");
    screen.close();
    return 0;

}