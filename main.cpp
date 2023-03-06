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
    QCommandLineOption takeFileOption(QStringList() << "f", "<directory>", "directory");
    QCommandLineOption doCoding("c", "Codding file");
    QCommandLineOption doDecoding("d", "Decoding file");
    QCommandLineOption takeKey("k", "Taking key");
    QCommandLineOption printInfo("h", "Printing info about author and programm");
    parser.addOption(takeFileOption);
    parser.addOption(doCoding);
    parser.addOption(doDecoding);
    parser.addOption(takeKey);
    parser.addOption(printInfo);

    parser.process(a);
    const QStringList args = parser.positionalArguments();
    bool catchFile = parser.isSet(takeFileOption);
    bool callCoder = parser.isSet(doCoding);
    bool callDecoder = parser.isSet(doDecoding);
    bool catchKey = parser.isSet(takeKey);
    bool showInfo = parser.isSet(printInfo);
    //QString targetDir = parser.value(takeFileOption);
    QFileInfo info1("/home/alevser/Изображения/whale.jpg");
    qDebug() << info1.suffix();
    //qDebug() << targetDir;

            if (catchFile == true) {
                QString targetDir = parser.value(takeFileOption);
                qDebug() << targetDir;
                qDebug() << "case f";
            }
            if (callCoder == true) {
                qDebug() << "case c";
            }
            if (callDecoder == true) {
                qDebug() << "case d";
            }
            if (catchKey == true) {
                QString keyValue = parser.value(takeKey);
                qDebug() << keyValue;
                qDebug() << "case k";
            }
            if (showInfo == true) {
                qDebug() << "Programm was created in educational purposes. \nMade by AES, 2023";
            }
            //asdasdasdasdasd

    //return a.exec();
    return 0;
}
