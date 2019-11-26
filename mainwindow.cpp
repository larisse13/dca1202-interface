#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sculptor.h"
#include "figurageometrica.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "dialog.h"
#include <QColorDialog>
#include <QFileDialog>
#include <QSysInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sculptor = new Sculptor(30, 30, 30);


    ui->plotter_XY->paintMatrix( sculptor, 50 );

    ui->label_Red->setText("Vermelho: ");
    ui->label_Green->setText("Verde: ");
    ui->label_Blue->setText("Azul: ");
    ui->label_Alpha->setText("Opacidade: ");

    connect(ui->horizontalSliderRed,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(redSliderChangeColor(int)));
    connect(ui->horizontalSliderGreen,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(greenSliderChangeColor(int)));
    connect(ui->horizontalSliderBlue,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(blueSliderChangeColor(int)));
    connect(ui->horizontalSliderAlpha,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(alphaSliderChangeColor(int)));




    connect(ui->plotter_XY,
            SIGNAL(clickXY(int, int)),
            this,
            SLOT(drawSculptorXY(int, int)));


    connect(ui->plotter_XY,
            SIGNAL(moveXY(int, int)),
            this,
            SLOT(drawMouseVoxelXY(int, int)));
    connect(ui->actionputvoxel,
            SIGNAL(triggered(bool)),
            this,
            SLOT(selectPutVoxel()));
    connect(ui->actioncutvoxel,
            SIGNAL(triggered(bool)),
            this,
            SLOT(selectCutVoxel()));
    connect(ui->actionputbox,
            SIGNAL(triggered(bool)),
            this,
            SLOT(selectPutBox()));
    connect(ui->actioncutbox,
            SIGNAL(triggered(bool)),
            this,
            SLOT(selectCutBox()));
    connect(ui->actionputsphere,
            SIGNAL(triggered(bool)),
            this,
            SLOT(selectPutSphere()));
    connect(ui->actioncutsphere,
            SIGNAL(triggered(bool)),
            this,
            SLOT(selectCutSphere()));
    connect(ui->actionputellipsoid,
            SIGNAL(triggered(bool)),
            this,
            SLOT(selectPutEllipsoid()));
    connect(ui->actioncutellipsoid,
            SIGNAL(triggered(bool)),
            this,
            SLOT(selectCutEllipsoid()));
    connect(ui->actionNew_3D_Canvas,
            SIGNAL(triggered(bool)),
            this,
            SLOT(setDimSculptor()));

    connect(ui->actionwriteOFF,
            SIGNAL(triggered(bool)),
            this,
            SLOT(writeOFF()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setDimSculptor()
{
    DialogNewCanvas dialog;

    if(dialog.exec() == QDialog::Accepted){
        int nx, ny, nz;
        nx = dialog.getDimX();
        ny = dialog.getDimY();
        nz = dialog.getDimZ();

        sculptor = new Sculptor(nx, ny, nz);
        drawPlane();
    }
}

void MainWindow::drawPlane()
{
    ui->plotter_XY->paintMatrix(sculptor, 0);


}

void MainWindow::drawSculptorXY(int x0, int y0)
{
    int z0 = 0;
    drawFigure(x0,y0,z0,brush);
}


void MainWindow::drawFigure(int x0, int y0, int z0, int brush)
{
    vector<GeometricFigure*> figs;

    if(brush == putvoxel){
        figs.push_back(new PutVoxel(x0,y0,z0,r,g,b,a));
    }
    if(brush == cutvoxel){
        figs.push_back(new CutVoxel(x0,y0,z0));
    }
    if(brush == putbox){
        figs.push_back(new PutBox(x0-((ui->lineEditRectangleSizeX->text()).toInt()/2),
                                  x0+((ui->lineEditRectangleSizeX->text()).toInt()/2),
                                  y0-((ui->lineEditRectangleSizeY->text()).toInt()/2),
                                  y0+((ui->lineEditRectangleSizeY->text()).toInt()/2),
                                  z0-((ui->lineEditRectangleSizeZ->text()).toInt()/2),
                                  z0+((ui->lineEditRectangleSizeZ->text()).toInt()/2),
                                  r,g,b,a));
    }
    if(brush == cutbox){
        figs.push_back(new CutBox(x0-((ui->lineEditRectangleSizeX->text()).toInt()/2),
                                  x0+((ui->lineEditRectangleSizeX->text()).toInt()/2),
                                  y0-((ui->lineEditRectangleSizeY->text()).toInt()/2),
                                  y0+((ui->lineEditRectangleSizeY->text()).toInt()/2),
                                  z0-((ui->lineEditRectangleSizeZ->text()).toInt()/2),
                                  z0+((ui->lineEditRectangleSizeZ->text()).toInt()/2)));
    }
    if(brush == putsphere){
        figs.push_back(new PutSphere(x0, y0, z0, (ui->lineEditSphereRadius->text()).toInt(), r, g, b, a));
    }
    if(brush == cutsphere){
        figs.push_back(new CutSphere(x0, y0, z0, (ui->lineEditSphereRadius->text()).toInt()));
    }
    if(brush == putellipsoid){
        figs.push_back(new PutEllipsoid(x0,
                                        y0,
                                        z0,
                                        (ui->lineEditElipsoidRadiusX->text()).toInt(),
                                        (ui->lineEditElipsoidRadiusY->text()).toInt(),
                                        (ui->lineEditElipsoidRadiusZ->text()).toInt(),
                                        r,g,b,a));
    }
    if(brush == cutellipsoid){
        figs.push_back(new CutEllipsoid(x0, y0, z0,
                                        (ui->lineEditElipsoidRadiusX->text()).toInt(),
                                        (ui->lineEditElipsoidRadiusY->text()).toInt(),
                                        (ui->lineEditElipsoidRadiusZ->text()).toInt()));
    }
    for(int i = 0; i< int(figs.size()); i++){
        figs[i]->draw(*sculptor);
    }
    this->drawPlane();
}




void MainWindow::selectPutVoxel()
{
    if(ui->actionputvoxel->isChecked()){
        brush = putvoxel;
    }
    else {
        brush = -1;
    }

    uncheckBrushButtons(brush);

}
void MainWindow::selectCutVoxel()
{
    if(ui->actioncutvoxel->isChecked()){
        brush = cutvoxel;
    }
    else {
        brush = -1;
    }
    uncheckBrushButtons(brush);
}
void MainWindow::selectPutBox()
{
    if(ui->actionputbox->isChecked()){
        brush = putbox;
    }
    else {
        brush = -1;
    }
    uncheckBrushButtons(brush);
}
void MainWindow::selectCutBox()
{
    if(ui->actioncutbox->isChecked()){
        brush = cutbox;
    }
    else {
        brush = -1;
    }
    uncheckBrushButtons(brush);
}
void MainWindow::selectPutSphere()
{
    if(ui->actionputsphere->isChecked()){
        brush = putsphere;
    }
    else {
        brush = -1;
    }
    uncheckBrushButtons(brush);
}
void MainWindow::selectCutSphere()
{
    if(ui->actioncutsphere->isChecked()){
        brush = cutsphere;
    }
    else {
        brush = -1;
    }
    uncheckBrushButtons(brush);
}
void MainWindow::selectPutEllipsoid()
{
    if(ui->actionputellipsoid->isChecked()){
        brush = putellipsoid;
    }
    else {
        brush = -1;
    }
    uncheckBrushButtons(brush);
}
void MainWindow::selectCutEllipsoid()
{
    if(ui->actioncutellipsoid->isChecked()){
        brush = cutellipsoid;
    }
    else {
        brush = -1;
    }
    uncheckBrushButtons(brush);
}

void MainWindow::uncheckBrushButtons(int brush)
{
    if(brush!=putvoxel){
        ui->actionputvoxel->setChecked(false);
    }
    if(brush!=cutvoxel){
        ui->actioncutvoxel->setChecked(false);
    }
    if(brush!=putbox){
        ui->actionputbox->setChecked(false);
    }
    if(brush!=cutbox){
        ui->actioncutbox->setChecked(false);
    }
    if(brush!=putsphere){
        ui->actionputsphere->setChecked(false);
    }
    if(brush!=cutsphere){
        ui->actioncutsphere->setChecked(false);
    }
    if(brush!=putellipsoid){
        ui->actionputellipsoid->setChecked(false);
    }
    if(brush!=cutellipsoid){
        ui->actioncutellipsoid->setChecked(false);
    }
}

void MainWindow::mudaCor()
{
    QColorDialog d;

    QColor previousColor(int(r*255), int(g*255), int(b*255));
    d.setCurrentColor(previousColor);
    d.exec();

    QColor color;
    color= d.selectedColor();
    if(!color.isValid()){
        color = previousColor;
    }

    r = color.red();
    g = color.green();
    b = color.blue();
    a = color.alpha();


    r=r/255.0;
    g=g/255.0;
    b=b/255.0;
    a=a/255.0;


    ui->horizontalSliderRed->setValue(r*100);
    ui->horizontalSliderGreen->setValue(g*100);
    ui->horizontalSliderBlue->setValue(b*100);
    ui->horizontalSliderAlpha->setValue(a*100);
}

void MainWindow::redSliderChangeColor(int slider)
{
    float aux = slider/100.0;
    r = aux;

}

void MainWindow::greenSliderChangeColor(int slider)
{
    float aux = slider/100.00;
    g = aux;

}

void MainWindow::blueSliderChangeColor(int slider)
{
    float aux = slider/100.0;
    b = aux;

}

void MainWindow::alphaSliderChangeColor(int slider)
{
    float aux = slider/100.0;
    a = aux;
}

void MainWindow::writeOFF()
{
    QString fileName;

    fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                   "./untitled.off",
                                   tr("OFF (*.off)"));
}
