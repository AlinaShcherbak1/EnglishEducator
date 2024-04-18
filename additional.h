#pragma once

#ifndef ADDITIONAL_H
#define ADDITIONAL_H

#include <QString>

#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QGridLayout>
#include <QPushButton>
#include <QMediaPlayer>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QDebug>
#include <QFontDatabase>
#include <QScrollArea>
#include <QColor>
#include <QAudioOutput>
#include <QTextStream>
#include <QRect>
#include <QGuiApplication>
#include <QScreen>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDir>
#include <QFileInfo>

struct Card {
    QString word_eng;
    QString word_rus;
};

const std::vector <Card> cards_family = {
    {"mother", "мама"},
    {"father", "папа"},
    {"daughter", "дочка"},
    {"son", "сын"},
    {"sister", "сестра"},
    {"brother", "брат"},
    {"baby", "ребенок"},
    {"children", "дети"},
    {"parents", "родители"},
    {"grandfather", "дедушка"},
    {"grandmother", "бабушка"},
    {"twin", "близнец"},
    {"aunt", "тетя"},
    {"uncle", "дядя"},
    {"niece", "племянница"},
    {"nephew", "племянник"},
    {"boy", "мальчик"},
    {"girl", "девочка"},
    {"friend", "друг"},
    {"teacher", "учитель"},

};

const std::vector <Card> cards_school = {
    {"pen","ручка"},
    {"pencil","карандаш"},
    {"book","книга"},
    {"bag","рюкзак"},
    {"table","стол"},
    {"chair","кресто"},
    {"open","открыто"},
    {"close","закрыто"},
    {"play","играть"},
    {"game","игра"},
};

const std::vector <Card> cards_animal = {
    {"bird","птица"},
    { "cat","кот"},
    { "cow","корова"},
    {"duck","утка"},
    {"fish","рыба"},
    {"hamster","хомяк"},
    {"horse","лошадь"},
    {"lion","лев"},
    {"mouse","мышка"},
    {"parrot","попугай"},
    {"pig","свинья"},
    {"rabbit","заяц"},
    {"sheep","овечка"},
    {"turtle","черепаха"},
    { "wolf","волк"},

};

const QString styleSheet_dictionary = "QScrollBar:vertical { border: none;background: rgb(45, 45, 68);width: 14px;margin: 15px 0 15px 0;border-radius: 0px;}"
                                "QScrollBar::handle:vertical { background-color: rgb(80, 80, 122); min-height: 30px;border-radius: 7px;}"
                                "QScrollBar::handle:vertical:hover{	background-color: rgb(161, 161, 240); } "
                                "QScrollBar::handle:vertical:pressed {	background-color: rgb(93, 93, 150);}"
                                "QScrollBar::sub-line:vertical {border: none;background-color: rgb(59, 59, 90);height: 15px;border-top-left-radius: 7px;"
                                                                "border-top-right-radius: 7px;subcontrol-position: top; subcontrol-origin: margin;}"
                                "QScrollBar::sub-line:vertical:hover {background-color: rgb(161, 161, 240);}"
                                "QScrollBar::sub-line:vertical:pressed {background-color: rgb(185, 0, 92);}"
                                "QScrollBar::add-line:vertical {border: none;background-color: rgb(59, 59, 90);height: 15px; border-bottom-left-radius: 7px;border-bottom-right-radius: 7px;subcontrol-position: bottom;subcontrol-origin: margin;}"
                                "QScrollBar::add-line:vertical:hover {background-color: rgb(255, 0, 127); } QScrollBar::add-line:vertical:pressed {background-color: rgb(185, 0, 92); }"
                                "QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical { background: none;} "
                                "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background: none; }"


                                "QScrollBar:horizontal { border: none;background: rgb(45, 45, 68); height: 14px;margin:0 15px 0 15px;border-radius: 0px;}"
                                "QScrollBar::handle:horizontal {background-color: rgb(80, 80, 122); min-width: 30px;border-radius: 7px; }"
                                "QScrollBar::handle:horizontal:hover{background-color: rgb(161, 161, 240); } "
                                "QScrollBar::handle:horizontal:pressed {background-color: rgb(93, 93, 150);}"
                                "QScrollBar::sub-line:horizontal {border: none;background-color: rgb(59, 59, 90); width: 15px; border-bottom-left-radius: 7px;"
                                                    "border-top-left-radius: 7px;subcontrol-position: left; subcontrol-origin: margin;}"
                                "QScrollBar::sub-line:horizontal:hover {background-color: rgb(161, 161, 240);}"
                                "QScrollBar::sub-line:horizontal:pressed {background-color: rgb(185, 0, 92);}"
                                "QScrollBar::add-line:horizontal {border: none;background-color: rgb(59, 59, 90);width: 15px; border-bottom-right-radius: 7px;border-top-right-radius: 7px;subcontrol-position: right;subcontrol-origin: margin;}"
                                "QScrollBar::add-line:horizontal:hover {background-color: rgb(255, 0, 127); } QScrollBar::add-line:horizontal:pressed {background-color: rgb(185, 0, 92); }"
                                "QScrollBar::up-arrow:horizontal, QScrollBar::down-arrow:horizontal{background: none;}"
                                "QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal{background: none;} ";


const QString styleSheet_button_dictionary ="QPushButton{background-color: rgb(79, 79, 118);color: rgb(255, 235, 134);border-style: outset;border-width: 2px; border-radius: 10px; font: bold 20px;min-width: 10em; padding: 2px;}"
                 "QPushButton:pressed{background-color:  rgb(54, 54, 81);}""QPushButton:hover:!pressed{background-color: rgb(107, 107, 161);}";

const QString styleSheet_label_dictionary ="background-color: rgb(54, 54, 81);color: rgb(89, 255, 122); font: bold 20px;border-style: outset;border-right: 1px solid #006100;border-left: 1px solid #006100; line-height: 30px; border-top : 30px solid  rgb(54, 54, 81); border-bottom : 30px solid  rgb(54, 54, 81);font:bold; font-family:Book Antiqua; ";


#endif // ADDITIONAL_H
