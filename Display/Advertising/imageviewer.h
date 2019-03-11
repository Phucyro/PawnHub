#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QMainWindow>
#include <QImage>
#ifndef QT_NO_PRINTER
#include <QPrinter>
#endif

class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;

class ImageViewer : public QMainWindow
{
  Q_OBJECT

private:
  void setImage(const QImage &newImage);
  QImage image;
  QLabel *imageLabel;
  double scaleFactor;

public:
  ImageViewer();
  bool loadFile(const QString &);
};
#endif
