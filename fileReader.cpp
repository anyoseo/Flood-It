#include "fileReader.h"
#include <fstream>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>

void FileReader::init(){
        QString filename="../scores.txt";
        QFile file(filename);
         if(file.open(QIODevice::ReadWrite|QIODevice::Text)){
            QTextStream stream(&file);
            for (unsigned row=2;row<=12;row++) {
                for (unsigned column=2;column<=12;column++) {
                    for(unsigned color=2;color<=5;color++){
                        stream<<row<<" "<<column<<" "<<color<<" "<<"0"<<endl;
                    }
                }
            }
        }
         file.close();
}

unsigned FileReader::highScore(unsigned row,unsigned column,unsigned nbColor){
    QString filename="../Flood-It/scores.txt";
    QFile file(filename);
    bool found=false;
    QStringList match;
    if(file.open(QIODevice::ReadWrite)){
        QTextStream in(&file);
        while (!found && !in.atEnd()) {
            match.clear();
            QString line = in.readLine();
            match=line.split(QRegExp("\\s+"));
            if(match.at(0).toUInt()==row && match.at(1).toUInt()==column && match.at(2).toUInt()==nbColor){
                found=true;
                file.close();
            }
        }
    }
    return match.at(3).toUInt();
}

void FileReader::writeFile(unsigned int row, unsigned int column, unsigned int nbColor,unsigned newScore){
    QString filename="../Flood-It/scores.txt";
    unsigned oldScore=highScore(row,column,nbColor);
    QString line=QString::number(row)+" "+QString::number(column)+" "+QString::number(nbColor)+" "+QString::number(oldScore)+"\n";
    QString newline=QString::number(row)+" "+QString::number(column)+" "+QString::number(nbColor)+" "+QString::number(newScore)+"\n";
    QFile data(filename);
        data.open(QIODevice::Text | QIODevice::ReadOnly);
        QString dataText = data.readAll();
        QRegularExpression re(line);
        dataText.replace(re, newline);
        QTextStream out(&data);
        out<<dataText;
        data.close();

        if(data.open(QFile::WriteOnly | QFile::Truncate)) {
                QTextStream out(&data);
                out << dataText;
        }
         data.close();
}
