#pragma once

#ifndef MAINMENU_H
#define MAINMENU_H

#include "dictionary.h"
#include "play.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();


private slots:

    void on_PLAY_clicked();
    void on_DICTIONARY_clicked();
    void Change_Data();
    void on_Read_clicked();
    void on_COMBO_BOX_currentIndexChanged(int index);
    void Setting_DB();

private:
    Ui::MainMenu *ui;
    Dictionary *dictionary;
    Play *play_widget;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    QString line;
    int id_combbox;

};
#endif // MAINMENU_H
