#include "dictionary.h"
#include "ui_dictionary.h"

int pos_I = 0;
int pos_M = 0;
int grid_H = 0;
int grid_W = 0;

void Add_New_Card(Dictionary *dict, const QString& word_eng, const QString& word_rus)
{
    dict->direction_music << "../../../Qt/Education/audio/" + word_eng + ".mp3";
    dict->image_direction << "../../../Qt/Education/image/" + word_eng + ".png";
    dict->button_name << word_eng + " - " + word_rus;
}


void Dictionary::Play_Sound(QString str)
{
    q_media_player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    q_media_player->setAudioOutput(audioOutput);
    q_media_player->setSource(QUrl::fromLocalFile(str));
    audioOutput->setVolume(50);
    q_media_player->play();
}

void Dictionary::Button_backward()
{
    close();
    emit MainWindow(); // вызываем сигнал на открытие главного окна
}

void Dictionary::Add_Card_Family(Dictionary *dict)
{
    for (const auto& cards_family : cards_family) {
        Add_New_Card(this, cards_family.word_eng, cards_family.word_rus);
    }
    for (const auto& cards_school : cards_school) {
        Add_New_Card(this, cards_school.word_eng, cards_school.word_rus);
    }
    for (const auto& cards_animal : cards_animal) {
        Add_New_Card(this, cards_animal.word_eng, cards_animal.word_rus);
    }
}

QWidget* Dictionary::Create_Button()
{
    QPushButton* btn = new QPushButton(button_name[pos_M]);
    QString sound_path = direction_music[pos_M];
    QObject::connect(btn,  &QPushButton::clicked, [this, sound_path](){
        Play_Sound(sound_path); });
    btn->setFixedSize(80, 35);
    btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn->setStyleSheet(styleSheet_button_dictionary);
    return btn;
}

QWidget* Dictionary::Create_Label() {
    QLabel* label = new QLabel(this);
    QImage* image = new QImage(image_direction[pos_I]);
    QImage scaled_image = image->scaled(150,150,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    label->show();
    label->setPixmap(QPixmap::fromImage(scaled_image,Qt::AutoColor));
    label->setAlignment(Qt::AlignCenter);
    return label;
}

int count = 0;

void Dictionary::Populate_Grid(Dictionary* dict, QGridLayout* grid,int start_H, int end_H)
{
    int *H = &grid_H;
    for (int H = start_H + 1 ; H <= start_H + end_H; ++H) {
        for (int grid_W = 1; grid_W <= 5; ++grid_W) {
            if(count % 2 == 0){
                if (H % 2 != 0) {  grid->addWidget(Create_Label(), H, grid_W);pos_I++; }
                else {  grid->addWidget(Create_Button(), H, grid_W, Qt::AlignCenter); pos_M++; }
             }
            else{
                if( H % 2 == 0 ){  grid->addWidget(Create_Label(), H, grid_W);pos_I++; }
                else{  grid->addWidget(Create_Button(), H, grid_W, Qt::AlignCenter);pos_M++; }
            }
            grid_H = H;
        }
    }
    count++;
}


void Add_Label_And_Populate_Grid(Dictionary* dict, QGridLayout *grid, int &grid_H, const QString &label_text, const std::vector<Card> &card_vector)
{
    QLabel *label = new QLabel(label_text);
    label->setStyleSheet(styleSheet_label_dictionary);
    grid->addWidget(label, grid_H, 1, Qt::AlignCenter);
    dict->Populate_Grid(dict,grid, grid_H, (card_vector.size() / 5) * 2);
    ++grid_H;
}

Dictionary::Dictionary(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::Dictionary),q_media_player(new QMediaPlayer),
    audioOutput(new QAudioOutput)
{
    //ui->setupUi(this);
    setWidgetResizable(true);
    this->setStyleSheet(styleSheet_dictionary);

    QWidget *Widget = new QWidget;
    Widget->setStyleSheet("background-color: rgb(54, 54, 81);");
    QGridLayout *grid = new QGridLayout;
    Widget->setLayout(grid);
    setWidget(Widget);
    grid->setSpacing(15);
    QPushButton *backward = new QPushButton("BACK");
    grid->addWidget(backward, 0, 0, Qt::AlignLeft,QSizePolicy::Minimum);

    connect(backward,&QPushButton::clicked,this, &Dictionary::Button_backward);
    backward->setFixedSize(120, 40);
    backward->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    backward->setStyleSheet(
                " QPushButton{background-color: rgb(79, 79, 118);border-style: dotted;color: rgb(89, 255, 122);font-size: 20px;font:bold; font-family:Book Antiqua; }"
                "QPushButton:pressed{background-color:  rgb(39, 39, 59);}""QPushButton:hover:!pressed{background-color: rgb(107, 107, 161);}");//a_CityNovaTitulRgLt

    Add_Card_Family(this);
    Add_Label_And_Populate_Grid(this,grid,grid_H,"FAMILY",cards_family);
    Add_Label_And_Populate_Grid(this,grid,grid_H,"SCHOOL",cards_school);
    Add_Label_And_Populate_Grid(this,grid,grid_H,"ANIMAL",cards_animal);
}


Dictionary::~Dictionary()
{
    delete ui;
}


