/**************************************************/
/*                  Homework 3                    */
/*           Alexandru Mihai Glontaru             */
/**************************************************/



#include <QCoreApplication>
#include "ukulele.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //first ukulele --> successfully created

    cout << "Create the first ukulele. \n";

    Body *body1 = new Body(5, 8, 7, 2300, "cherry");
    Neck *neck1 = new Neck(1300, 20, 5, "cherry");
    Top *top1 = new Top(400, 10, 6, "cherry");
    String *strings1[4];
    for(int i=0; i<4; i++){
        strings1[i] = new String(0.1*i, 40, "steel", 40);
    }

    Ukulele *ukulele1 = new Ukulele(top1, neck1, body1, strings1, 4000);

    if( ukulele1->checkUkulele() ){
        cout << "First ukulele was successfully created. Let's play it! \n";
        ukulele1->play();
    }
    else{
        cout << "It looks like something went wrong \n";
    }

    cout << "\n\n";

    //second ukulele --> unsuccessfully created

    cout << "Create the second ukulele. \n";

    Body *body2 = new Body(3, 7, 20, 1500, "pine");
    Neck *neck2 = new Neck(400, 10, 3, "cherry");
    Top *top2 = new Top(300, 5, 5, "oak");
    String *strings2[4];
    for(int i=0; i<4; i++){
        strings2[i] = new String(0.15*i, 35, "steel", 40);
    }
    Ukulele *ukulele2 = new Ukulele(top2, neck2, body2, strings2, 2500);

    if( ukulele2->checkUkulele() ){
        cout << "The second ukulele was successfully created. Let's play it! \n";
        ukulele2->play();
    }
    else{
        cout << "It looks like something went wrong \n";
    }

    cout << "\n\n";

    //third ukulele --> unsuccessfully created

    cout << "Create the third ukulele. \n";

    Body *body3 = new Body(3, 5, 7, 300, "cherry");
    Neck *neck3 = new Neck(600, 12, 4, "oak");
    Top *top3 = new Top(-1, -2, -1, "cherry");
    String *strings3[4];
    for(int i=0; i<4; i++){
        strings3[i] = new String(0.1*i, 20, "steel", 40);
    }

    Ukulele *ukulele3 = new Ukulele(top3, neck3, body3, strings3, 0);

    if( ukulele3->checkUkulele() ){
        cout << "The third ukulele was successfully created. Let's play it! \n";
        ukulele1->play();
    }
    else{
        cout << "It looks like something went wrong \n";
    }

    a.exit(0);
}
