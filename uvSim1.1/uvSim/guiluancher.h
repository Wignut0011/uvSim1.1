#ifndef GUILUANCHER_H
#define GUILUANCHER_H
#include <QObject>
#include <QWidget>
#include "consolewindow.h"
class gui_launcher : public QObject
{
public:
  ConsoleWindow *w;
  // other components
  //..
public:
  virtual bool event( QEvent *ev )
  {
    if( ev->type() == QEvent::User )
    {
      w = new ConsoleWindow;
      w->show();
      return true;
    }
    return false;
  }
};
#endif // GUILUANCHER_H
