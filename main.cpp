#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>
#include <stdio.h>
#include <unistd.h>
#include <QCommandLineParser>
#include <QCommandLineOption>


int catchFile(QString targetDir)
{
    qDebug() << targetDir;
}

int encodeFile()
{
    qDebug() << "Encoding complete!";
}


int decodeFile()
{
    qDebug() << "Decoding complete!";
}

int catchKey(QString keyValue)
{
    qDebug() << keyValue;
}

int printInfo()
{
    qDebug() << "Programm was created in educational purposes. \nMade by AES, 2023";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCommandLineParser parser;
    QCommandLineOption takeFileOption(QStringList() << "f", "<directory>", "directory");
    QCommandLineOption doEncoding("c", "encodding file");
    QCommandLineOption doDecoding("d", "Decoding file");
    QCommandLineOption takeKey("k", "Taking key");
    QCommandLineOption info("h", "Printing info about author and programm");
    parser.addOption(takeFileOption);
    parser.addOption(doEncoding);
    parser.addOption(doDecoding);
    parser.addOption(takeKey);
    parser.addOption(info);

    parser.process(a);
    const QStringList args = parser.positionalArguments();
    bool f = parser.isSet(takeFileOption);
    bool c = parser.isSet(doEncoding);
    bool d = parser.isSet(doDecoding);
    bool k = parser.isSet(takeKey);
    bool h = parser.isSet(info);
    //QString targetDir = parser.value(takeFileOption);
    //QFileInfo info1("/home/alevser/Изображения/whale.jpg");
    //qDebug() << info1.suffix();
    //qDebug() << targetDir;

            if (f == true) {
                QString targetDir = parser.value(takeFileOption);
                catchFile(targetDir);

            }
            if (c == true) {
                encodeFile();

            }
            if (d == true) {
                decodeFile();

            }
            if (k == true) {
                QString keyValue = parser.value(takeKey);
                catchKey(keyValue);

            }
            if (h == true) {
                printInfo();
            }


    //return a.exec();
    return 0;
}
