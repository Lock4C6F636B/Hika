#include "hika.h"
#include <QApplication>
#include <QFile>
#include <QMediaPlayer>
#include <QAudioOutput>

QString readTextFile(QString path){
    QFile file(path);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        return in.readAll();
    }

    return "";
}


int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    //set styles
    QString css = readTextFile(":/styles/style.css");
    qDebug() << "CSS content:" << css;
    if (css.isEmpty()) {
        qWarning() << "Failed to load CSS file!";
    }
    a.setStyleSheet(css);

    HiKa w;
    w.show();

    return a.exec();
}
