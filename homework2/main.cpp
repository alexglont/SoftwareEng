/*******************************************/
/*        Alexandru Mihai Glontaru         */
/*   Software Engineering - Spring 2017    */
/*******************************************/


#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Input a string: ";

    //read the string to be printed
    QTextStream in(stdin);
    QString myString = in.readLine();


    //create and open the file where we print
    QFile outFile("Output.txt");
    if ( outFile.open(QIODevice::ReadWrite) ) {

        QTextStream stream( &outFile );
        stream << myString << endl; //print string to file
    }

    // flush and close the file
    outFile.flush();
    outFile.close();

    a.exit(0);

}
