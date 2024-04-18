#include "play.h"
#include "ui_play.h"
#include <algorithm>


QString word;
int num;
int global_grade;
int random_index ;
std::vector<int> indices_animal(cards_animal.size());
std::vector<int> indices_family(cards_family.size());
std::vector<int> indices_school(cards_school.size());


Play::Play(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Play)
{

    ui->setupUi(this);
    srand(time(NULL));

    std::iota(indices_animal.begin(), indices_animal.end(), 0);
    std::iota(indices_school.begin(), indices_school.end(), 0);  // Заполнить вектор индексов от 0 до cards_family.size()-1
    std::iota(indices_family.begin(), indices_family.end(), 0);
    audioOutput = new QAudioOutput;
    mQMediaPlayer.setAudioOutput(audioOutput);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    ui->groupBox->move(screenGeometry.width()/2 -250,screenGeometry.height()/2 - 180);
    ui->COMBO_BOX->addItem("animal");
    ui->COMBO_BOX->addItem("family");
    ui->COMBO_BOX->addItem("school");
}

Play::~Play()
{
    delete ui;
}

void Play::on_PLAY_MUSIC_clicked()
{
mQMediaPlayer.play();
}

void Play::on_BACK_clicked()
{
    close();
    emit play_Window(); // И вызываем сигнал на открытие главного окна
    emit  Pressed_Back_Button();
}


int COMBO_BOX_chose;

void Play::on_COMBO_BOX_currentIndexChanged(int index)
{
    COMBO_BOX_chose=index;
    if(COMBO_BOX_chose==1 && indices_animal.size()!=0){
        random_index = indices_animal[rand() %indices_animal.size()];
        word = "../../../Qt/Education/audio/" +cards_animal[random_index].word_eng +".mp3";
        qDebug()<<word;
    }
    if(COMBO_BOX_chose==2 && indices_family.size()!=0){
        random_index = indices_family[rand() %indices_family.size()];
        word = "../../../Qt/Education/audio/" +cards_family[random_index].word_eng +".mp3";
    }
    if(COMBO_BOX_chose==3 && indices_school.size()!=0 ){
        random_index = indices_school[rand() %indices_school.size()];
        word="../../../Qt/Education/audio/" +cards_school[random_index].word_eng +".mp3";
    }
    mQMediaPlayer.setSource(QUrl::fromLocalFile(word));
}





void Play::handle_card_set(const std::vector <Card>& cards, std::vector <int>& indices, const QString& typed_word, const QString& typed_translate)
{
    if (indices.size() == 0) {
        ui->label->setText("It is all!!!");
        return;
    }
    if(typed_word==cards[random_index].word_eng || typed_translate==cards[random_index].word_rus){
        global_grade+=1;
        ui->label->setText("Good!");
        ui->label->setStyleSheet("QLabel {  color : rgb(255, 219, 13);}");
        ui->label->setGeometry(365, 105, 100, 50);
        QPropertyAnimation *animation = new QPropertyAnimation(ui->label, "color");
        animation->setDuration(1500);
        animation->setStartValue(QColor(13,255,243));
        animation->setEndValue(QColor(0, 255, 99));
        animation->start();
        indices.erase(std::remove(indices.begin(), indices.end(), random_index), indices.end());
        if(indices.size() !=0){
            random_index = indices[rand() %indices.size()];  // Сгенерировать случайный индекс из вектора индексов
            word="C:/Users/Alina/Documents/family_mp3/" +cards[random_index].word_eng +".mp3";
            mQMediaPlayer.setSource(QUrl::fromLocalFile(word));
        }
        else if(indices.size()==0){ ui->label->setText("It is all!!!");}
        ui->typed_word->setText("");
        ui->typed_translate->setText("");
    }

    else if(typed_word!=cards[random_index].word_eng || typed_translate==cards[random_index].word_rus){
        global_grade-=1;
        ui->label->setText("Wrong!");
        ui->label->setStyleSheet("QLabel {  color : rgb(255, 76, 76); }");
        ui->label->setGeometry(365, 100, 100, 50);
        ui->label->setStyleSheet("QLabel {  color : rgb(255, 76, 76); position:absolute; left:400px; top:400px; }");

        QSequentialAnimationGroup* group = new QSequentialAnimationGroup;
        QPropertyAnimation* animation1 = new QPropertyAnimation(ui->label, "geometry");
        animation1->setDuration(100);
        animation1->setStartValue(QRect(365, 105, 100, 50));
        animation1->setEndValue(QRect(400, 105, 100, 50));
        group->addAnimation(animation1);

        QPropertyAnimation* animation2 = new QPropertyAnimation(ui->label, "geometry");
        animation2->setDuration(100);
        animation2->setStartValue(QRect(400, 105, 100, 50));
        animation2->setEndValue(QRect(365, 105, 100, 50));
        group->addAnimation(animation2);
        group->start();
    }
}
void Play::on_CHECK_clicked()
{
    QString typed_word = ui->typed_word->text();
    QString typed_translate = ui->typed_translate->text();
    switch ( COMBO_BOX_chose) {
    case 1:
        handle_card_set(cards_animal, indices_animal, typed_word,typed_translate);
        break;
    case 2:
        handle_card_set(cards_family, indices_family, typed_word,typed_translate);
        break;
    case 3:
        handle_card_set(cards_school, indices_school, typed_word,typed_translate);
        break;
    default:
        break;
    }

}




void Play::on_SKIP_clicked()
{
    global_grade-=1;
    switch ( COMBO_BOX_chose) {
    case 1:
        if(indices_animal.size()==1){ ui->label->setText("It is all!!!"); return;}
        else if(indices_animal.size()>1){
            indices_animal.erase(std::remove(indices_animal.begin(), indices_animal.end(), random_index), indices_animal.end());
            random_index = indices_animal[rand() %indices_animal.size()];  // Сгенерировать случайный индекс из вектора индексов
            word="../../../Qt/Education/audio/" +cards_animal[random_index].word_eng +".mp3";
                qDebug()<<"word = "<<word;

        }
        break;
    case 2:
        if(indices_family.size()==1){ ui->label->setText("It is all!!!"); return;}
        else if(indices_family.size()>1){
            indices_family.erase(std::remove(indices_family.begin(), indices_family.end(), random_index), indices_family.end());
            random_index = indices_family[rand() %indices_family.size()];
            word="../../../Qt/Education/audio/" +cards_family[random_index].word_eng +".mp3";
              qDebug()<<"word = "<<word;
           }
        break;
    case 3:
        if(indices_school.size()==1){ ui->label->setText("It is all!!!");return;}
        else if(indices_school.size()>1){
            indices_school.erase(std::remove(indices_school.begin(), indices_school.end(), random_index), indices_school.end());
            random_index = indices_school[rand() %indices_school.size()];
            word="../../../Qt/Education/audio/" +cards_school[random_index].word_eng +".mp3";
                qDebug()<<"word = "<<word;
        }
        break;
    }
    mQMediaPlayer.setSource(QUrl::fromLocalFile(word));
}
