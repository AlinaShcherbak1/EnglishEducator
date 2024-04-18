#include "mainmenu.h"
#include "ui_mainmenu.h"


int screenWidth;
int screenHeight;
MainMenu::MainMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainMenu)
{

    ui->setupUi(this);
    QString styleSheet = "::section {""background-color: rgb(79, 79, 118);" "color: rgb(89, 255, 122);""border-style: dashed solid;""font-size: 12px; }";
    ui->tableWidget->horizontalHeader()->setStyleSheet(styleSheet);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    screenWidth = screenGeometry.width();
    screenHeight = screenGeometry.height();

    ui->COMBO_BOX->move(screenWidth - 150, 50);
    ui->tableWidget->move(screenWidth - 252,150);
    ui->DICTIONARY->move(screenWidth/2 - 135,screenHeight/2  - 150);
    ui->PLAY->move(screenWidth/2 - 135,screenHeight/2 );

    dictionary = new Dictionary();// connect SLOT and SIGNAL
    connect(dictionary, &Dictionary::MainWindow, this, &MainMenu::show);
    play_widget = new Play();
    connect(play_widget, &Play::play_Window, this, &MainMenu::show);// подключаем к слоту запуска главного окна по кнопке во втором окне
    connect(play_widget, &Play::Pressed_Back_Button, this, &MainMenu::Change_Data);

    Setting_DB();
    id_combbox = 0;
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_PLAY_clicked()
{
    if(id_combbox>0){
    play_widget->showMaximized();
    this->close();}    // Закрываем основное окно}

    else{
        QMessageBox::warning(this, "Not Connection", "<html><b><font color='white'>Выберите пользователя</font></b></html>");

    }
}
void MainMenu::on_DICTIONARY_clicked()
{
    dictionary->showMaximized();
    this->close();    // Закрываем основное окно
}

void MainMenu::Change_Data()
{
    db.open();
    query = new QSqlQuery();
    query->prepare("UPDATE data SET grade = ? WHERE id_user = ?");
    query->bindValue(0,global_grade);
    query->bindValue(1,id_combbox);
    query->exec();
    db.close();
    on_Read_clicked();
    qDebug()<<"\n Change_Data ";
     qDebug()<<"global_grade = "<<global_grade;
    qDebug()<<"id_combbox = "<<id_combbox;
      qDebug()<<"\n ";
}

void MainMenu::on_Read_clicked()
{
    db.open();
    QSqlQuery Query_Get_Data(db);
    Query_Get_Data.prepare("SELECT * FROM data ORDER BY grade DESC;");
    if (Query_Get_Data.exec()){
        int RowNumber = 0;
        ui->tableWidget->setRowCount(Query_Get_Data.size());
        while(Query_Get_Data.next()){
        ui->tableWidget->setItem(RowNumber,0, new QTableWidgetItem(QString(Query_Get_Data.value("name").toString())));
        ui->tableWidget->setItem(RowNumber,1, new QTableWidgetItem(QString::number(Query_Get_Data.value("grade").toInt())));
        RowNumber=RowNumber+1;
        }
    }
     qDebug()<<"on_Read_clicked ";
    qDebug()<<" global_grade = "<<global_grade<<"/n \n";
    db.close();
}


void MainMenu::on_COMBO_BOX_currentIndexChanged(int index)
{
    id_combbox = index;
    db.open();
    QSqlQuery Query_Get_Grade(db);
    Query_Get_Grade.exec("SELECT grade FROM data WHERE id_user=?");
    Query_Get_Grade.bindValue(0,index);
    if (Query_Get_Grade.exec()){
        while(Query_Get_Grade.next()){
            global_grade = Query_Get_Grade.value("grade").toInt();
         qDebug()<<"on_COMBO_BOX_currentIndexChanged ";
             qDebug()<<"global_grade = "<<global_grade;
        }
    }
    db.close();
}

void MainMenu::Setting_DB()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("qt5");
    db.setUserName("root");
    db.setPassword("");
    if(db.open()){    qDebug()<<"correct connection"; }
    else {   QMessageBox::warning((this),"not Connection",db.lastError().text());}
    query = new QSqlQuery(db);
    query->exec("SELECT name FROM data");
    while(query->next()){
        ui->COMBO_BOX->addItem(query->value(0).toString());
    }
    on_Read_clicked();
}

