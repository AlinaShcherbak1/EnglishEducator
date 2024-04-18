#pragma once

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "additional.h"

extern int grid_H;
namespace Ui {
class Dictionary;
}

class Dictionary : public QScrollArea
{
    Q_OBJECT

public:
    explicit Dictionary(QWidget *parent = nullptr);
    QVector<QString> image_direction;
    QVector<QString> direction_music;
    QVector<QString> button_name;
    QImage *image;
    ~Dictionary();
signals:
    void MainWindow();  // Сигнал для первого окна на открытие

public slots:
    void Play_Sound(QString str);
    void Button_backward();
    void Add_Card_Family(Dictionary *dict);
    QWidget* Create_Button();
    QWidget* Create_Label();
    void Populate_Grid( Dictionary* dict,QGridLayout* grid,int start_H, int end_H);

private:
    Ui::Dictionary *ui;
    QLabel *label;
    QMediaPlayer *q_media_player;
    QAudioOutput *audioOutput;


};

#endif // DICTIONARY_H
