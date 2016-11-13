#include "samplewidget.h"
#include <QDebug>
#include <QPainter>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QtGui>

QOpenGLBuffer vbo;
QOpenGLVertexArrayObject vao;
static float vertices[] = {0, 0.5,  0.5, -0.5, -0.5, -0.5};

SampleWidget::SampleWidget(QWidget *parent, Qt::WindowFlags f) : QOpenGLWidget(parent, f)
{

}

void SampleWidget::initializeGL()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClearColor(0, 0.5, 1, 1);
    auto context = QOpenGLContext::currentContext();
    qDebug() << QString("OpenGL Informations : GLES ? %0. Major version : %1. Minor version : %2")
                .arg
                (context->isOpenGLES())
                .arg
                (context->format().version().first)
                .arg(context->format().version().second);

    vao.create();
    vao.bind();

    vbo.create();
    vbo.bind();
    vbo.allocate(vertices, sizeof(vertices));

    f->glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), 0);
    f->glEnableVertexAttribArray(0);

    vao.release();
}
void SampleWidget::resizeGL(int w, int h)
{

}

void SampleWidget::paintGL()
{
    qDebug() << "Drawing widget";
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

    f->glClear(GL_COLOR_BUFFER_BIT);

    vao.bind();
    f->glDrawArrays(GL_TRIANGLES, 0, 3);


}

