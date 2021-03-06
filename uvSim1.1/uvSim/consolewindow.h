
#ifndef CONSOLEWINDOW_H
#define CONSOLEWINDOW_H
#include <QPlainTextEdit>
#include <QObject>
#include <sstream>
#include <QEventLoop>
#include <string>




// The ConsoleWindow class
// Written and debugged by: Abinadi Swapp
class ConsoleWindow:  public QPlainTextEdit
{
    Q_OBJECT

public:

    // This variable is changed and grabbed with the read and
    // write
    std::string consoleInput = " ";

    // This variable is used to log the console input to be returned
    QString buf = "";


    // This variable allows the window to close when we get the close window
    bool done = false;


     // The console window constructor
     // basically sets all the connections
     // with their signals and slots
     ConsoleWindow(QWidget *parent=0){
         connect(this, SIGNAL(writeSignal()), this, SLOT(writeConsole()),Qt::BlockingQueuedConnection);
         connect(this, SIGNAL(readSignal()), this, SLOT(readConsole()), Qt::BlockingQueuedConnection);
         connect(this, SIGNAL(grabbedKey()), this, SLOT(clearStringBuff()));
         connect(this, SIGNAL(closeSignal()), this, SLOT(closeConsole()));

          this->setReadOnly(true);
     }


     // The write method
     // basically sets the consoleinput variable
     // then emits the readsignal and the console
     // write the consoleinput variable to the string.
     // returns: nothing
     // inputs: text as a string.
     void write(std::string text){
         consoleInput = text;
         emit writeSignal();
      }

     // The read method
     // basically puts the window where it is in a keyboard input state.
     // returns: an empty string.
     // inputs: none
     std::string read(){
         //readWindow = true;
         emit readSignal();
         return consoleInput;
     }

     // The getOutPut method
     // bascally this grabes the consoleinput variable. This is used to
     // grab the keyboard input after the read function is called. Needs to
     // be used in tandom with an event loop that exits on enter key press.
     // returns: string
     // inputs: none
     std::string getOutPut(){
         return consoleInput;
     }

     // The setDone method
     // basically sets the done variable to true
     // so that the next time the enter key is pressed the
     // console will exit.
     // returns: nothing
     // inputs: none
     void setDone(){
         done = true;
     }



private slots:
     // The setDone slot
     // bascally writes whatever is in the consoleinput
     // variable to the console.
     // returns: nothing
     // inputs: none
     void writeConsole(){
         this->setReadOnly(false);
         QString input = QString::fromStdString (consoleInput);
         this->moveCursor (QTextCursor::End);
         this->insertPlainText (input);
         consoleInput = "";
     }

     // The readConsole slot
     // basically sets the console state to a keyboard input state
     // returns: nothing
     // inputs: none
     void readConsole(){
         auto start = this->cursor;

     }

     // The clearStringBuff slot
     // Resets the string input vector but also sets the consoleinput
     // string to the string. So it can be grabbed later
     // returns: nothing
     // inputs: none
     void clearStringBuff(){
         consoleInput = buf.toStdString();
         buf.clear();

        QString input = QString::fromStdString ("\n");
         this->moveCursor (QTextCursor::End);
         this->insertPlainText (input);
        this->setReadOnly(true);
     }


     // The clearStringBuff slot
     // Just closes the current console window
     // returns: nothing
     // inputs: none
     void closeConsole(){
         if(done)
         this->close();
     }



signals:
      // emited when the enter key is pressed
      void grabbedKey();

      // emited when the write function is called
      void writeSignal();

      // emited when the read function is called
      void readSignal();

      // emited when the enter key is pressed but doesn't do anything unless the
      // done variable is set to true.s
      void closeSignal();


private:

    // the keyPressEvent method
    // called evertime a key is pressed
    // this function handles all the keypresses
    // and emits the grabbedkey and closeConsole signals
    // on enter.
    void keyPressEvent(QKeyEvent *event)
    {
       if( event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
        {
           emit grabbedKey();
           emit closeConsole();
   }
        else{

            QPlainTextEdit::keyPressEvent( event );
             buf.push_back(event->text());
             emit closeConsole();
        }

    }
};

#endif // CONSOLEWINDOW_H
