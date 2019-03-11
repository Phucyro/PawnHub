#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QFileDialog>  //QDir



// #include "imageviewer.h" //Obsolete

int main(int argc, char *argv[])
{

  QApplication app(argc, argv);
  QGraphicsScene scene;
  QGraphicsView view(&scene);

  //Directory
  QDir directory = QDir("/home/kryptonx/Documents/School/OneDrive/2018-2019/PROJOANNEE/groupe2/Display/Advertising/");

  //List of Images
  QStringList images = directory.entryList(QStringList() << "*.jpg" << "*.JPG",QDir::Files);

  //Position in scene
  int xPos = 0 ;
  int yPos = 0 ;

  foreach(QString filename, images) {

    QPixmap pix = QPixmap(filename);
    QGraphicsPixmapItem *pm = scene.addPixmap(pix);
    pm->setPos(xPos,yPos);

    xPos+=500;
    yPos+=500;
  }

  //QPixmap pix = QPixmap("/home/kryptonx/Documents/School/OneDrive/2018-2019/PROJOANNEE/groupe2/Display/Advertising/index.jpg");
  //QGraphicsPixmapItem *pm2 = scene.addPixmap(pixx);
  //pm2->setPos(1000,1000);

  view.show();
  return app.exec();

}
