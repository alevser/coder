#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>
#include <stdio.h>
#include <unistd.h>
#include <QCommandLineParser>
#include <QCommandLineOption>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("Coder");
    QCoreApplication::setApplicationVersion("1.0");
    QCommandLineParser parser;
    QCommandLineOption takeFileOption("f", "Processed file");
    QCommandLineOption doCoding("c", "Codding file");
    QCommandLineOption doDecoding("d", "Decoding file");
    QCommandLineOption takeKey("k", "Taking file");
    QCommandLineOption printInfo("h", "Printing info about author and programm");
    parser.addOption(takeFileOption);
    parser.addOption(doCoding);
    parser.addOption(doDecoding);
    parser.addOption(takeKey);
    parser.addOption(printInfo);

/*    int c;

    while ((c = getopt( argc, argv, "f:dck:h")) != EOF)
    {
        switch (c) {
        case 'f':
            qDebug() << "case f";
            break;
        case 'c':
            qDebug() << "case c";
            break;
        case 'd':
            qDebug() << "case d";
            break;
        case 'k':
            qDebug() << "case k";
            break;
        case 'h':
            qDebug() << "Programm was created in educational purposes. \nMade by AES, 2023";
            break;
        default:
            qDebug() << "default";
            break;
        }
    }
    */


    parser.process(a);
    bool catchFile = parser.isSet(takeFileOption);
    bool callCoder = parser.isSet(doCoding);
    bool callDecoder = parser.isSet(doDecoding);
    bool catchKey = parser.isSet(takeKey);
    bool showInfo = parser.isSet(printInfo);
    QFileInfo info1("/home/alevser/Изображения/whale.jpg");
    qDebug() << info1.suffix();

            if (catchFile == true) {
                qDebug() << "case f";
            }
            if (callCoder == true) {
                qDebug() << "case c";
            }
            if (callDecoder == true) {
                qDebug() << "case d";
            }
            if (catchKey == true) {
                qDebug() << "case k";
            }
            if (showInfo == true) {
                qDebug() << "Programm was created in educational purposes. \nMade by AES, 2023";
            }

    //return a.exec();
    return 0;
}
