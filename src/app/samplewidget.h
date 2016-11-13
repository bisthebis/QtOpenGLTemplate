#ifndef SAMPLEWIDGET_H
#define SAMPLEWIDGET_H

#include <QOpenGLWidget>

class SampleWidget : public QOpenGLWidget
{
public:
    SampleWidget(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

protected:
    virtual void paintGL() Q_DECL_OVERRIDE;
    virtual void initializeGL() Q_DECL_OVERRIDE;
    virtual void resizeGL(int w, int h) Q_DECL_OVERRIDE;
};

#endif // SAMPLEWIDGET_H
