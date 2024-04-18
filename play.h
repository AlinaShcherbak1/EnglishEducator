#pragma once

#ifndef PLAY_H
#define PLAY_H
#include "additional.h"



extern int global_grade;
extern int my_x;
extern int my_y;
extern int screenWidth;
extern int screenHeight;
namespace Ui {
class Play;
}

class Play : public QWidget
{
    Q_OBJECT

public:
    explicit Play(QWidget *parent = nullptr);
    ~Play();
signals:
    void play_Window();// Сигнал для первого окна на открытие
    void Pressed_Back_Button();
private slots:
    void on_PLAY_MUSIC_clicked();
    void on_CHECK_clicked();
    void on_BACK_clicked();
    void on_SKIP_clicked();
    void handle_card_set(const std::vector <Card>& cards, std::vector <int>& indices, const QString& typed_word, const QString& typed_translate);


    void on_COMBO_BOX_currentIndexChanged(int index);

private:
    Ui::Play *ui;
    QMediaPlayer mQMediaPlayer;
    QAudioOutput *audioOutput;
};

#endif // PLAY_H
