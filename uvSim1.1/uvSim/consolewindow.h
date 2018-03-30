#ifndef CONSOLEWINDOW_H
#define CONSOLEWINDOW_H
#include <QPlainTextEdit>
#include <QObject>
#include <sstream>
#include <QEventLoop>
#include <string>








class ConsoleWindow:  public QPlainTextEdit
{
    Q_OBJECT

public:
    std::string consoleInput = " ";
    QString buf = "";

    // on tab out we set current window to false
    // sent


     ConsoleWindow(QWidget *parent=0);

     void setId(int & _id);
     void write(std::string text);
     void operator<< (std::string input);
     std::string read();
     std::string getOutPut();



private slots:
     void writeConsole();
    void readConsole();
     void clearStringBuff();



signals:
      void grabbedKey();
      void stopRead();
      void writeSignal();
      void readSignal();
 \


private:
    void moveCursorToEnd();
    void keyPressEvent(QKeyEvent *event);
    void focusOutEvent(QFocusEvent *event);
    void focusInEvent(QFocusEvent *event);
};

#endif // CONSOLEWINDOW_H
