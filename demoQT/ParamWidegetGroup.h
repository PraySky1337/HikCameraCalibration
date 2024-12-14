#pragma once
#include <QWidget>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QMutex>

class ParamterGroupWidget : public QWidget {
    Q_OBJECT
public:
    ParamterGroupWidget(int startIndex, int endIndex, QWidget* parent = nullptr) 
    : QWidget(parent) 
    {
        QVBoxLayout* layout = new QVBoxLayout(this);
        for (int i = startIndex; i )
    } 

};